char digit2hex(int digit) {
	if (digit < 10)
	{
		return digit + '0';
	}
	else if (digit >= 10 && digit <= 15)
	{
		return digit - 10 + 'A';
	}
}