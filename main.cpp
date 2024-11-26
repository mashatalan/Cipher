#include <iostream>
#include <string>
#include <fstream>
#include "CaesarCipher.h"
#include "XorCipher.h"

using namespace std;

void saveToFile(const string& filename, const string& data) {
	ofstream outFile(filename);
	if (outFile) {
		outFile << data << "\n";
		outFile.close();
		cout << "Data saved to " << filename << "\n";
	}
	else {
		cout << "Failed to open file for writing." << "\n";
	}
}


string loadFromFile(const string& filename) {
	ifstream inFile(filename);
	string content;
	if (inFile) {
		getline(inFile, content);
		inFile.close();
		cout << "Data loaded from " << filename << "\n";
	}
	else {
		cout << "Failed to open file for reading." << "\n";
	}
	return content;
}


int main()
{
	int step;
	char key;
	string inputText;
	int choice;


	do
	{
		cout << "\n\n Menu \n\n";
		cout << "1.Encrypt using the Caesar cipher\n";
		cout << "2.Decodes using the Caesar cipher\n";
		cout << "3.Encrypt using the Xor cipher\n";
		cout << "4.Decodes using the Xor cipher\n";
		cout << "0.Exit.\n";

		
		cout << "Make your choice : ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			cout << "\nEnter the shift step: ";
			cin >> step;
			cin.ignore();
			cout << "Enter your text: ";
			getline(cin, inputText);

			CaesarCipher caesarCipher(inputText, step);
			string encryptedText = caesarCipher.encrypts();
			cout << "Encrypted text: " << encryptedText << "\n";
			saveToFile("caesarCiper.txt", encryptedText);
			break;
		}
		case 2:
		{
			cout << "\nEnter the shift step: ";
			cin >> step;
			cin.ignore();

			inputText = loadFromFile("caesarCiper.txt");
			if (inputText.empty()) {
				cout << "No text to decrypt.\n";
				break;
			}

			CaesarCipher caesarCipher(inputText, step);
			string decryptedText = caesarCipher.decodes();
			cout << "Decrypted text: " << decryptedText << "\n";
			break;
		}

		case 3:
		{
			cout << "Enter key: ";
			cin >> key;
			cin.ignore();

			cout << "Enter your text: ";
			getline(cin, inputText);

			XorCipher xorCipher(inputText, key);
			string encryptedText = xorCipher.encrypts();
			cout << "Encrypted text: " << encryptedText << "\n";
			saveToFile("xorCipher.txt", encryptedText);
			break;
		}
		case 4:
		{
			cout << "Enter key: ";
			cin >> key;
			cin.ignore();

			inputText = loadFromFile("xorCipher.txt");
			if (inputText.empty())
			{
				cout << "No text to decrypt.\n";
				break;
			}
			
			XorCipher xorCipher(inputText, key);
			string decryptedText = xorCipher.decodes();
			cout << "Decrypted text: " << decryptedText << "\n";
			break;
		}
			
		default:
			cout << "Invalid choice. Please choose again.\n";
		}

	} while (choice != 0);

}