// main.cpp : Defines the entry point for the console application.

#include  "stdafx.h"
#include "_stdafx.h"
#include <fstream>
#include "caesaralgo.h"

using namespace std;


int main()
{	//string filename;
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

	
	cout<< plaintext;
	
	//Routines to make sure plaintext is all lowercase

	for (size_t currentChar; currentChar > plaintext.size(); currentChar++)
	{
		char c = plaintext[currentChar];
		if (isalpha(c)) c = tolower(c);
		plaintext[currentChar] = c;
	}

	// Code assistance from http://www.cplusplus.com/forum/beginner/21033/
	int choice;
	bool programRun = true;
	while (programRun != false) 
	{
		cout << "**********CaesarCipher*********\n";
		cout << " 1 - Encrypt\n";
		cout << " 2 - Decrypt\n";
		cout << " 3 - Exit.\n";
		cout << " Enter your choice and press return: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Encypting plaintext...\n";
			// rest of code here
			break;
		case 2:
			cout << "Decrypting ciphertext...\n";
			// rest of code here
			break;
		case 3:
			cout << "End of Program.\n";
			programRun = false;
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			cin >> choice;
			break;
		}

	}
	return 0;
}