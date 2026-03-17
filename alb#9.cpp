// this programm reads names from the file line by line and tells you in alphabetical order and how many names are there
//Daniel Suarez
//3/17/2026
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//this programm reads names from the file line by line and tells you in alphabetical order and how many names are there
int main() {
	string filename, name, first, last;
	int count = 0;
	cout << "welcome, this programm reads names from the file line by line and tells you in alphabetical order and how many names are there" << endl;
	cout << "Enter filename: ";
	cin >> filename;

	ifstream inputFile(filename);

	// Check if the file exists
	if (!inputFile) {
		cout << "File does not exist." << endl;
	}
	else {
		// Reads names one by one
		while (inputFile >> name) {
			if (count == 0) {
				// First name found becomes both first and last initially
				first = name;
				last = name;
			}
			else {
				if (name < first) first = name;
				if (name > last) last = name;
			}
			count++;
		}
		inputFile.close();

		// Output results
		if (count > 0) {
			cout << "First: " << first << endl;
			cout << "Last: " << last << endl;
			cout << "Total: " << count << endl;
		}
		else {
			cout << "File is empty." << endl;
		}
	}

	return 0;
}