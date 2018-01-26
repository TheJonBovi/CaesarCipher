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
	//Some Test comment
	cout << plaintext;

	return 0;
}