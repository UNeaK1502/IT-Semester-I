//Libraries

#include <stdio.h>
#include "Aufgabe_4.h"

//Hauptprogramm

int main()
{
	printf("Welche Teilaufgabe soll bearbeitet werden?\n");
	do {
		int inputTask = 0;
		scanf_s("%d", &inputTask);

		switch (inputTask) {

		case 1:
			printf("Teilaufgabe 1 (Quadratische Gleichungenwird ausgefuehrt..\n");
			Teilaufgabe_1();
			break;
		case 2:
			printf("Teilaufgabe 2 (Polar 2 Kartesisch) wird ausgefuehrt..\n");
			Teilaufgabe_2();
			break;
		case 3:
			printf("Teilaufgabe 3 (Widerstand 2 Farbcode) wird ausgefuehrt..\n");
			Teilaufgabe_3();
			break;
		case 4:
			printf("Teilaufgabe 4 (Zahl 2 Rows) wird ausgefuehrt..\n");
			Teilaufgabe_4();
			break;
		case 5:
			printf("Teilaufgabe 5 (Digit 2 Bin) wird ausgefuehrt..\n");
			Teilaufgabe_5();
			break;
		case 6:
			printf("Teilaufgabe 6 (Digit 2 Hex) wird ausgefuehrt..\n");
			Teilaufgabe_6();
			break;
		case 7:
			printf("Teilaufgabe 7 wird ausgefuehrt..\n");
			Teilaufgabe_7();
			break;
		case 8:
			printf("Teilaufgabe 8 wird ausgefuehrt..\n");
			Teilaufgabe_8();
			break;
		default:
			printf("Ungueltige Eingabe, erneut versuchen:\n");
			break;
		}
	} while (1);

	return 0;  // Return a valid exit code
}