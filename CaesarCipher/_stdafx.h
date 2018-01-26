#pragma once

#ifndef _STDAFX
#define _STDAFX

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

const int NNUL = INT_MIN;//194
const std::string OoB("Error: Out of Bounds.\n");
const std::string AF ("Error: allocation failure.\n");

typedef double db;

inline void Flush() { cin.ignore(cin.rdbuf()->in_avail()); }
//void Clear_Screen();// Provided verbatum by Geer 2011

#endif