#include <stdio.h>
#include <math.h>

//Pi manuell definieren- Thanks ChatGPT
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
void einlesen(float dataArray[]) {
	printf("Welche Koordinaten sollen umgewandelt werden?\n\nKartesische in Polarkoordinaten [1]\nPolarkoordinaten in kartesische [2]\n");
	int choice;	
	scanf_s("%d", &choice);
	switch (choice) {
	case 1: //Polar in kartesisch
		printf("Radius und Winkel eingeben:\n[r],[phi]\n");
		scanf_s("%f,%f", dataArray[2], dataArray[3]);
		printf("%.2f", dataArray[2]);
		break;
	case 2:
		printf("X und Y Koordinaten eingeben:\n[x],[y]\n");
		scanf_s("%f,%f", dataArray[0], dataArray[1]);
		printf("\n|z| = a + b*i =  %.2f + %.2f*i\n", dataArray[0], dataArray[1]);
		break;
	default:
		printf("Eingabe ungueltig");
		break;
	}
}

void kartesischZuPolar(float a, float b ) {
	//kartesisch in Polar
	float radius, phi = 0.0;
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
void polarZuKartesisch(float phi, float radius) { 
		  float x, y = 0.0;
	
	//Mathematik bla bla
	x = radius * cos(phi);
	y = radius * sin(phi);
	//Ergebnisausgabe
	printf("X-Koordinate:\t%f\nY-Koordinate:\t%f", x, y);
}
void ausgeben(){}

