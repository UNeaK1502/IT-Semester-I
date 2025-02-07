#include "Aufgabe_8.h"
#include <stdio.h>
#include <string.h>


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
color_t color_from_string(const char* s){
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
void Teilaufgabe_2() {

}