#pragma once
typedef enum {
	Rot,
	Lila,
	Gelb,
	Blau,
	Grau
}color_t;
void Teilaufgabe_1();
void Teilaufgabe_2();
color_t color_from_string(const char* s);
const char *color_to_string(color_t	color);