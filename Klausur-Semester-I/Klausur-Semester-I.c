#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MATRIKELNR_LEN		8			//L�nge der Matrikelnummer
#define MAX_INPUT_LEN		10			//Maximale L�nge der Eingabe
#define MAX_STRING_LEN		90			//String der die Textl�nge begrenzt

typedef struct {
	const char* neunzehn[20];
	const char* zehner[10];
	const char* potenzen[4];
}zahlenWoerter;
zahlenWoerter woerter = {
	.neunzehn = { "null","ein", "zwei", "drei", "vier", "fuenf", "sechs", "sieben", "acht", "neun" ,"zehn",
	"elf", "zwoelf", "dreizehn", "vierzehn", "fuenfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn" },								//die ersten 20 Zahlen weil 6/7 mit 16/17 & 60/70 bl�d sind
	.zehner = {"placeholder","placeholder","zwanzig", "dreissig", "vierzig", "fuenfzig", "sechzig", "siebzig", "achtzig", "neunzig" },	//Platzhalter f�r 0 und 1
	.potenzen = { "hundert", "tausend", "million", "milliarde"},
};
typedef enum {
	milliarden = 0,
	hundertmillionen = 1,
	zehnmillionen = 2,
	millionen = 3,
	hunderttausend = 4,
	zehntausend = 5,
	tausend = 6,
	hundert = 7,
	zehn = 8,
	einer = 9
}zahlen_index;		//Enum zur �bersichtlichkeit

//Methoden Deklaration

int matrikelnr(char* nr, int maxlen);
int num2text(char* text, int maxlen, int num);
int checkStrCat(char* text, int maxlen, const char* str);			//Hilfsfunktion f�r strcat
//Extra
int smallnum2text(char* text, int maxlen, int num, int digits);

//Hauptprogramm

int main() {
	char outputText[MAX_STRING_LEN] = { 0 };
	int input = NULL;
	int watchdog = 0;		// 0 = fehlerhafte Eingabe, 1 = richtige Eingabe
	while (watchdog == 0) {
		printf("Zahl eingeben: ");
		watchdog = scanf_s("%d", &input);
		if (watchdog == 0) {			
			while (getchar() != '\n');	//Buffer leeren, um Endlosschleife zu verhindern
		} else {
			if (num2text(outputText, MAX_STRING_LEN, input) == -1) {
				printf("Die Umwandlung war fehlerhaft.\n");				//Fehler wenn Textl�nge zu lang f�r MAX_STRING_LEN ist
			} else {
				// Text printen
				printf("%s\nPress any key to continue . . .", outputText);
			}
		}
	}
	return 0;
}

