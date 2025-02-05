//Libraries

#include <stdio.h>
#include <math.h>
#include "digit2hex.h"
//Pi manuell definieren- Thanks ChatGPT
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
/// <summary>
/// Input zurückgeben
/// </summary>
/// <returns>Einen validen Input der <= 1 ist.</returns>
int returnInput() {
	int input = 0;
	do {
		printf("Wert des Widerstands eingeben:\n");
		scanf_s("%d", &input);
	} while (input <= 1);
	return input;
}
/// <summary>
/// Berechnet die Potenz von einer bestimmten Anzahl an Digits
/// </summary>
/// <param name="digits">Digits nach dem Zehner</param>
/// <returns>10-er-Potenz</returns>
int getPotenz(int digits) {
	//Multiplikator berechnen
	int multiplikator = pow(10, digits - 1);
	//Potenz ermitteln
	int potenz = 0;
	//Potenz wird nur berechnet, wenn der Multiplikator nicht 0 ist (alles außer 1-Stellig)
	if (multiplikator != 0) {
		potenz = log10(multiplikator);
	}
	return potenz;
}
/// <summary>
/// Ausgabe für Widerstandsringe
/// </summary>
/// <param name="values"></param>
void ausgabeRinge(int values[])
{
	const char *colorCodes[10] = { "schwarz","braun","rot","orange","gelb",
											"gruen","blau","lila","grau","weiss" };
	//Werte durchgehen
	for (int i = 0; i < 3; i++)
	{
		//ColorCodes durchzählen
		for (int j = 0; j <= 9; j++)
		{
			//Wenn der gespeicherte Wert gleich einem Index des ColorCodes ist, die Farbe des dazugehörigen ColorCodes ausgeben.
			if (values[i] == j) {
				printf("Farbe des %d. Rings ist:\t%s\n", i + 1, colorCodes[j]);
				break;
			}
		}
	}
}

/// <summary>
/// Eine quadratische Gleichung lösen für eingegebene Parameter [a],[b],[c].
/// </summary>
/// <param name=""></param>
void Teilaufgabe_1(void) {
	float a, b, c = 0;

	printf("Parameter [a]x² + bx + c = 0 angeben:\n");
	scanf_s("%f", &a);
	printf("Parameter %.2flx² + [b]x + c = 0 angeben:\n", a);
	scanf_s("%f", &b);
	printf("Parameter %.2flx² + %.2flx + [c] = 0 angeben:\n", a, b);
	scanf_s("%f", &c);
	if ((b * b - 4.0f * a * c) < 0.0f) {
		printf("Keine relle Lösung, negative Zahl unter der Wurzel.");
	}
	else {
		float results[2] = {
			(-b + sqrt(pow(b, 2.0f) - 4.0f * a * c)) / (2.0f * a) ,
			(-b - sqrt(pow(b, 2.0f) - 4.0f * a * c)) / (2.0f * a)
		};
		//Ergebnis auf 2 Nachkommastellen runden und ausgeben
		for (int i = 0; i < 2; i++)
		{
			printf("Ergebnis %d:\t%.2f\n", i + 1, results[i]);
		}
	}
}
/// <summary>
/// Polarkoordinaten in kartesische umrechnen und umgekehrt
/// </summary>
/// <param name=""></param>
void Teilaufgabe_2(void)
{
	//Erste Abfrage ob Polar- oder Kartesische Koordinaten umgewandelt werden sollen
	printf("Welche Koordinaten sollen umgewandelt werden?\n\nKartesische in Polarkoordinaten [1]\nPolarkoordinaten in kartesische [2]\n");
	int choice;
	scanf_s("%d", &choice);
	if (choice == 1)
	{
		//kartesisch in Polar
		float a, b, radius, phi;
		printf("X und Y Koordinaten eingeben:\n[x],[y]\n");
		scanf_s("%f,%f", &a, &b);
		printf("\n|z| = a + b*i =  %.2f + %.2f*i\n", a, b);
		//Mathematik
		//Radius bestimmen
		radius = sqrtf(pow(a, 2.0f) + pow(b, 2.0));
		//Winkel bestimmen
		//Prüfen ob a oder b gleich null um berechnung zu überspringen
		if (a == 0.0f || b == 0.0f) {
			if (a == 0.0f && b > 0.0f) phi = M_PI / 2.0f;			//Rein imaginär-positiv
			else if (a == 0.0f && b < 0.0f) phi = M_PI * 3 / 2.0f;	//Rein imaginär-negativ
			else if (a == 0.0f && b == 0.0f) phi = 0.0f;			//Ursprung
			else if (a > 0.0f && b == 0.0f) phi = 0.0f;				//Rein reell-positiv
			else if (a < 0.0f && b == 0.0f) phi = M_PI;				//Rein reell-negativ			
		}
		else {
			//Winkel berechnen und nach Quadranten korrigieren
			phi = atanf(b / a);						//Quadrant I
			if (a > 0.0f && b >= 0.0f) phi + 2 * M_PI;	//Quadrant IV
			else if (a < 0.0f) phi + M_PI;			//Quadrant II oder III
		}
		//Ergebnisausgabe
		printf("z = %.2f * cos(%.2f) + i * sin(%.2f)", radius, phi, phi);

	}
	else if (choice == 2) {
		double  radius, phi, x, y = 0.0;
		//Polar in kartesisch
		printf("Radius und Winkel eingeben:\n[r],[phi]\n");
		scanf_s("%lf,%lf", &radius, &phi);
		//Mathematik bla bla
		x = radius * cos(phi);
		y = radius * sin(phi);
		//Ergebnisausgabe
		printf("X-Koordinate:\t%f\nY-Koordinate:\t%f", x, y);
	}
}
/// <summary>
/// Widerstandsprogramm aus 3.2 erweitern. Farbcodes für die Widerstandsringe ausgeben. Einer-/Zehnerstelle ausgeben
/// Multiplikator ausgeben. Eingabe auf Gültigkeit überprüfen. Zahlenbereich von 10mOhm (10^-2) bis 1G Ohm (10^10)
/// </summary>
/// <param name=""></param>
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

