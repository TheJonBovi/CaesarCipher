#include "_stdafx.h"
#include "caesaralgo.h"

void Caesar_En(const char plaintext[], char ciphertext[], int key)
{
	int i;
	int relative_value;//	The numeric value of the current character relative to the first character in the set alphabet
	key = key % N_CHAR;//	Used specifically for negatives

	for (i = 0; plaintext[i] != 0; i++)
	{	relative_value = plaintext[i] - MINVAL;//brings the ASCII value of 'a' down to 0 for the first alphabet
		if ( plaintext[i] < MINVAL || plaintext[i] > MAXVAL )	ciphertext[i] = plaintext[i];
		else ciphertext[i] = unsigned((relative_value + N_CHAR + key) % N_CHAR + MINVAL);
	}/* ^ adding N_CHAR then taking the modulos negates the concequences of the plaintext being less than the absolute value of the key.*/

	ciphertext[i] = 0; key = 0;//Terminating Char, and cleanup.
}

void Caesar_De(const char ciphertext[], char plaintext[], int key)
	{ Caesar_En(ciphertext, plaintext, -key); }
