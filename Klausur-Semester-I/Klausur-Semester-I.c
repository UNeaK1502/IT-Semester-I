#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MATRIKELNR_LEN		8
#define MAX_INPUT_LEN		10
#define MAX_STRING_LEN		100

typedef struct {
	const char* neunzehn[20];
	const char* zehner[10];
	const char* potenzen[4];
}zahlenWoerter;
zahlenWoerter woerter = {
	.neunzehn = { "null","ein", "zwei", "drei", "vier", "fuenf", "sechs", "sieben", "acht", "neun" ,"zehn",
	"elf", "zwoelf", "dreizehn", "vierzehn", "fuenfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn" },
	.zehner = {"placeholder","placeholder","zwanzig", "dreissig", "vierzig", "fuenfzig", "sechzig", "siebzig", "achtzig", "neunzig" },	//Platzhalter für 0 und 1
	.potenzen = { "hundert", "tausend", "million", "milliarde"},
};
typedef enum {
	milliarden = 0,
	hundertmillionen = 1,
	zehnmillionen = 2,
	millionen = 3,
	hundertausend = 4,
	zehntausend = 5,
	tausend = 6,
	hundert = 7,
	zehn = 8,
	einer = 9
}zahlen_index;

int matrikelnr(char* nr, int maxlen);
int num2text(char* text, int maxlen, int num);
void printOutput(char output[]);
void getInputChars(char* input, int maxlen);
//Extra
int smallnum2text(char* text, int maxlen, int num, int digits);	//Sonderfall eine Million, ein Tausend

//Hauptprogramm

