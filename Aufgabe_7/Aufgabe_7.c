#include <stdio.h>
#include <math.h>
#include "7.1.h"
#include "7.2.h"
#include "7.3.h"

#define LENGTH_CHAR_ARRAY 100

void Teilaufgabe_1() {
	char array[LENGTH_CHAR_ARRAY];
	getMatrikelInput(array);
	strreverse(array);
	printOutput(array);
}
void Teilaufgabe_2() {
	char array[LENGTH_CHAR_ARRAY];
	getMatrikelInput(array);
	if (checkPalindrome(array)) {
		printf("%s ist ein Palindrom", array);
	}
	else {
		printf("%s ist kein Palindrom", array);
	}
}
void Teilaufgabe_3() {
	int resistance = 0;
	//Input Abfragen
	resistance = returnInput();
	int helper = resistance;

	int digits = 0;
	//Zehner berechnen
	while (helper >= 10)
	{
		helper /= 10;
		digits++;										//Gibt die Stellen hinter dem Zehner an
	}
	int zehner = helper;
	int einser = 0;
	int potenz = getPotenz(digits);

	//Sonderfall für 1-stellige Widerstände
	if (resistance < 10) {
		//Wenn Zehner gleich 0 ist der Einser gleich dem Eingabewert (Helper)
		zehner = 0;											//Zehner muss überschrieben werden
		einser = helper;
	}
	else {
		//Wenn nicht, Einser berechnen
		helper = resistance - (zehner * pow(10, digits));	//Zieht vom Gesamtwiderstand den Betrag der Zehnerstelle ab
		while (helper >= 10) {
			helper /= pow(10, potenz);					//Teilt durch den Multiplikator - Entfernt alle Stellen hinter dem einer
		}
		einser = helper;
	}
	int values[3] = { zehner,einser,potenz };				//Daten zusammenfassen
	//Ausgabe
	ausgabeRinge(values);
}