// Necessary header files for input output functions
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

//prompt for template file
int templateSelect() { //function to prompt user for template file
    int templatenumber;
    while (true) {
        cout << "Select a template: " << endl; // Type a number and press enter
        cin >> templatenumber; // Get user input from the keyboard
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        cout << "Your number is: " + to_string(templatenumber) + " ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return templatenumber;
    }
}

// function to read the template file from current directory and return the content as a string
string filereader(int x) {
    // variable to store the content of the file
    string webpage; 
    // variable to store the name of the file
    string filename = ("template" + to_string(x) + ".html");
    // open the file in read mode
    ifstream file(filename);
    // check if the file is open
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            // read each line of the file and append it to the webpage variable
            webpage += line + "\n";
        }
    } else {
        cout << "Unable to open file or does not exist" << endl;
        return "error";
    }
    cout << webpage << endl;
    file.close();
    
    return webpage;
}

// Struct to store student details
struct StudentDetails {
    string name;
    string id;
    string image;
};

// function to prompt user for student details
// and return the details as a struct
StudentDetails studentdetailsinput() {
    StudentDetails details;
    cout << "Enter the image path of student photo: " << endl;
    cin >> details.image;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter the name of the student: " << endl;
    cin >> details.name;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter the ID of the student: " << endl;
    cin >> details.id;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return details;
}
// function to write the changes to the webpage variable
string filewriter(string webpage, string x, string y, string z) {
    size_t img_pos = webpage.find("src=\"\"");
    if (img_pos != string::npos) {
        webpage.replace(img_pos, 7, "src=\"" + x + "\"");
    }

    size_t name_pos = webpage.find("Student_Name");
    if (name_pos != string::npos) {
        webpage.replace(name_pos, 12, y);
    }

    size_t id_pos = webpage.find("Student_Id");
    if (id_pos != string::npos) {
        webpage.replace(id_pos, 10, z);
    }

    return webpage;
}

string webpagecreator(string webpage) {
    ofstream file("webpage.html");
    file << webpage;
    file.close();
    return webpage;
}

// function to write the changes to a new file

// prompt user for changes they wish to make to the file

int main() {
    int confirmation = 0;
    while (confirmation != 1) {
        // call the function to prompt user for template file
        int templatenumber = templateSelect();

        // check if the template file is correct for the user
        confirmation = 0; // just assign, don't redeclare

        while (confirmation != 1) {
            cout << "is this the template file you want to use, press 1 for yes" << endl;
            cin >> confirmation;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number." << endl;
                confirmation = 0;
                continue;
            }
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (confirmation == 1) {
                cout << "You have selected the template file " + to_string(templatenumber) << endl;
            } else {
                cout << "Please select a different template file" << endl;
                templatenumber = templateSelect();
            }
        }

        // reads the template file and stores it in the webpage variable
        string webpage = filereader(templatenumber);

        // asks for the student details and stores it in the details struct
        StudentDetails details = studentdetailsinput();

        // write the changes to the webpage variable
        webpage = filewriter(webpage, details.name, details.id, details.image);

        // print the changes made to the webpage variable
        cout << webpage << endl;
        cout << "Do you want to save the changes made to the file, press 1 for yes" << endl;
        cin >> confirmation;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            confirmation = 0;
            continue;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (confirmation == 1) {
            // write the changes to a new file
            webpagecreator(webpage);

            // inform the user that the file has been created successfully
            cout << "The file has been created successfully" << endl;
            cout << "The file is named webpage.html" << endl;
            cout << "The file is located in the same directory as this program" << endl;
            cout << "Please check the file for the changes made" << endl;
        }
    }
}