/* 
 * Logan Welsh
 * 2325215
 * lwelsh@chapman.edu
 * CPSC-350-01
 * Assignment 3: Syntax Checker
 * main.cpp
 * Main syntax checker program.
 */

#include "GenStack.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

	// Open and closed delimiters must have the same indices in the "open" and "close" arrays.
	const string delim_open = "({[";
	const string delim_close = ")}]";
	const string defaultFname = "example.txt";	// Default file to use when no argument is given.


	// GET NAME OF FILE TO CHECK
	string filename = "";
	if(argc == 1) {
		cout << "No input file given. Using \"" + defaultFname + "\" by default." << endl;
		filename = defaultFname;
	}
	else if(argc > 2) {
		cout << "Too many arguments given." << endl;
		return -1;
	}
	else {
		filename = argv[1];
	}
	
	
	// OPEN THE INPUT FILE STREAM
	ifstream inFile;
	inFile.open(filename);
	if(!inFile.is_open()) {
		cout << "Could not open \"" + filename + "\". Exiting." << endl;
		return 1;
	}
	
	
	// CHECK SYNTAX IN THE FILE
	// Array indices are stored on the stack to make it easier to compare open delimiters to their closed counterparts.
	GenStack<int> *dStk = new GenStack<int>();
	string line = "";
	int lineNum = 0;
	bool errorFound = false;
	
	// For each "line" in the file...
	while( !inFile.eof() && !errorFound ) {
		lineNum++;
		getline(inFile,line);
		
		// ...for each character in that line...
		for(int i = 0; i < line.size(); ++i) {
			// ...check if the character is an open delimiter.
			size_t inDelimOpen = delim_open.find(line[i]);
			if( inDelimOpen != string::npos ) {
				dStk->push(inDelimOpen);	// If so, keep track of that character.
			}
			
			// If it's not an open delimiter...
			else {
				// ...check if it's a closed delimiter.
				size_t inDelimClose = delim_close.find(line[i]);
				if(inDelimClose != string::npos) {
					
					// If this is the "close" we are looking for...
					if(dStk->peek() == inDelimClose) {
						// ...then we can forget this "open" and move to the previously found one.
						try {
							dStk->pop();
						}
						catch(int e) {
							if(e == -1) {
								cout << "Exception: Tried to pop from an empty stack. Exiting.";
								errorFound = true;
								break;
							}
						}
					}
					
					// If a different "close" was found, then we have encountered a syntax error.
					else {
						cout << "Line " << lineNum << ": ";
						cout << "expected " << delim_close[dStk->peek()];
						cout << " and found " << line[i];
						cout << endl;
						errorFound = true;
					}
				}
				
			}
		}
	}
	
	
	// CHECK FOR LEFTOVER "OPEN" DELIMITERS
	if( !dStk->isEmpty() && !errorFound ) {
		cout << "Reached end of file: missing " << delim_close[dStk->peek()] << endl;
		errorFound = true;
	}
	
	
	// CLEANUP
	inFile.close();
	delete dStk;
	
	return 0;
}