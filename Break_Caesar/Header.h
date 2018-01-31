#pragma once

#define LETTERS_ONLY

#ifdef LETTERS_ONLY

#define ALPHABET                          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
const int MINVAL(65);   //40 (OCT) 20(HEX) Minimum ASCII Value
const int MAXVAL(90);  //176(OCT) 7E(HEX) Maximum ASCII Value
#else
#define ALPHABET                          " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
const int MINVAL(32);   //40 (OCT) 20(HEX) Minimum ASCII Value
const int MAXVAL(126);  //176(OCT) 7E(HEX) Maximum ASCII Value
#endif
const int MAXFIL(256);    //The maximum in <bytes?> size of a file
const int N_CHAR(MAXVAL - MINVAL + 1); //Number of Characters available.(26 or 95)
const int MAXKEY(N_CHAR + 1);    //(Maximum) length for a text key for vigenere or substitution encryption 26

#define NUM_ARRAY_ENTRIES(a)  ( sizeof(a)/sizeof(*a) )
								 //constexpr int NUM_ARRAY_ENTRIES(MenuChoice a)  { return sizeof(a)/sizeof(*a); } //Why won't this work?