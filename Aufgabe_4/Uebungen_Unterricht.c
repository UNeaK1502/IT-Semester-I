char reg = 0;			//0xBA

void function(unsigned char twa) {
	reg &= 0b00000001;
	reg |= twa << 1;		//Bitshift nach links weil nur 7 Bits gesetzt werden dürfen
	printf("Register %c wurde auf %c gesetzt", reg, twa);	
}