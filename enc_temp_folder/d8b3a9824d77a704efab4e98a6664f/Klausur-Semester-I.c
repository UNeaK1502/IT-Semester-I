#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MATRIKELNR_LEN		8

//Hauptprogramm


int matrikelnr(char* nr, int maxlen);
int num2text(char* text, int maxlen, int num);
void getMatrikelInput(char input[]);
void printOutput(char output[]);
//Extra
//int smallnum2text(char* text, int maxlen, int num,int digits);	//Sonderfall eine Million, ein Tausend

int main()
{	
	char matrikelNummer[MATRIKELNR_LEN];
	int sdfs = matrikelnr(matrikelNummer, MATRIKELNR_LEN);

	printOutput(matrikelNummer);

	/*
	Getinput
	char ausgabe;
		num2text(ausgabe, 5, 1234);*/
	return 0; 
}
int num2text(char* text, int maxlen, int num) {

	return 0;
}
/// <summary>
/// Methode zum Einlesen und prüfen der Matrikelnummer
/// </summary>
/// <param name="nr"></param>
/// <param name="maxlen"></param>
/// <returns></returns>
int matrikelnr(char *nr, int maxlen) {
	char helper[100];
	getMatrikelInput(helper);					//Matrikelnummer einlesen
	if (strlen(helper) < maxlen) {
		//Wenn eingegebene Matrikelnummer kleiner als 8 ist, dann Matrikelnr schreiben und 0 zurückgeben
		strcpy_s(nr, maxlen, helper);
		return 0;
	}
	else { 
		return -1;
	}
}
void getMatrikelInput(char input[]) {
	printf("Bitte geben Sie einen String ein:\t");
	scanf_s("%s", input, MATRIKELNR_LEN);				//Als Buffergroesse wird die maximal Länge vom Char-Array genommen
}
void printOutput(char output[]) {
	printf("%s", output);
}