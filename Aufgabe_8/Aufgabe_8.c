#include "Aufgabe_8.h"
#include <stdio.h>
#include <math.h>

//Pi manuell definieren- Thanks ChatGPT
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void (*vectorFunctions[METHOD_COUNT])(vec2_t*, vec2_t*) = {
	(void (*)(vec2_t*, vec2_t*)) getVectorInput,     // Achtung: Cast notwendig wegen unterschiedlicher Signatur
	(void (*)(vec2_t*, vec2_t*)) printVec	tor,
	(void (*)(vec2_t*, vec2_t*)) getScalarProduct,
	(void (*)(vec2_t*, vec2_t*)) mathOpsVectors,
	(void (*)(vec2_t*, vec2_t*)) getVectorAbsolut,
	(void (*)(vec2_t*, vec2_t*)) calculateVectorAngle
};
void Teilaufgabe_1() {
	//Farben Rot, Lila, Gelb, Blau und Grau. Implementiere
	// eine Funktion, die eine Farbe(enum) in eine dazugeh¨orige Zeichenkette(string, z.B.”Rot“) umwandelt,
	// sowie eine Funktion, die aus einer gegebenen Zeichenkette das passende Element der Aufzählung
	// auswählt. Ist die gegebene Zeichenkette keiner Farbe zuzuordnen, soll Grau zurückgegeben werden
	// Die Signaturen der zu implementierenden Funktionen sind const char *color_to_string(color_t	color); 
	// und color_t color_from_string(const char* s);
	// Lese zum Testen eine Farbe(string) ein, wandle sie in die zugehörige Aufzählung(color t) um, und
	// konvertiere sie anschließend wieder in einen string.Dieser String soll ausgegeben werden und wenn
	// eingegebener und ausgegebener String ¨ubereinstimmen, funktionieren die Funktionen korrekt.
	// Tipp: Speichere die Zuordnung von Enum zu zugehörigem String für beide Funktionen in einer Lookup -
	// Tabelle(Array eines struct, welches jeweils ein Enum und einen String enthält).
	char colorStr[10];
	printf("Bitte eine Farbe eingeben:\t");
	scanf_s("%s", colorStr, 10);
	color_t color = color_from_string(colorStr);
	const char* colorStr2 = color_to_string(color);
	printf("Farbe: %s\n", colorStr2);
}
color_t color_from_string(const char* s) {
	//Alternati Lookup Tabelle mit Struct
	//struct colorLookup {
	//	color_t color;
	//	const char* colorStr;
	//};
	//colorLookup colorLookupTable[] = {
	//	{Rot,"Rot"},
	//	{Lila,"Lila"},
	//	{Gelb,"Gelb"},
	//	{Blau,"Blau"},
	//	{Grau,"Grau"}
	//};

	if (strcmp(s, "Rot") == 0) {
		return Rot;
	}
	else if (strcmp(s, "Lila") == 0) {
		return Lila;
	}
	else if (strcmp(s, "Gelb") == 0) {
		return Gelb;
	}
	else if (strcmp(s, "Blau") == 0) {
		return Blau;
	}
	else if (strcmp(s, "Grau") == 0) {
		return Grau;
	}
	else {
		return Grau;
	}
}
const char* color_to_string(color_t	color) {
	switch (color) {
	case Rot:
		return "Rot";
	case Lila:
		return "Lila";
	case Gelb:
		return "Gelb";
	case Blau:
		return "Blau";
	case Grau:
		return "Grau";
	default:
		return "Grau";
	}
}

//-------------------------------------------------------------------------------------
void Teilaufgabe_2() {
	vec2_t vector1, vector2;
	getVectorInput(&vector1);
	getVectorInput(&vector2);
	printf("Welche Operation soll durchgeführt werden?\n\nSkalarprodukt[0]\nBetrag beider Vektoren[1]\nSumme/Differenz[2]\n");
	//Array/Struct mit Funktionen
	int eingabe = 0;
	scanf_s("%d", &eingabe);
	(*vectorFunctions[eingabe])(&vector1, &vector2);
}
//Methoden in einem Array zusammen fassen

void getVectorInput(vec2_t* input) {
	printf("X-Komponente eingeben:\n");
	scanf_s("%f", &input->x);
	printf("Y-Komponente eingeben:\n");
	scanf_s("%f", &input->y);
	printf("Z-Komponente eingeben:\n");
	scanf_s("%f", &input->z);
}
void printVector(vec2_t* output) {
	printf("Komponenten sind:\nX:\t%.2f\nY:\t%.2f\nZ:\t%.2f\n", output->x, output->y, output->z);
}
float getScalarProduct(vec2_t vector1, vec2_t vector2) {
	//a1*b1 + a2*b2 + a3*b3
	float result = vector1.x * vector2.x;
	result += vector1.y * vector2.y;
	result += vector1.z * vector2.z;
	/*printVector(&vector1);
	printVector(&vector2);*/
	printf("Das Skalarprodukt der beiden Vektoren betraegt:\t%.2f\n", result);
	return result;
}
/// <summary>
/// Auswählen ob 2 Vektoren addiert oder subtrahiert werden	
/// </summary>
/// <param name="vector1"></param>
/// <param name="vector2"></param>
void mathOpsVectors(vec2_t vector1, vec2_t vector2) {
	//Funktioniert
	vec2_t result;
	printf("Soll addiert [1] oder subtrahiert [0] werden?\n");
	int eingabe = 0;
	scanf_s("%d", &eingabe);
	if (eingabe) {
		result.x = vector1.x + vector2.x;
		result.y = vector1.y + vector2.y;
		result.z = vector1.z + vector2.z;
	}
	else {
		result.x = vector1.x - vector2.x;
		result.y = vector1.y - vector2.y;
		result.z = vector1.z - vector2.z;
	}
	printVector(&result);
}
float getVectorAbsolut(vec2_t vector) {
	//(a²+b²+c²)^(-0.5)
	float result = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	printVector(&vector);
	return result;
}
void calculateVectorAngle(vec2_t vector1, vec2_t vector2) {
	//arccos ((a*b)/(vektorprodukt
	float absVector1, absVector2, vectorProduct;
	absVector1 = getVectorAbsolut(vector1);
	absVector2 = getVectorAbsolut(vector2);
	vectorProduct = getScalarProduct(vector1, vector2);
	//Bis hier richtig
	float angle = acosf(vectorProduct / (absVector1 * absVector2));	//Angabe in Bogenmass
	float angleDegree = angle / (2 * M_PI) * 360.0;
	printf("Der Winkel zwischen den beiden Vektoren betraegt %.2f Grad\n", angleDegree);
}