int main() {
	char outputText[MAX_STRING_LEN] = { 0 };
	int input = -1;
	while (1) {						//Zum testen mehrere eingaben, andere While schleife
		//while (input < 0) {
		printf("Zahl eingeben: ");
		scanf_s("%d", &input);

		if (num2text(outputText, MAX_STRING_LEN, input) == -1) {
			printf("Die Umwandlung war fehlerhaft.\n");
		}
		else {
			//Text printen
			printf("%s\nPress any key to continue . . .", outputText);
		}
		//Text zurücksetzen
		memset(outputText, 0, MAX_STRING_LEN);
	}
	return 0;
}
int num2text(char* text, int maxlen, int num) {
	//Zahl in Array umwandeln
	int zahlenArray[MAX_INPUT_LEN] = { 0 };
	int noDigits = 0;				//Anzahl der Digits
	int backup = num;				//Wird benötigt, um die Zahl zu sichern
	noDigits = num ? 0 : 1;			//Wenn num 0 ist (false), dann gibt es eine Digit. Wenn num nicht 0 ist, dann werden die Stellen über den nächsten Loop ermittelt

	while (backup != 0) {
		backup /= 10;
		noDigits++;
	}
	//Tausend ausgeben
	if (smallnum2text(text, maxlen, num, noDigits) == -1) return -1;	//Zahlen von -9999 bis 9999 ausgeben
	else return 0;
}
/// <summary>
/// 9999 bis -9999 ausgeben
/// </summary>
/// <param name="text">Array für Ausgabetext</param>
/// <param name="maxlen">maximale Länge des Ausgabetexts</param>
/// <param name="num">Zahl die konvertiert wird</param>
/// <param name="digits">stellen der Zahl</param>
/// <returns></returns>
int smallnum2text(char* text, int maxlen, int num, int digits) {
	//Zahl in Array umwandeln
	int zahlenArray[MAX_INPUT_LEN] = { 0 };
	int noDigits = 0;				//Anzahl der Digits
	int backup = num;				//Wird benötigt, um die Zahl zu sichern
	noDigits = num ? 0 : 1;			//Wenn num 0 ist (false), dann gibt es eine Digit. Wenn num nicht 0 ist, dann werden die Stellen über den nächsten Loop ermittelt

	//Edge - Cases
	if (num == 0) {
		if (strlen(text) + strlen("null") >= maxlen) return -1;
		strcat_s(text, maxlen, "null");
	}
	else if (num < 0) {
		if (strlen(text) + strlen("minus ") >= maxlen) return -1;
		strcat_s(text, maxlen, "minus ");
		num *= -1;
	}
	while (backup != 0) {

		backup /= 10;
		noDigits++;
	}
	backup = num;			//num für Berechnungen zwischenspeichern
	for (int i = MAX_INPUT_LEN - 1; i >= 0; i--) {
		zahlenArray[i] = backup % 10;
		backup /= 10;
	}

	//Milliarden ausgeben
	if (zahlenArray[milliarden] > 0) {
		if (strlen(text) + strlen(woerter.potenzen[3]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.potenzen[3]);
	}
	//Hundertmillionen ausgeben
	if (zahlenArray[hundertmillionen] > 0) {
		if (strlen(text) + strlen(woerter.potenzen[0]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.potenzen[0]);
	}
	//Zehnmillionen ausgeben	
	if (zahlenArray[zehnmillionen] > 0) {
		if (strlen(text) + strlen(woerter.potenzen[2]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.potenzen[2]);
	}
	//Millionen ausgeben
	if (zahlenArray[millionen] > 0) {
		if (strlen(text) + strlen(woerter.potenzen[1]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.potenzen[1]);
	}

	//Tausender Rewrite - Zahlenbereich 1000-99000 - passt sehr wahrscheinlich
	if (zahlenArray[hundertausend] != 0 || zahlenArray[zehntausend] != 0 || zahlenArray[tausend] != 0) {
		if (zahlenArray[hundertausend] != 0) {
			//Zahlenbereich 100000-900000 - passt
			if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[hundertausend]]) + strlen(woerter.potenzen[0]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[hundertausend]]);	//Wert des Hundertausenders anheften
			strcat_s(text, maxlen, woerter.potenzen[0]);							//Hundert anheften
		}
		if (zahlenArray[zehntausend] == 0 && zahlenArray[tausend] != 0) {
			//Zahlenbereich 1000-9000		
			if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[tausend]]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[tausend]]);

		}
		else if (zahlenArray[zehntausend] == 1) {
			//Zahlenbereich 10000-19000
			if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[tausend] + 10]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[tausend] + 10]);
		}
		else if (zahlenArray[zehntausend] > 1) {
			//Zahlenbereich 20000-99000
			if (zahlenArray[tausend] == 0) {
				//30t,20t usw abfangen
				if (strlen(text) + strlen(woerter.zehner[zahlenArray[zehntausend]]) >= maxlen) return -1;
				strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehntausend]]);
			}
			//Tausender überprüfen
			else if (zahlenArray[tausend] > 0)
			{
				//Zahlen 31t,32t,33t
				if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[tausend]]) + strlen("und") + strlen(woerter.zehner[zahlenArray[zehn]]) >= maxlen) return -1;
				strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[tausend]]);	//Einer printen
				strcat_s(text, maxlen, "und");
				strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehntausend]]);	//Zehner printen
			}
		}
		//Prefix -tausend hinzufügen
		if (strlen(text) + strlen(woerter.potenzen[1]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.potenzen[1]);
	}

	//Hunderter ausgeben - passt
	if (zahlenArray[hundert] != 0) {
		if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[hundert]]) + strlen(woerter.potenzen[0]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[hundert]]);			//Fügt ein/zwei/drei hinzu
		strcat_s(text, maxlen, woerter.potenzen[0]);							//Fügt hundert hinzu
	}
	//Zehner und Einer ausgeben
	//Wenn Zehner 1 ist, dann 10-19 ausgeben - passt
	if (zahlenArray[zehn] == 1) {
		if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[einer] + 10]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[einer] + 10]);
	}
	//Ansonsten Zahlenbereich 20-99
	else if (zahlenArray[zehn] > 1) {
		if (zahlenArray[einer] == 0) {
			//30,20 usw abfangen
			if (strlen(text) + strlen(woerter.zehner[zahlenArray[zehn]]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehn]]);
		}
		//Einer überprüfen
		else if (zahlenArray[einer] == 1) //passt
		{
			//Zahlen wie 31, 21 usw abfangen
			if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[einer]]) + strlen("und") + strlen(woerter.zehner[zahlenArray[zehn]]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[einer]]);
			strcat_s(text, maxlen, "und");
			strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehn]]);	//Zehner printen
		}
		else if (zahlenArray[einer] > 1)	//passt
		{
			//Zahlen 33,34,34
			if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[einer]]) + strlen("und") + strlen(woerter.zehner[zahlenArray[zehn]]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[einer]]);	//Einer printen
			strcat_s(text, maxlen, "und");
			strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehn]]);	//Zehner printen
		}
	}
	else {
		//Ansonsten Zehner und Einer ausgeben
		//Zahlenbereich 100-119
		//Sonderfall 0-9 "und"
		if (zahlenArray[zehn] == 0 && zahlenArray[einer] != 0 && num > 100) {
			if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[einer]]) >= maxlen) return -1;
			//strcat_s(text, maxlen, "und");
			strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[einer]]);
			if (zahlenArray[zehn] == 0 && zahlenArray[einer] == 1) {		//Prüfen ob 01 am Ende steht - 11 wird ausgenommen
				if (strlen(text) + strlen("s") >= maxlen) return -1;
				strcat_s(text, maxlen, "s");								//"s" für eins anhängen	
			}
		}
		else if (zahlenArray[einer] != 0) {		//Breakpoint gesetzt, aber wahrscheinlich wird dieser Code nie wieder erreicht, durch entfall von "und"
			if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[einer]]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[einer]]);
		}
	}
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