void Teilaufgabe_4() {
	//Es soll eine positive Ganzzahl eingelesen und alle Digits in einer eigenen Zeile ausgeben werden
	int input = 0;
	int counter = 0;
	int helper = 0;			//Kopie vom input erstellen
	do
	{
		printf("Beliebig lange Zahl eingeben (max. 4.3 Milliarden):\n");
		scanf_s("%d", &input);
	} while (input < 0);
	helper = input;

	//Länge der Zahl bestimmen
	//Solange durch 10 teilen, bis das Ergebnis 0 ist
	if (helper == 0)
	{
		counter++;
	}
	else
	{
		while (helper != 0)
		{
			helper /= 10;
			counter++;
		}
	}
	//Ausgabe der einzelnen Stellen von rechts nach links
	for (int i = 0; i < counter; i++)
	{
		int ergebnis = (input / (int)pow(10, i) % 10);
		printf("Die %d. Digit von rechts ist:\t %d\n", i + 1, ergebnis);
	}
}

void Teilaufgabe_5()
{
	//Digit2Hex
	unsigned int input = 0;
	do {
		printf("Zahl eingeben:\n");
		scanf_s("%u", &input);
	} while (input <= 1);
	int result = input & 0xFF;		//Maskieren um die 16 niederwertigsten Bits auszuwerten - Maximal 65535
	for (int i = 0xF; i >= 0; i--)
	{
		//Index ausgeben
		printf("%d\t", i);
	}
	printf("\n");
	for (int i = 0xF; i >= 0; i--)
	{
		//Bit ausgeben
		printf("%d\t", (result >> i) & 1);
	}
}
void Teilaufgabe_6()
{
	unsigned int input;
	printf("Zeichen eingeben:\n");
	scanf_s("%u", &input);
	//Länge ermitteln
	int helper = input;
	int length = 0;		//In Hex
	while (helper != 0) {
		//Solange nach rechts shiften bis die letzte 1 raus geshiftet wurde
		//helper >>= 1;		//Länge in bits
		helper /= 16;		//Länge in Hexadezimalzahlen
		length++;
	}
	//Ausgabe
	for (int i = length-1; i >= 0; i--)
	{
		printf("%c\t", digit2hex((input >> (i * 4)) & 0xF));
	}
}
void Teilaufgabe_7()
{
	//Bin2Dec
	int input;
	printf("Binärzahl eingeben:\n");
	scanf_s("%d", &input); //Binärzahl wird als Dezimalzahl eingelesen
	int helper = input;

	//Länge ermitteln

	int length = 0;
	while (helper != 0) {
		helper /= 10;
		length++;
	}
	//Array erstellen
	int array[sizeof(input) * 4];

	helper = input;
	for (int i = 0; i < length; i++)
	{
		array[i] = helper % 10; //Letzte Stelle auswerten
		if (helper != 10) {
			helper /= 10;
		}
		else {					//Catch wenn die letzten beiden Ziffern 10 ergeben, würde eine [0] statt [1][0] geschrieben
			array[i] = 0;
			array[i + 1] = 1;
			break;
		}
	}
	//Ergebnis aufsummieren
	int result = 0;
	for (int i = 0; i < length; i++) {
		result += array[i] * pow(2, i);
	}
	printf("Ergebnis: %d", result);
}
void Teilaufgabe_8()
{
	//Zähle gesetzte Bits
	printf("Dezimalzahl eingeben:\n");
	unsigned int input = 0;
	int counter = 0;
	unsigned array[32];		//32-bit

	//scanf_s("%d", array);
	scanf_s("%d", &input);
	int length = 0;
	int helper = input;
	while (helper != 0) {
		//Solange nach rechts shiften bis die letzte 1 raus geshiftet wurde
		helper = helper >> 1;
		length++;
	}
	//Wird nur solange ausgewertet wie die Binärzahl lang ist
	for (int i = 0; i < length; i++)
	{
		//Input um I-Stellen nach rechts shiften um letzte Stelle zu ver-UND-en
		if ((input >> i) & 1) {
			counter++;
			array[i] = 1;
		}
		else {
			array[i] = 0;
		}
	}
	printf("Anzahl gesetzter Bits: %d\n", counter);
	//Ausgabe - 2er Potenzen
	int summe = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		int bla = pow(2, i);
		//Summe aufaddieren wenn ein Bit gesetzt ist - optional
		if (array[i] & 1) summe += bla;
		printf("%d\t", bla);
	}
	//Ausgabe - Binärzahl
	printf("\n");
	for (int i = length; i > 0; i--)
	{
		printf("%d\t", array[i - 1]);
	}
	printf("\nSumme:\t%d", summe);

}