#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MATRIKELNR_LEN		8
#define MAX_INPUT_LEN		4
#define MAX_STRING_LEN		100

typedef struct {
	const char* neunzehn[20];
	const char* zehner[9];
	const char* hunderter[1];
}zahlenWoerter;
zahlenWoerter woerter = {
	.neunzehn = { "null","eins", "zwei", "drei", "vier", "fuenf", "sechs", "sieben", "acht", "neun" ,"zehn",
	"elf", "zwoelf", "dreizehn", "vierzehn", "fuenfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn" },
	.zehner = {"zwanzig", "dreissig", "vierzig", "fuenfzig", "sechzig", "siebzig", "achtzig", "neunzig" },
	.hunderter = { "hundert" },
};

int matrikelnr(char* nr, int maxlen);
int num2text(char* text, int maxlen, int num);
void printOutput(char output[]);
void getInputChars(char* input, int maxlen);
//Extra
//int smallnum2text(char* text, int maxlen, int num,int digits);	//Sonderfall eine Million, ein Tausend

//Hauptprogramm

int main() {
	char outputText[MAX_STRING_LEN] = { 0 };
	int input = 0;
	while (1) {
		printf("Zu konvertierende Zahl eingeben:\n");
		scanf_s("%d", &input);
		num2text(outputText, MAX_INPUT_LEN, input);
		//Text zurücksetzen
		memset(outputText, 0, MAX_STRING_LEN);
	}
	return 0;
}
int num2text(char* text, int maxlen, int num) {
	//Zahl in Array umwandeln
	int zahlenArray[MAX_INPUT_LEN];
	int backup = num;				//Wird benötigt, um die Zahl zu sichern
	for (int i = maxlen - 1; i >= 0; i--) {
		zahlenArray[i] = backup % 10;
		backup /= 10;
	}
	//Edge -Cases
	if (num == 0) {
		strcat_s(text, MAX_STRING_LEN, "null");
	}
	//Tausender ausgeben - paschd
	if (zahlenArray[0] != 0) {
		if (zahlenArray[0] == 1) {
			strcat_s(text, MAX_STRING_LEN, "eintausend");
		}
		else {
			strcat_s(text, MAX_STRING_LEN, woerter.neunzehn[zahlenArray[0]]);
			strcat_s(text, MAX_STRING_LEN, "tausend");
		}
	}
	//Hunderter ausgeben - paschd
	if (zahlenArray[1] != 0) {
		if (zahlenArray[1] == 1) {
			strcat_s(text, MAX_STRING_LEN, "einhundert");
		}
		else {
			strcat_s(text, MAX_STRING_LEN, woerter.neunzehn[zahlenArray[1]]);
			strcat_s(text, MAX_STRING_LEN, woerter.hunderter[0]);
		}
	}
	//Zehner und Einer ausgeben
		//Wenn Zehner 1 ist, dann 10-19 ausgeben
	if (zahlenArray[2] == 1) {
		strcat_s(text, MAX_STRING_LEN, woerter.neunzehn[zahlenArray[3] + 10]);
	}
	//Ansonsten Zahlenbereich 20-99
	else if (zahlenArray[2] > 1) {		
		if (zahlenArray[3] == 0){
			//30,20 usw abfangen
			strcat_s(text, MAX_STRING_LEN, woerter.zehner[zahlenArray[2] - 2]);
		}
		else if (zahlenArray[3] == 1) {
			//Zahlen wie 31, 21 usw abfangen
			strcat_s(text, MAX_STRING_LEN, "ein");
			strcat_s(text, MAX_STRING_LEN, "und");
			strcat_s(text, MAX_STRING_LEN, woerter.zehner[zahlenArray[2] - 2]);	//Zehner printen
		}else if (zahlenArray[3] > 1) {
			//Zahlen 33,34,34
			strcat_s(text, MAX_STRING_LEN, woerter.neunzehn[zahlenArray[3]]);	//Einer printen
			strcat_s(text, MAX_STRING_LEN, "und");
			strcat_s(text, MAX_STRING_LEN, woerter.zehner[zahlenArray[2] - 2]);	//Zehner printen
		}
	}
	else {
		//Ansonsten Zehner und Einer ausgeben
		//Zahlenbereich 100-119
		//Sonderfall 0-9 "und"
		if (zahlenArray[2] == 0 && zahlenArray[3] != 0 && num > 10) {

			strcat_s(text, MAX_STRING_LEN, "und");
			strcat_s(text, MAX_STRING_LEN, woerter.neunzehn[zahlenArray[3]]);
		}
		else if(zahlenArray[3]!= 0) {
			strcat_s(text, MAX_STRING_LEN, woerter.neunzehn[zahlenArray[3]]);
		}
	}

	printf("%s\n", text);
	return 0;
}

/// <summary>
/// Methode zum Einlesen und prüfen der Matrikelnummer
/// </summary>
/// <param name="nr"></param>
/// <param name="maxlen"></param>
/// <returns></returns>
int matrikelnr(char* nr, int maxlen) {
	char matrNr[MATRIKELNR_LEN] = { "5635349" };
	if (strlen(matrNr) < maxlen) {
		//Wenn eingegebene Matrikelnummer kleiner als 8 ist, dann Matrikelnr schreiben und 0 zurückgeben
		strcpy_s(nr, maxlen, matrNr);
		printf("Matrikelnummer: %s\n", nr);
		return 0;
	}
	else {
		printf("Fehler: Matrikelnummer zu lang\n");
		return -1;
	}
}
void getInputChars(char* input, int maxlen) {
	scanf_s("%s", input, maxlen);
}
void printOutput(char output[]) {
	printf("%s", output);
}