#pragma once

#ifndef _STDAFX
#define _STDFAX

#include <iostream>
#include <string>
#include <climits>//<limits.h> + <yvals.h>
#include <conio.h>//For _getch();
#include <iomanip>
#include <cstdlib>
#include <exception>
//#include "Clear_Screen.cpp"
using namespace std;

#define DEBUGPAUSE _getch();	//ON
#define CAST(type, data) reinterpret_cast< type >(reinterpret_cast<void*>( data ))

#ifndef ORF
#define ORF else if
#endif

const int NNUL = INT_MIN;//194
const std::string OoB("Error: Out of Bounds.\n");
const std::string AF ("Error: allocation failure.\n");

typedef double db;

inline void Flush() { cin.ignore(cin.rdbuf()->in_avail()); }
//void Clear_Screen();// Provided verbatum by Geer 2011

//#include "Linked List.h"
//#include "ArrayList.h"
//#include "ArrayStack.h"
//#include "Binary Tree List.h"

//Code Storage
//cout.precision(0);	cout << std::fixed << setiosflags(ios::left);

#endif