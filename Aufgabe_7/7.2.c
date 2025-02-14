#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LENGTH_CHAR_ARRAY 100

int checkPalindrome(char* array) {
	char reversedArray[LENGTH_CHAR_ARRAY];
	//Destination String, source String, length of source string
	memcpy(reversedArray, array, LENGTH_CHAR_ARRAY);
	strreverse(reversedArray);	//String umdrehen

	for (size_t i = 0; i < LENGTH_CHAR_ARRAY; i++)
	{
		if (tolower(reversedArray[i]) != tolower(array[i])) {
			return 0;	//Wenn ein Zeichen nicht übereinstimmt, dann ist es kein Palindrom
		}
	}
	return 1;
}
