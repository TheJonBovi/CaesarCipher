// main.cpp : Defines the entry point for the console application.

#include "_stdafx.h"
#include <fstream>
#include "caesaralgo.h"
#include <cstdlib>
#include <locale>

using namespace std;


string& ReadAll(const char* file)
{	static string text;
	text = "";

	ifstream* fin = nullptr;
	try
	{	fin = new ifstream(file);
		char achar;
		while(fin->get(achar)) text += achar;
		fin->close();
	}
	catch(exception error)
	{	if(fin != nullptr)	if(fin->good()) fin->close();
		delete fin;
		cout<< error.what();
	}
	
	return text;
}

char* ToLower(char* text)	//Routines to make output all lowercase (plaintext rules)
{	for (size_t currentChar{}; currentChar < strlen(text) + 1; currentChar++)
	{	char c = text[currentChar];
		if (isalpha(c) && !isspace(c)) text[currentChar] = tolower(c);
	}
	return text;
}

char* ToUpper(char* text)	//Routines to make output all caps (ciphertext rules)
{	for (size_t currentChar{}; currentChar < strlen(text) + 1; currentChar++)
	{	char c = text[currentChar];
		if (isalpha(c) && !isspace(c)) text[currentChar] = toupper(c);
	}
	return text;
}

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
		case 1:{
			string plaintext = ReadAll("plaintextfile.txt");

			// Create cString copies to use with provided algorithm
			char* cStrPlain  = new char[strlen(plaintext.c_str())	 ];
			char* ciphertext = new char[strlen(plaintext.c_str()) + 1];

			strcpy_s(cStrPlain, strlen(plaintext.c_str()) + 1 , plaintext.c_str());
				
			ToLower(cStrPlain);

			int key{};
			cout << " Enter Key: ";
			cin >> key;
			Caesar_En(cStrPlain, ciphertext, key);

			ToUpper(ciphertext);

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

		case 2:{
			string ciphertext = ReadAll("ciphertextfile.txt");

			// Create cString copies to use with provided algorithm
			char* cStrCipher = new char[strlen(ciphertext.c_str())	  ];
			char* plaintext  = new char[strlen(ciphertext.c_str()) + 1];

			strcpy_s(cStrCipher, strlen(ciphertext.c_str()) + 1 , ciphertext.c_str());
				
			ToLower(cStrCipher);

			int key{};
			cout << " Enter Key: \n";
			cin >> key;
			Caesar_De(cStrCipher, plaintext, key);

			//ToLower(plaintext) is redundant

			//Output to file
			fstream plainStream;
			plainStream.open("plaintextfile.txt", ios::out | ios::trunc);
			plainStream << plaintext;
			plainStream.close();

			//delete [] cStrCipher;
			//delete [] plaintext;

			system("CLS");

			cout << "\n Decryption Sucessful! \n \n";

			system("PAUSE");
			system("CLS");

			break;
			}

		case 3:{
			cout << "End of Program.\n";
			programRun = false;
			break;
			}

		default:{
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			cin >> choice;
			break;
			}
		}
	}
	return 0;
}