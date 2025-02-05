#include <stdio.h>
#include "7.1.h"
#include "7.2.h"

#define LENGTH_CHAR_ARRAY 100

void Teilaufgabe_1() {
	char array[LENGTH_CHAR_ARRAY];
	getInputChars(array);
	strreverse(array);
	printOutput(array);
}
void Teilaufgabe_2() {
	char array[LENGTH_CHAR_ARRAY];
	getInputChars(array);
	if (checkPalindrome(array)) {
		printf("%s ist ein Palindrom", array);
	}
	else {
		printf("%s ist kein Palindrom", array);
	}
}
void Teilaufgabe_3() {

}