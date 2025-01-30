#include <stdio.h>
#include <math.h>
#include "Aufgabe_5.h"

#define LEN(x)		sizeof(x) / sizeof(x[0]);
#define		ARRAY_LENGTH	5
//Slide 108 genauer anschauen
/// <summary>
/// Schreibe ein Programm, welches eine durch die Arraygröße festgelegte Anzahl an 
/// Zahlen vom Typ int in ein Array einliest und anschließend alle Zahlen,
/// sowie deren Summe ausgibt
/// </summary>
Teilaufgabe_1() {
	int array[ARRAY_LENGTH] = { 1,2,5,1,2 };
	int LENGTH = LEN(array);
	//Eingabe
	for (size_t i = 0; i < LENGTH; i++)
	{
		printf("Bitte geben Sie eine Zahl ein: ");
		scanf_s("%d", &array[i]);
	}
	int sum = 0;
	//Ausgabe
	for (size_t i = 0; i < LENGTH; i++)
	{
		printf("Zelle [%d]:\t%d\n",(int) i, array[i]);
		sum += array[i];
	}
	printf("Summe des Arrays:\t%d", sum);
}
/// <summary>
/// Schreibe ein Programm, welches eine durch die Arraygröße festgelegte Anzahl an 
/// Zahlen vom Typ int in ein Array einliest und ausgibt, ob diese Zahlen aufsteigend 
/// sortiert sind.
/// </summary>
Teilaufgabe_2() {
	int array[ARRAY_LENGTH];
	int LENGTH = LEN(array);
	int arrLength = sizeof(array) / sizeof(array[0]);
	for (size_t i = 0; i < arrLength; i++)
	{
		printf("Bitte geben Sie eine Zahl fuer Zelle[%d] ein:\t", (int)i);
		scanf_s("%d", &array[i]);
	}
	//Prüfen ob Zahlen aufsteigend sortiert sind
	int watchdog = 0;
	for (int i = 0; i < arrLength - 1; i++)
	{
		if (array[i] > array[i + 1]) {
			printf("Die Zahlen sind nicht aufsteigend sortiert.\n");
			printf("! Zelle[%d] ist groesser als Zelle[%d] ", i, (i + 1));
			printf("(%d > %d)\n", array[i], array[i + 1]);
			watchdog = 0;
		}
		else {
			watchdog = 1;
		}
	}
	if (watchdog == 1) {
		printf("Die Zahlen sind aufsteigend sortiert.\n");
	}
	printf("Programm Ende");
}
/// <summary>
/// Schreibe ein Programm, welches eine durch die Arraygr¨oße festgelegte Anzahl an Zahlen vom 
/// Typ int in ein Array einliest und die Differenzen aufeinander folgender Elemente in ein 
/// weiteres Array schreibt und dieses ausgibt.
/// </summary>
Teilaufgabe_3() {
	int array[ARRAY_LENGTH];
	int LENGTH = LEN(array);
	for (size_t i = 0; i < LENGTH; i++)
	{
		printf("Bitte geben Sie eine Zahl fuer Zelle[%d] ein:\t", (int)i);
		scanf_s("%d", &array[i]);
	}
	int arrayDiff[5];
	for (size_t i = 0; i < LENGTH-1; i++)
	{
		arrayDiff[i] = abs(array[i] - array[i + 1]);
	}
	//Ausgabe
	int array_diff_length = sizeof(arrayDiff) / sizeof(arrayDiff[0]);
	for (size_t i = 0; i < array_diff_length-1; i++)
	{
		printf("Differenz zwischen Zelle [%d] & [%d] betraegt:\t%d\n", (int)i, (int)(i + 1), arrayDiff[i]);
	}
}

