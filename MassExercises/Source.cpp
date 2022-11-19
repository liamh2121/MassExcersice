#include <iostream>
#include <string.h>
#include <regex>
#include <fstream>
#include <sstream>

using namespace std;

const string* FILENAME = new string("People.xml"); //Filename/path

bool readFile(string& fileContent);
void showDetails(string& fileContent);

int main() {

#ifdef _DEBUG //check for memory leak
	//_CrtSetBreakAlloc(93);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	string fileContent;
	if (readFile(fileContent))  //if the xml file is successfully read then print details
		showDetails(fileContent);
	else //else give error message and end program
		cout << "File Not Found";

	delete FILENAME;
	return 0;
}

bool readFile(string& fileContent) {
	ifstream rFile(FILENAME->c_str());
	
	if (rFile) { //if the file is read then put it into a string stream to load into the fileContent string
		ostringstream ss;
		ss << rFile.rdbuf();
		fileContent = ss.str();
		return true;
	}
	else //else reuturn function failed
		return false;
}

void showDetails(string& fileContent) {
	regex regex("[A-Za-z]+(?=<)"); //regular expreasion gets all characters between <> </> tags
	smatch matched;
	regex_iterator<string::iterator> it(fileContent.begin(), fileContent.end(), regex);
	regex_iterator<string::iterator> end;
	int personCounter = 0;
	regex_search(fileContent, matched, regex);

	cout << "Peoples Names:" << endl;

	while (it != end) { //while not at the end of the iterator print the current value and increment iterator
		cout << it->str() << " ";
		it++;
		personCounter++;
		if (personCounter % 2 == 0) //if first and last name have been printed then start a new line
			cout << endl;
	}

	cout << "There are " << personCounter / 2 << " people found" << endl;
}