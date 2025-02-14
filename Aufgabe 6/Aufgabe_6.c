#include <stdio.h>
#include <math.h>
#include "6.2.h"
#include "6.3.h"
#include "6.4.h"

//Pi manuell definieren- Thanks ChatGPT
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define LENGTH		5
#define LENGTH_CHAR_ARRAY 100	

#define LEN(x)		sizeof(x) / sizeof(x[0]);	

void getInput(int array[]) {						//alternativ void getInput (int *array){
	for (size_t i = 0; i < LENGTH; i++)
	{
		printf("Bitte geben Sie eine Zahl fuer Zelle[%d] ein:\t", (int)i);
		scanf_s("%d", &array[i]);
	}
}
void calculateArrayDiff(int array[], int arrayDiff[]) {
	for (size_t i = 0; i < LENGTH - 1; i++)
	{
		arrayDiff[i] = abs(array[i] - array[i + 1]);
	}
}
void printArrayDiff(int array[]) {
	for (size_t i = 0; i < LENGTH - 1; i++)
	{
		printf("Differenz zwischen Zelle [%d] & [%d] betraegt:\t%d\n", (int)i, (int)(i + 1), array[i]);
	}
}
void Teilaufgabe_1() {
	int array[LENGTH];
	int arrayDiff[LENGTH - 1];
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
	float dataArray[] = { 0.0,0.0,0.0,0.0,0.0 };
	einlesen(dataArray);
	//Polar in Kartesisch
	kartesischZuPolar(dataArray);
	polarZuKartesisch(dataArray);
	ausgeben(dataArray);

}
//----------------------------------------------------------

/// <summary>
/// Schreibe ein Programm, welches einen String von festgelegter Maximallänge einliest und 
/// bei Buchstaben die Groß / -Kleinschreibung vertauscht(a -> A, H -> h).
/// </summary>
void Teilaufgabe_3() {
	char input[LENGTH_CHAR_ARRAY];
	char output[LENGTH_CHAR_ARRAY];
	getMatrInputChars(input);
	umwandeln(input, output);
	printOutput(output);

}
/// <summary>
///Schreibe ein Programm, welches eine Zeichenkette einliest und diese in eine Zahl vom Typ unsigned
/// int konvertiert("1337" → 1337).Ist ein ungültiges Zeichen(keine Ziffer) in der Eingabe enthalten,
/// soll eine Fehlermeldung ausgegeben werden. Welche Möglichkeiten zur Kategorisierung der Zeichen
/// existieren ? (Tipp: C - Standardbibliothek verwenden)
/// Die Konvertierung ist in einer eigenen Funktion zu implementieren, die zur¨uck gibt, ob die Konvertierung
/// erfolgreich war.
/// </summary>
void Teilaufgabe_4() {
	char input[LENGTH_CHAR_ARRAY];
	getMatrInputChars(input);
	unsigned int output = 0;
	if (convertStringToUInt(input, &output)) {
		printf("Die Konvertierung war erfolgreich. Die Zahl lautet: %d\n", output);
	}
	else {
		printf("Die Konvertierung war nicht erfolgreich. Bitte geben Sie nur Zahlen ein.\n");
	}
}