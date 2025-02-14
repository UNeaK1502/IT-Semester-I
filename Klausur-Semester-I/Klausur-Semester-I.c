#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Hauptprogramm


int matrikelnr(char* nr, int maxlen);
int num2text(char* text, int maxlen, int num);
//Extra
int smallnum2text(char* text, int maxlen, int num,int digits);	//Sonderfall eine Million, ein Tausend

int main()
{	
	//Getinput
	char ausgabe;
		num2text(ausgabe, 5, 1234);
	return 0; 
}
int num2text(char* text, int maxlen, int num) {
	return 0;
}

int matrikelnr(char* nr, int maxlen) {
	char* matrikel = (char*)malloc(maxlen);
	if (matrikel == NULL) {
		return -1;
	}
	strcpy(matrikel, nr);
	free(matrikel);
	return 0;
}