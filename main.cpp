#include <iostream>
#include <string>
#include <fstream>
#include "CaesarCipher.h"

using namespace std;

void saveToFile(const string& filename, const string& data) {
	ofstream outFile(filename, ios::app);
	if (outFile) {
		outFile << data << "\n";
		outFile.close();
		cout << "Data saved to " << filename << "\n";
	}
	else {
		cout << "Failed to open file for writing." << "\n";
	}
}


int main()
{
	string filename;
	cout << "Enter name file : ";
	getline(cin, filename);

	int step;
	cout << "Enter the shift step  : ";
	cin >> step;
	cin.ignore();

	string inputText;
	cout << "Enter your text : ";
	getline(cin, inputText);

	CaesarCipher caesCipher(inputText, step);
	
	string encryptsText =  caesCipher.encrypts();
	string decodesText = caesCipher.decodes();

	saveToFile(filename, encryptsText);
	saveToFile(filename, decodesText);

}