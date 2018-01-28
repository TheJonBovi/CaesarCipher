// main.cpp : Defines the entry point for the console application.

#include  "stdafx.h"
#include "_stdafx.h"
#include <fstream>
#include "caesaralgo.h"
#include <cstdlib>

using namespace std;

int main()
{	//string filename;


	// Code assistance from http://www.cplusplus.com/forum/beginner/21033/
	int choice;
	auto programRun = true;
	while (programRun) 
	{
		cout << "*************CaesarCipher************\n";
		cout << " 1 - Encrypt\n";
		cout << " 2 - Decrypt\n";
		cout << " 3 - Exit\n";
		cout << " Enter your choice and press return: ";

		cin >> choice;


		switch (choice)
		{
		case 1:
			{
				string plaintext = "";

				ifstream* fin = nullptr;
				try
				{	fin = new ifstream("plaintextfile.txt");
					char achar;
					while(fin->get(achar)) plaintext += achar;
					fin->close();
				}
				catch(exception error)
				{	if(fin != nullptr)	if(fin->good()) fin->close();
					delete fin;
					cout<< error.what();
				}


				char* cStrPlain = new char[strlen(plaintext.c_str())];
				char* ciphertext = new char[strlen(plaintext.c_str()) + 1];

				strcpy_s(cStrPlain, strlen(plaintext.c_str()) + 1 , plaintext.c_str());
				
				//Routines to make output all caps (ciphertext rules)
				for (size_t currentChar{}; currentChar < strlen(cStrPlain) + 1; currentChar++)
				{
					char c = cStrPlain[currentChar];
					if (isalpha(c) && !isspace(c))
					{
						c = toupper(c);
					}

					cStrPlain[currentChar] = c;
				}

				int key{};
				cout << " Enter Key: ";
				cin >> key;
				Caesar_En(cStrPlain, ciphertext, key);

				//Output to file
				fstream cipherStream;
				cipherStream.open("ciphertextfile.txt", ios::out | ios::trunc);
				cipherStream << ciphertext;
				cipherStream.close();

				//delete[] ciphertext;
				//delete[] cStrPlain;

				system("CLS");

				cout << "\n Encryption Sucessful! \n \n";

				system("PAUSE");
				system("CLS");


				break;
			}
		case 2:
			{
				string ciphertext = "";

				ifstream* fin = nullptr;
				try
				{	fin = new ifstream("ciphertextfile.txt");
					char achar;
					while(fin->get(achar)) ciphertext += achar;
					fin->close();
				}
				catch(exception error)
				{	if(fin != nullptr)	if(fin->good()) fin->close();
					delete fin;
					cout<< error.what();
				}


				// Create cString copies to use with provided algorithm
				char* cStrCipher = new char[strlen(ciphertext.c_str())];
				char* plaintext = new char[strlen(ciphertext.c_str()) + 1];

				strcpy_s(cStrCipher, strlen(ciphertext.c_str()) + 1 , ciphertext.c_str());
				
				//Routines to make output all lowercase (plaintext rules)
				for (size_t currentChar{}; currentChar < strlen(cStrCipher) + 1; currentChar++)
				{
					char c = cStrCipher[currentChar];
					if (isalpha(c) && !isspace(c))
					{
						c = tolower(c);
						cStrCipher[currentChar] = c;
					}
				}

				int key{};
				cout << " Enter Key: \n";
				cin >> key;
				Caesar_De(cStrCipher, plaintext, key);


				//Output to file
				fstream plainStream;
				plainStream.open("plaintextfile.txt", ios::out | ios::trunc);
				plainStream << plaintext;
				plainStream.close();

				system("CLS");

				cout << "\n Decryption Sucessful! \n \n";

				system("PAUSE");
				system("CLS");

				break;
			}
		case 3:
			{
				cout << "End of Program.\n";
				programRun = false;
				break;
			}
		default:
			{
				cout << "Not a Valid Choice. \n";
				cout << "Choose again.\n";
				cin >> choice;
				break;
			}
		}
	}
	return 0;
}