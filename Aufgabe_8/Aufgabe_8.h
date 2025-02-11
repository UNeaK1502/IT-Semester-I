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
const char* color_to_string(color_t	color);
//Aufgabe 8.2
typedef struct {
	float x;
	float y;
	float z;
}vec2_t;
void getVectorInput(vec2_t* input);
void printVector(vec2_t* output);
float getScalarProduct(vec2_t vector1, vec2_t vector2);
float getVectorAbsolut(vec2_t vector);
void calculateVectorAngle(vec2_t vector1, vec2_t vector2);
void mathOpsVectors(vec2_t vector1, vec2_t vector2);