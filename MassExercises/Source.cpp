#include <iostream>
#include <string.h>
#include <regex>
#include <fstream>
#include <sstream>

using namespace std;

const string FILENAME = "People.xml";

bool readFile(string& fileContent);
void showDetails(string& fileContent);

int main() {

#ifdef _DEBUG //check for memory leak
	//_CrtSetBreakAlloc(93);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	string fileContent;
	if (readFile(fileContent))
		showDetails(fileContent);
	else
		cout << "File Not Found";

	return 0;
}

bool readFile(string& fileContent) {
	ifstream rFile(FILENAME.c_str());
	
	if (rFile) {
		ostringstream ss;
		ss << rFile.rdbuf();
		fileContent = ss.str();
		return true;
	}
	else
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

	while (it != end) {
		cout << it->str() << " ";
		it++;
		personCounter++;
		if (personCounter % 2 == 0)
			cout << endl;
	}

	cout << "There are " << personCounter / 2 << " people found" << endl;
}