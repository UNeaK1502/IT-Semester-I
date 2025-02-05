#include <stdio.h>
#include <math.h>

#define LENGTH_COLOR_ARRAY 10

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
void ausgabeRinge(int values[])
{
	const char* colorCodes[LENGTH_COLOR_ARRAY] = { "schwarz","braun","rot","orange","gelb",
											"gruen","blau","lila","grau","weiss" };
	//Werte durchgehen
	for (int i = 0; i < 3; i++)
	{
		//ColorCodes durchzählen
		for (int j = 0; j <= LENGTH_COLOR_ARRAY - 1; j++)
		{
			//Wenn der gespeicherte Wert gleich einem Index des ColorCodes ist, die Farbe des dazugehörigen ColorCodes ausgeben.
			if (values[i] == j) {
				printf("Farbe des %d. Rings ist:\t%s\n", i + 1, colorCodes[j]);
				break;
			}
		}
	}
}