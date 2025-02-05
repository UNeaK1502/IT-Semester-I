#include <stdio.h>

#define LENGTH_CHAR_ARRAY 100


void getInputChars(char input[]) {
	printf("Bitte geben Sie einen String ein:\t");
	scanf_s("%s", input, LENGTH_CHAR_ARRAY);				//Als Buffergroesse wird die maximal Länge vom Char-Array genommen
}

void strreverse(char* s) {
	int counter = 0;
	for (size_t i = 0; i < LENGTH_CHAR_ARRAY; i++)
	{
		if (s[i] == '\0') break;
		counter++;							//Länge von String ermitteln
	}
	char copy[LENGTH_CHAR_ARRAY];
	memcpy(copy, s, LENGTH_CHAR_ARRAY);		//Inhalt kopieren

	for (size_t i = 0; i < counter; i++)
	{
		s[i] = copy[counter - 1 - i];		//Inhalt vertauschen
	}
}

void printOutput(char output[]) {
	printf("Der umgewandelte String lautet:\t%s\n", output);
}