int num2text(char* text, int maxlen, int num) {
	int zahlenArray[MAX_INPUT_LEN] = { 0 };
	int noDigits = 0;				//Anzahl der Digits
	int backup = num;				//Wird ben�tigt, um die Zahl zu sichern
	noDigits = num ? 0 : 1;			//Wenn num 0 ist (false), dann gibt es eine Digit. Wenn num nicht 0 ist, dann werden die Stellen �ber den n�chsten Loop ermittelt

	while (backup != 0) {
		backup /= 10;
		noDigits++;
	}
	if (smallnum2text(text, maxlen, num, noDigits) == -1) return -1;	//Zahlen von -9999 bis 9999 ausgeben
	else return 0;
}
/// <summary>
/// 9999 bis -9999 ausgeben
/// </summary>
/// <param name="text">Array f�r Ausgabetext</param>
/// <param name="maxlen">maximale L�nge des Ausgabetexts</param>
/// <param name="num">Zahl die konvertiert wird</param>
/// <param name="digits">stellen der Zahl</param>
/// <returns></returns>
int smallnum2text(char* text, int maxlen, int num, int digits) {
	
	int zahlenArray[MAX_INPUT_LEN] = { 0 };
	int backup = num;				//Wird ben�tigt, um die Zahl zu sichern
	//Edge - Cases
	if (num == 0) {
		if (checkStrCat(text, maxlen, woerter.neunzehn[0]) == -1) return -1;
		/*if (strlen(text) + strlen("null") >= maxlen) return -1;
		strcat_s(text, maxlen, "null");*/
	}
	else if (num < 0) {
		if (strlen(text) + strlen("minus ") >= maxlen) return -1;
		strcat_s(text, maxlen, "minus ");
		num *= -1;
	}

	backup = num;			//num f�r Berechnungen zwischenspeichern
	//Zahl in Array umwandeln
	for (int i = MAX_INPUT_LEN - 1; i >= 0; i--) {
		zahlenArray[i] = backup % 10;
		backup /= 10;
	}

	//Milliarden ausgeben
	if (digits > 9) {
		if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[milliarden]]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[milliarden]]);
		if (zahlenArray[milliarden] == 1) {
			//Gendern wenn 1 Milliarde
			if (checkStrCat(text, maxlen, "e") == -1) return -1;/*
			if (strlen(text) + strlen("e") >= maxlen) return -1;
			strcat_s(text, maxlen, "e");*/
			//Sonderfall X01.XXX.XXX.XXX muss nicht behandelt werden, da eine Zahl gr��er 4.3 Mrd mit uInt nicht m�glich ist
		}
		//Postfix -milliarde hinzuf�gen
		if (checkStrCat(text, maxlen, woerter.potenzen[3]) == -1) return -1;
		/*
		if (strlen(text) + strlen(woerter.potenzen[3]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.potenzen[3]);*/
		if (zahlenArray[milliarden] > 1) {
			//Pluralform anh�ngen
			if (checkStrCat(text, maxlen, "n") == -1) return -1;
			/*if (strlen(text) + strlen("n") >= maxlen) return -1;
			strcat_s(text, maxlen, "n");*/
		}
	}
	//Millionen - Zahlenbereich 1.000.000-999.000.000
	if (zahlenArray[hundertmillionen] != 0 || zahlenArray[zehnmillionen] != 0 || zahlenArray[millionen] != 0) {
		if (zahlenArray[hundertmillionen] != 0) {
			//Zahlenbereich 100.000.000-900.000.000
			if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[hundertmillionen]]) == -1) return -1;
			if (checkStrCat(text, maxlen, woerter.potenzen[0]) == -1) return -1;
			//if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[hundertmillionen]]) + strlen(woerter.potenzen[0]) >= maxlen) return -1;
			//strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[hundertmillionen]]);	//Wert des Hundertausenders anheften
			//strcat_s(text, maxlen, woerter.potenzen[0]);							//Hundert anheften
		}
		if (zahlenArray[zehnmillionen] == 0 && zahlenArray[millionen] != 0) {
			//Zahlenbereich 1.000.000-9.000.000		
			if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[millionen]]) == -1) return -1;
			//if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[millionen]]) >= maxlen) return -1;
			//strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[millionen]]);
			if (zahlenArray[hundertmillionen] != 0 && zahlenArray[millionen] == 1) {
				//S anh�ngen wenn X01.XXX.XXX
				if (checkStrCat(text, maxlen, "s") == -1) return -1;
				//if (strlen(text) + strlen("s") >= maxlen) return -1;
				//strcat_s(text, maxlen, "s");
			}
			else if (zahlenArray[millionen] == 1) {
				//e anh�ngen wenn 001.XXX.XXX
				if (checkStrCat(text, maxlen, "e") == -1) return -1;
				/*if (strlen(text) + strlen("e") >= maxlen) return -1;
				strcat_s(text, maxlen, "e");*/
			}
		}
		else if (zahlenArray[zehnmillionen] == 1) {
			//Zahlenbereich 10.000.000-19.000.000
			if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[millionen] + 10]) == -1) return -1;
			//if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[millionen] + 10]) >= maxlen) return -1;
			//strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[millionen] + 10]);
		}
		else if (zahlenArray[zehnmillionen] > 1) {
			//Zahlenbereich 20.000.000-99.000.000
			if (zahlenArray[millionen] == 0) {
				//30m,20m usw abfangen
				if (checkStrCat(text, maxlen, woerter.zehner[zahlenArray[zehnmillionen]]) == -1) return -1;
				/*if (strlen(text) + strlen(woerter.zehner[zahlenArray[zehnmillionen]]) >= maxlen) return -1;
				strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehnmillionen]]);*/

			}
			//millionen �berpr�fen
			else if (zahlenArray[millionen] > 1)
			{
				//Zahlen 31m,32m,33m
				if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[millionen]]) == -1) return -1;
				if (checkStrCat(text, maxlen, "und") == -1) return -1;
				if (checkStrCat(text, maxlen, woerter.zehner[zahlenArray[zehnmillionen]]) == -1) return -1;
				//if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[millionen]]) + strlen("und") + strlen(woerter.zehner[zahlenArray[zehn]]) >= maxlen) return -1;
				//strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[millionen]]);	//Einer printen
				//strcat_s(text, maxlen, "und");
				//strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehnmillionen]]);	//Zehner printen
			}
		}
		//Postfix -millionen hinzuf�gen - plural million/millionen abfangen - TODO
		//million wenn = 001
		//millionen wenn > 001
		if (zahlenArray[hundertmillionen] == 0 && zahlenArray[zehnmillionen] == 0 && zahlenArray[millionen] == 1) {
			if (checkStrCat(text, maxlen, woerter.potenzen[2]) == -1) return -1;
			//if (strlen(text) + strlen(woerter.potenzen[2]) >= maxlen) return -1;
			//strcat_s(text, maxlen, woerter.potenzen[2]);	//Million anh�ngen
		}
		else if (zahlenArray[hundertmillionen] != 0 || zahlenArray[zehnmillionen] != 0 || zahlenArray[millionen] > 1) {
			if (checkStrCat(text, maxlen, woerter.potenzen[2]) == -1) return -1;
			if (checkStrCat(text, maxlen, "en") == -1) return -1;
			//if (strlen(text) + strlen(woerter.potenzen[2]) + strlen("en") >= maxlen) return -1;
			//strcat_s(text, maxlen, woerter.potenzen[2]);	//Million anh�ngen
			//strcat_s(text, maxlen, "en");					//Pluralform anh�ngen
		}
	}

	//Tausender - Zahlenbereich 1000-999000
	if (zahlenArray[hunderttausend] != 0 || zahlenArray[zehntausend] != 0 || zahlenArray[tausend] != 0) {
		if (zahlenArray[hunderttausend] != 0) {
			//Zahlenbereich 100000-900000 - passt
			if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[hunderttausend]]) == -1) return -1;
			if (checkStrCat(text, maxlen, woerter.potenzen[0]) == -1) return -1;
			//if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[hunderttausend]]) + strlen(woerter.potenzen[0]) >= maxlen) return -1;
			//strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[hunderttausend]]);	//Wert des Hundertausenders anheften
			//strcat_s(text, maxlen, woerter.potenzen[0]);							//Hundert anheften
		}
		if (zahlenArray[zehntausend] == 0 && zahlenArray[tausend] != 0) {
			//Zahlenbereich 1000-9000	
			if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[tausend]]) == -1) return -1;
			/*if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[tausend]]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[tausend]]);*/
			if (zahlenArray[hunderttausend] != 0 && zahlenArray[tausend] == 1) {
				//S anh�ngen wenn X01000
				if (checkStrCat(text, maxlen, "s") == -1) return -1;
				/*if (strlen(text) + strlen("s") >= maxlen) return -1;
				strcat_s(text, maxlen, "s");*/
			}
		}
		else if (zahlenArray[zehntausend] == 1) {
			//Zahlenbereich 10000-19000
			if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[tausend] + 10]) == -1) return -1;
			/*if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[tausend] + 10]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[tausend] + 10]);*/
		}
		else if (zahlenArray[zehntausend] > 1) {
			//Zahlenbereich 20000-99000
			if (zahlenArray[tausend] == 0) {
				//30t,20t usw abfangen
				if (checkStrCat(text, maxlen, woerter.zehner[zahlenArray[zehntausend]]) == -1) return -1;
				/*if (strlen(text) + strlen(woerter.zehner[zahlenArray[zehntausend]]) >= maxlen) return -1;
				strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehntausend]]);*/

			}
			//Tausender �berpr�fen
			else if (zahlenArray[tausend] > 1)
			{
				//Zahlen 31t,32t,33t
				if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[tausend]]) == -1) return -1;
				if (checkStrCat(text, maxlen, "und") == -1) return -1;
				if (checkStrCat(text, maxlen, woerter.zehner[zahlenArray[zehntausend]]) == -1) return -1;
				
			//	if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[tausend]]) + strlen("und") + strlen(woerter.zehner[zahlenArray[zehn]]) >= maxlen) return -1;
			//	strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[tausend]]);	//Einer printen
			//	strcat_s(text, maxlen, "und");
			//	strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehntausend]]);	//Zehner printen
			}
		}
		//Postfix -tausend hinzuf�gen
		if (checkStrCat(text, maxlen, woerter.potenzen[1]) == -1) return -1;/*
		if (strlen(text) + strlen(woerter.potenzen[1]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.potenzen[1]);*/
	}

	//Hunderter ausgeben - passt
	if (zahlenArray[hundert] != 0) {
		if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[hundert]]) == -1) return -1;
		if (checkStrCat(text, maxlen, woerter.potenzen[0]) == -1) return -1;
		//if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[hundert]]) + strlen(woerter.potenzen[0]) >= maxlen) return -1;
		//strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[hundert]]);			//F�gt ein/zwei/drei hinzu
		//strcat_s(text, maxlen, woerter.potenzen[0]);							//F�gt hundert hinzu
	}
	//Zehner und Einer ausgeben
	//Wenn Zehner 1 ist, dann 10-19 ausgeben - passt
	if (zahlenArray[zehn] == 1) {
		if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[einer] + 10]) == -1) return -1;
		/*if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[einer] + 10]) >= maxlen) return -1;
		strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[einer] + 10]);*/
	}
	//Ansonsten Zahlenbereich 20-99
	else if (zahlenArray[zehn] > 1) {
		if (zahlenArray[einer] == 0) {
			//30,20 usw abfangen
			if (checkStrCat(text, maxlen, woerter.zehner[zahlenArray[zehn]]) == -1) return -1;
			/*if (strlen(text) + strlen(woerter.zehner[zahlenArray[zehn]]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehn]]);*/
		}
		//Einer �berpr�fen
		else if (zahlenArray[einer] == 1) //passt
		{
			//Zahlen wie 31, 21 usw abfangen
			if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[einer]]) == -1) return -1;
			if (checkStrCat(text, maxlen, "und") == -1) return -1;
			if (checkStrCat(text, maxlen, woerter.zehner[zahlenArray[zehn]]) == -1) return -1;
			//if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[einer]]) + strlen("und") + strlen(woerter.zehner[zahlenArray[zehn]]) >= maxlen) return -1;
			//strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[einer]]);
			//strcat_s(text, maxlen, "und");
			//strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehn]]);	//Zehner printen
		}
		else if (zahlenArray[einer] > 1)	//passt
		{
			//Zahlen 33,34,34
			if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[einer]]) == -1) return -1;
			if (checkStrCat(text, maxlen, "und") == -1) return -1;
			if (checkStrCat(text, maxlen, woerter.zehner[zahlenArray[zehn]]) == -1) return -1;

			//if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[einer]]) + strlen("und") + strlen(woerter.zehner[zahlenArray[zehn]]) >= maxlen) return -1;
			//strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[einer]]);	//Einer printen
			//strcat_s(text, maxlen, "und");
			//strcat_s(text, maxlen, woerter.zehner[zahlenArray[zehn]]);	//Zehner printen
		}
	}
	else {
		//Ansonsten Zehner und Einer ausgeben
		//Zahlenbereich 100-119
		//Sonderfall 0-9 "und"
		if (zahlenArray[zehn] == 0 && zahlenArray[einer] != 0 && num > 100) {
			if (checkStrCat(text, maxlen, "und") == -1) return -1;
			//if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[einer]]) >= maxlen) return -1;
			////strcat_s(text, maxlen, "und");
			//strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[einer]]);
			if (zahlenArray[zehn] == 0 && zahlenArray[einer] == 1) {		//Pr�fen ob 01 am Ende steht - 11 wird ausgenommen
				if (checkStrCat(text, maxlen, "s") == -1) return -1;
				//if (strlen(text) + strlen("s") >= maxlen) return -1;
				//strcat_s(text, maxlen, "s");								//"s" f�r eins anh�ngen	
			}
		}
		else if (zahlenArray[einer] != 0) {		//Breakpoint gesetzt, aber wahrscheinlich wird dieser Code nie wieder erreicht, durch entfall von "und"
			if (checkStrCat(text, maxlen, woerter.neunzehn[zahlenArray[einer]]) == -1) return -1;
			/*if (strlen(text) + strlen(woerter.neunzehn[zahlenArray[einer]]) >= maxlen) return -1;
			strcat_s(text, maxlen, woerter.neunzehn[zahlenArray[einer]]);*/
		}
	}
	return 0;
}
/// <summary>
/// Check ob die Textl�nge zu lang ist, wenn nein, f�gt den String hinzu
/// </summary>
/// <param name="text">Ziel-String</param>
/// <param name="maxlen">Maximale L�nge vom Zielstring</param>
/// <param name="str">String der angeheftet werden soll</param>
/// <returns>-1 Wenn String zu lang ist, 0 Wenn es gepasst hat</returns>
int checkStrCat(char* text, int maxlen, const char* str) {
	if (strlen(text) + strlen(str) >= maxlen) return -1;
	strcat_s(text, maxlen, str);
	return 0;
}
/// <summary>
/// Methode zum Einlesen und pr�fen der Matrikelnummer
/// </summary>
/// <param name="nr"></param>
/// <param name="maxlen"></param>
/// <returns></returns>
int matrikelnr(char* nr, int maxlen) {
	char matrNr[MATRIKELNR_LEN] = { "5635349" };
	if (strlen(matrNr) < maxlen) {
		//Wenn eingegebene Matrikelnummer kleiner als 8 ist, dann Matrikelnr schreiben und 0 zur�ckgeben
		strcpy_s(nr, maxlen, matrNr);
		printf("Matrikelnummer: %s\n", nr);
		return 0;
	}
	else {
		printf("Fehler: Matrikelnummer zu lang\n");
		return -1;
	}
}