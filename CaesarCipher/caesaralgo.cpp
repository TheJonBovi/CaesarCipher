
#include "stdafx.h"
#include "caesaralgo.h"

void Caesar_En(char plaintext[], char ciphertext[], int key)
{
	int i;
	unsigned char pc;//         plaincharacter[i]
	key = key % N_CHAR;//  Used specifically for negatives

	for (i = 0; plaintext[i] != 0; i++)
	{
		pc = plaintext[i] - MINVAL;//        brings the ASCII value of 'a' down to 0.
		if ( plaintext[i] < MINVAL || plaintext[i] > MAXVAL )	ciphertext[i] = plaintext[i];
		else ciphertext[i] = unsigned((pc + N_CHAR + key) % N_CHAR + MINVAL);
	}/* ^ adding N_CHAR then taking the modulos negates the concequences of ( pt < abs(key) ) ^ */

	ciphertext[i] = 0; key = 0;//             Terminating Char, and cleanup.
}

void Caesar_De(char ciphertext[], char plaintext[], int key)
{ 
	Caesar_En(ciphertext, plaintext, -key);
}
