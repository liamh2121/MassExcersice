#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

bool readXML(string*);

int main() {
	string regex = "[<].?[A-Za-z]+[>]\K[^<][A_Za-z]+"; //regular expreasion getting all the data from an xml file


	return 0;
}

bool readXML(string* fileName) {

	istream rFile;
	if (rFile.open(fileName)) {
		return true;
	}
	else
		return false;
}