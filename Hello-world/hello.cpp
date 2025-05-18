// Necessary header files for input output functions
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//prompt for template file
int templateSelect(){ //function to prompt user for template file
int templatenumber;
cout << "Select a template: " << endl; // Type a number and press enter
cin >> templatenumber; // Get user input from the keyboard
cout << "Your number is: " + to_string(templatenumber) + " ";
return templatenumber;
	}

// function to read the template file from \resources folder and return the content as a string

string templateRead(int templatenumber) {
	string webpage;
	if (templatenumber == 1) {
		ifstream file("resources/template1.txt");
	}
	for (getline(file, webpage)) {
		cout << webpage << endl; // print the content of the file to the console
	}

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
		}
		else {
			cout << "Please select a different template file" << endl;
			templatenumber = templateSelect();
		}
	}
}
 webpage = templateRead(templatenumber); // read the template file and return the content as a string





// create a new file with the changes made by the user