#pragma once
#ifndef COMPLEX_PLANE
#define COMPLEX_PLANE
#include <sstream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>

using namespace sf;
using namespace std;

class ComplexPlane
{
public:
	inline ComplexPlane(float aspectRatio);
	inline void zoomIn();
	inline void zoomOut();
	inline void setCenter(Vector2f coord);
	inline View getView();
	inline void setMouseLocation(Vector2f coord);
	inline void loadText(Text& text);
	inline size_t countIterations(Vector2f coord);
	inline void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b);
private:
	Vector2f m_mouseLocation;
	View m_view;
	int m_zoomCount;
	float m_aspectRatio;
};

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

#endif