#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <complex>
#include <iostream>

class ComplexPlane
{
public:
	ComplexPlane(float aspectRatio);
	void zoomIn();
	void zoomOut();
	void setCenter(vector<Vector2f> coord);
	View getView();
	void setMouseLocation(vector<Vector2f> coord);
	void loadText(Text& text);
	size_t countIterations(vector<Vector2f> coord);
	void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b);
private:
	vector<Vector2f> m_mouseLocation;
	View m_view;
	int m_zoomCount;
	float m_aspectRatio;
};

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;