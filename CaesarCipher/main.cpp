// main.cpp : Defines the entry point for the console application.

#include  "stdafx.h"
#include "_stdafx.h"
#include <fstream>
#include "caesaralgo.h"

using namespace std;


int main()
{
	/* This whole thing is me verifying drew understands how algorithm works
	char testplaintext[] = "Hello World";
	char testciphertext[sizeof(testplaintext)];
	int testkey = 0;

	cout << "Please provide a key: ";
	cin >> testkey;

	cout << testplaintext << endl;

	Caesar_En(testplaintext, testciphertext, testkey); //Test Encode

	cout << testciphertext << endl;
the
	Caesar_De(testciphertext, testplaintext, testkey); //Test Decode

	cout << testplaintext << endl;
	*/

	//Function to open plaintext file
	// Not sure how to pull strings out of file, working on it

	string filename;
	string plaintext = "";
	ifstream* fin = nullptr;
	try
	{	cout<< "Enter message or file: ";
		cin >> filename;
		fin = new ifstream(filename);
		if(fin) if (fin->good()) //double if for gaurenteed sequentialization
		{	char achar;
			while(fin->get(achar)) plaintext += achar;
			fin->close();
		}
		else { plaintext = filename; }
	}catch(exception error)
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
	cout << plaintext;

	return 0;
}