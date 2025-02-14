#include <stdio.h>
#define LENGTH_CHAR_ARRAY	100

void getMatrInputChars(char input[]) {
	printf("Bitte geben Sie einen String ein:\t");
	scanf_s("%s", input, LENGTH_CHAR_ARRAY);				//Als Buffergroesse wird die maximal Länge vom Char-Array genommen
}
void umwandeln(char input[], char output[]) {
	for (size_t i = 0; i < LENGTH_CHAR_ARRAY; i++)
	{
		//Da chars verwendet werden, muss kein Hex-Wert verwendet werden 0x61 (a) bis 0x7A (z)
		if (input[i] >= 'a' && input[i] <= 'z') {
			output[i] = input[i] - 32;						//32 oder 0x20 ist die Differenz zwischen Groß- und Kleinbuchstaben
		}
		//0x41 (A) bis 0x5A (Z)
		else if (input[i] >= 'A' && input[i] <= 'Z') {
			output[i] = input[i] + 32;
		}
		else {
			output[i] = input[i];							//Für alles was keiner der 26 Buchstaben ist
		}
	}
}
void printOutput(char output[]) {
	printf("Der umgewandelte String lautet:\t%s\n", output);
}