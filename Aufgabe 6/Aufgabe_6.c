#include <stdio.h>
#include <math.h>
#include "6.2.h"

//Pi manuell definieren- Thanks ChatGPT
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define LENGTH		5

#define LEN(x)		sizeof(x) / sizeof(x[0]);	

void getInput(int array[]) {
	for (size_t i = 0; i < LENGTH; i++)
	{
		printf("Bitte geben Sie eine Zahl fuer Zelle[%d] ein:\t", (int)i);
		scanf_s("%d", &array[i]);
	}
}
void calculateArrayDiff(int array[], int arrayDiff[]) {
	for (size_t i = 0; i < LENGTH-1; i++)
	{
		arrayDiff[i] = abs(array[i] - array[i + 1]);
	}
}
void printArrayDiff(int array[]) {
	for (size_t i = 0; i < LENGTH-1; i++)
	{
		printf("Differenz zwischen Zelle [%d] & [%d] betraegt:\t%d\n", (int)i, (int)(i + 1), array[i]);
	}
}
void Teilaufgabe_1() {
	int array[LENGTH];
	int arrayDiff[LENGTH-1];
	//Eingabe
	getInput(array);
	//Berechnung
	calculateArrayDiff(array, arrayDiff);
	//Ausgabe
	printArrayDiff(arrayDiff);
}

void Teilaufgabe_2() {
	//Polarform in Kartesisch umwandeln und umgekehrt mit Hilfe von Funktionen
	
	//Datenarray, welches als Zwischenspeicher der Methoden fungiert. a, b, radius, phi;
	float dataArray[] = { 0.0,0.0,0.0,0.0,0.0};
	einlesen(dataArray);
	//Polar in Kartesisch
	kartesischZuPolar(dataArray);
	polarZuKartesisch(dataArray);
	//berechnen(dataArray);
	ausgeben(dataArray);

}
void Teilaufgabe_3() {

}
void Teilaufgabe_4() {

}