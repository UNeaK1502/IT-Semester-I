//Libraries

#include <stdio.h>
#include "Aufgabe_8.h"

//Hauptprogramm

int main()
{
	printf("Welche Teilaufgabe soll bearbeitet werden?\n");
	do {
		int inputTask = 0;
		scanf_s("%d", &inputTask);

		switch (inputTask) {

		case 1:
			printf("Teilaufgabe 1 (Enums fuer Farben) wird ausgefuehrt..\n");
			Teilaufgabe_1();
			break;
		case 2:
			printf("Teilaufgabe 2 (Struct fuer einen Vektor erstellen) wird ausgefuehrt..\n");
			Teilaufgabe_2();
			break;
		default:
			printf("Ungueltige Eingabe, erneut versuchen:\n");
			break;
		}
	} while (1);

	return 0;  // Return a valid exit code
}