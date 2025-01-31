#include <stdio.h>
#include <math.h>

//Pi manuell definieren- Thanks ChatGPT
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//Datenarray, welches als Zwischenspeicher der Methoden fungiert. a, b, radius, phi;
void einlesen(float dataArray[]) {
	printf("Welche Koordinaten sollen umgewandelt werden?\n\nKartesische in Polarkoordinaten [1]\nPolarkoordinaten in kartesische [2]\n");
	int helper = 0;
	scanf_s("%fl", &dataArray[4]);
	if (dataArray[4] == 1) {
		//Polar in kartesisch
		printf("Radius und Winkel eingeben:\n[r],[phi]\n");
		scanf_s("%f,%f", &dataArray[2], &dataArray[3]);
		//printf("Eingabe war: %.2f,%.2f", dataArray[2], dataArray[3]);
	}
	else if (dataArray[4] == 2) {
		printf("X und Y Koordinaten eingeben:\n[x],[y]\n");
		scanf_s("%f,%f", &dataArray[0], &dataArray[1]);
		//printf("\n|z| = a + b*i =  %.2f + %.2f*i\n", dataArray[0], dataArray[1]);
	}
	else {
		printf("Eingabe ungültig.\n");
	}
}

void kartesischZuPolar(float dataArray[]) {
	//Radius bestimmen
	dataArray[2] = sqrtf(pow(dataArray[0], 2.0f) + pow(dataArray[1], 2.0));
	//Winkel bestimmen
	//Prüfen ob a oder b gleich null um Berechnung zu überspringen
	if (dataArray[0] == 0.0f || dataArray[1] == 0.0f) {
		if (dataArray[0] == 0.0f && dataArray[1] > 0.0f) dataArray[3] = M_PI / 2.0f;			//Rein imaginär-positiv
		else if (dataArray[0] == 0.0f && dataArray[1] < 0.0f) dataArray[3] = M_PI * 3 / 2.0f;	//Rein imaginär-negativ
		else if (dataArray[0] == 0.0f && dataArray[1] == 0.0f) dataArray[3] = 0.0f;			//Ursprung
		else if (dataArray[0] > 0.0f && dataArray[1] == 0.0f) dataArray[3] = 0.0f;				//Rein reell-positiv
		else if (dataArray[0] < 0.0f && dataArray[1] == 0.0f) dataArray[3] = M_PI;				//Rein reell-negativ			
	}
	else {
		//Ansonsten Winkel berechnen und nach Quadranten korrigieren
		dataArray[3] = atanf(dataArray[1] / dataArray[0]);						//Quadrant I
		if (dataArray[0] > 0.0f && dataArray[1] >= 0.0f) dataArray[3] + 2 * M_PI;	//Quadrant IV
		else if (dataArray[0] < 0.0f) dataArray[3] + M_PI;			//Quadrant II oder III
	}
}
void polarZuKartesisch(float dataArray[]) {
	//Mathematik
	//a = z * cos(phi)
	//b = z * sin(phi)
	dataArray[0] = dataArray[2] * cos(dataArray[3]);
	dataArray[1] = dataArray[2] * sin(dataArray[3]);
	}
void ausgeben(float dataArray[]) {
	//Ergebnisausgabe
	if (dataArray[4] == 1) {
		//Polarausgabe
		printf("z = %.2f * cos(%.2f) + i * sin(%.2f)\n", dataArray[2], dataArray[3], dataArray[3]);
	}
	else {
		//Kartesische Ausgabe
		printf("X-Koordinate:\t%f\nY-Koordinate:\t%f\n", dataArray[0], dataArray[1]);
	}
}

