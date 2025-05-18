// Necessary header files for input output functions
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//prompt for template file
int templateSelect() { //function to prompt user for template file
    int templatenumber;
    cout << "Select a template: " << endl; // Type a number and press enter
    cin >> templatenumber; // Get user input from the keyboard
    cout << "Your number is: " + to_string(templatenumber) + " ";
    return templatenumber;
}

// function to read the template file from \resources folder and return the content as a string
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
    }
    cout << webpage << endl;
    file.close();
    
    return webpage;
}




// function to write the changes to a new file

// prompt user for changes they wish to make to the file

int main() {
    // call the function to prompt user for template file
    int templatenumber = templateSelect();
    // check if the template file is correct for the user
    int confirmation = 0;

    while (confirmation != 1) {
        cout << "is this the template file you want to use ?" << endl;
        cin >> confirmation;
        if (confirmation == 1) {
            cout << "You have selected the template file " + to_string(templatenumber) << endl;
        } else {
            cout << "Please select a different template file" << endl;
            templatenumber = templateSelect();
        }
    }
    // call the function to read the template file and return the content as a string
    filereader(templatenumber);
}
// read the template file and return the content as a string

// create a new file with the changes made by the user