// Break_Caesar.cpp : Defines the entry point for the console application.
//
#include "_stdafx.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

int main()
{	string filename;
	string ciphertext = "";
	ifstream* fin = nullptr;
	try
	{	cout<< "Enter message or file: ";
		cin >> filename;
		fin = new ifstream(filename);
		if(fin) if (fin->good()) //double if for gaurenteed sequentialization
		{	char achar;
			while(fin->get(achar)) ciphertext += achar;
			fin->close();
		}
		else { ciphertext = filename; }
	}catch(exception error)
	{	if(fin != nullptr)	if(fin->good()) fin->close();
		delete fin;
		cout<< error.what();
	}

	for(int i(0); i < ; )

    return 0;
}

