// Break_Caesar.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"	//I guess I could copy and paste it over...
#include "Header.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <stdlib.h>

using namespace std;

bool ContainsWord(string newtext)//Check if nextext contains the word "the".
{	if(newtext.find("THE", 0) != string::npos) return true;

	if(newtext.find("AND", 0) != string::npos) return true;

	return false;
}

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

int main()
{	
	while (true)
	{
		//string ciphertext = "";
		string plaintext = "";
		ifstream* fin = nullptr;

		string ciphertext = ReadAll("ciphertextfile.txt");

		cout << "Press Enter to begin Cryptobreaker." << endl;

		system("PAUSE");
		system("CLS");

		for (int i(0); i < N_CHAR; ++i)
		{
			for (int j(0); j < ciphertext.size(); ++j)
			{
				if (ciphertext[j] < MINVAL || ciphertext[j] > MAXVAL)	plaintext += ciphertext[j];
				else plaintext += ciphertext[j] + i;
			}
			if (ContainsWord(plaintext)) break;
			plaintext = "";
		}

		if (plaintext == "")
		{
			cout << "Failure: no english text could be identified." << endl;

			system("PAUSE");
			system("CLS");

			//return 0;
		}
		else
		{
			fstream plainStream;
			plainStream.open("plaintextfile.txt", ios::out | ios::trunc);
			plainStream << plaintext;
			plainStream.close();

			cout << "Possible original text found, see plaintextfile.txt" << endl;

			system("PAUSE");
			system("CLS");
		}

	}
    return 0;

}

