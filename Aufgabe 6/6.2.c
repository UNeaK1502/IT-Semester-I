#include <stdio.h>
#include <math.h>

//Pi manuell definieren- Thanks ChatGPT
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//Datenarray, welches als Zwischenspeicher der Methoden fungiert. a, b, radius, phi;
void einlesen(float dataArray[]) {
	printf("Welche Koordinaten sollen umgewandelt werden?\n\nKartesische in Polarkoordinaten [1]\nPolarkoordinaten in kartesische [2]\n");
	scanf_s("%f", &dataArray[4]);
	if (dataArray[4] == 1) {
		printf("X und Y Koordinaten eingeben:\n[x],[y]\n");
		scanf_s("%f,%f", &dataArray[0], &dataArray[1]);
		//printf("\n|z| = a + b*i =  %.2f + %.2f*i\n", dataArray[0], dataArray[1]);
	}
	else if (dataArray[4] == 2) {
		//Polar in kartesisch
		printf("Radius und Winkel eingeben:\n[r],[phi]\n");
		scanf_s("%f,%f", &dataArray[2], &dataArray[3]);
		printf("Eingabe war: %.2f\t%.2f\n", dataArray[2], dataArray[3]);
	}
	else {
		printf("Eingabe ungültig.\n");
	}
}

void kartesischZuPolar(float dataArray[]) {
	//Checken ob kartesisch in Polar konvertiert werden soll
	if (dataArray[4] == 1) {
		//Radius bestimmen
		dataArray[2] = sqrtf(pow(dataArray[0], 2.0) + pow(dataArray[1], 2.0));
		//Winkel bestimmen
		//Prüfen ob a oder b gleich null um Berechnung zu überspringen
		if (dataArray[0] == 0.0f || dataArray[1] == 0.0f) {
			if (dataArray[0] == 0.0f && dataArray[1] > 0.0f) dataArray[3] = M_PI / 2.0f;			//Rein imaginär-positiv
			else if (dataArray[0] == 0.0f && dataArray[1] < 0.0f) dataArray[3] = M_PI * 3 / 2.0f;	//Rein imaginär-negativ
			else if (dataArray[0] == 0.0f && dataArray[1] == 0.0f) dataArray[3] = 0.0f;				//Ursprung
			else if (dataArray[0] > 0.0f && dataArray[1] == 0.0f) dataArray[3] = 0.0f;				//Rein reell-positiv
			else if (dataArray[0] < 0.0f && dataArray[1] == 0.0f) dataArray[3] = M_PI;				//Rein reell-negativ			
		}
		else {
			//Ansonsten Winkel berechnen und nach Quadranten korrigieren
			dataArray[3] = atanf(dataArray[1] / dataArray[0]);										//Quadrant I - keine Korrektur
			if (dataArray[0] > 0.0f && dataArray[1] < 0.0f) dataArray[3] += 2 * M_PI;				//Quadrant IV
			else if (dataArray[0] < 0.0f) dataArray[3] += M_PI;										//Quadrant II oder III
		}
	}
}
void polarZuKartesisch(float dataArray[]) {
	//Checken ob von Polar zu kartesisch konvertiert werden soll
	if (dataArray[4] == 2) {
		//Mathematik
		//a = z * cos(phi)
		//b = z * sin(phi)
		dataArray[0] = dataArray[2] * cos(dataArray[3]);
		dataArray[1] = dataArray[2] * sin(dataArray[3]);
	}
}
void ausgeben(float dataArray[]) {
	//Ergebnisausgabe
	float bla = dataArray[4];
	if (dataArray[4] == 1.0f) {
		//Polarausgabe
		printf("Radius:\t%.4f\nWinkel (Bogenmass):\t%.4f\n", dataArray[2], dataArray[3]);
		printf("z = %.2f * cos(%.2f) + i * sin(%.2f)\n", dataArray[2], dataArray[3], dataArray[3]);
	}
	else if(dataArray[4] == 2.0f){
		//Kartesische Ausgabe
		printf("\nX-Koordinate:\t%.2f\nY-Koordinate:\t%.2f\n", dataArray[0], dataArray[1]);
	}
}

