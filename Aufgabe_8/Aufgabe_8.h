#pragma once
struct
enum color_t {
	Rot = 0,
	Lila,
	Gelb,
	Blau,
	Grau
};
void Teilaufgabe_1();
void Teilaufgabe_2();
color_t color_from_string(const char* s);
const char* color_to_string(color_t	color);