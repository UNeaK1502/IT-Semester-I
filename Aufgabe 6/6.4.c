#include <stdio.h>

//Datentyp int damit ein "true"/"false" zurückgegeben werden kann

int convertStringToUInt(char input[], unsigned int *output) {
	//Solange den Array durchlaufen bis NULL kommt
	for (size_t i = 0; input[i] != '\0'; i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			//Wert an Adresse von output wird mit 10 multipliziert um dezimal eine Stelle nach links zu shiften
			//Vom i-ten Char wird 0x30 bzw '0' abgezogen -> char 3 entspricht 0x33. 0x30 abgezogen entspricht 3.
			*output =  *output * 10 + input[i] - '0';
		}
		else {
			//Es wurde ein Zeichen gefunden, welches keine Zahl ist
			return 0;
		}
	}
	//Erfolgreiche Konvertierung
	return 1;
}