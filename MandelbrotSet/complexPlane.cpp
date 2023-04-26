#include "complexPlane.h"

ComplexPlane::ComplexPlane(float aspectRatio)
{
	/*Store the aspectRatio into m_aspectRatio
	setSize of the m_view variable to BASE_WIDTH, -BASE_HEIGHT * m_aspectRatio
	Negative size for the height will invert the vertical axis
	setCenter of the m_view variable to 0.0, 0.0
	Set m_zoomCount to 0*/
}

void ComplexPlane::zoomIn()
{
	/*Increment m_zoomCount
	Set a local variable for the x size to BASE_WIDTH * (BASE_ZOOM to the m_ZoomCount power)
	Set a local variable for the y size to BASE_HEIGHT * m_aspectRatio * (BASE_ZOOM to the m_ZoomCount power)
	setSize in m_view to the new size*/
}

void ComplexPlane::zoomOut()
{
	/*Same as zoomIn, just decrement m_zoomCount instead of incrementing it*/
}

void ComplexPlane::setCenter(vector<Vector2F> coord)
{
	/*setCenter for m_view to the given coordinate*/
}

void ComplexPlane::setMouseLocation(vector<Vector2F> coord)
{
	/*Store the given value in the m_mouseLocation variable*/
}

void ComplexPlane::loadText(Text& text)
{
	/*Use a stringstream and the corresponding member variables to create the following output:
	Mandelbrot Set
	Center: (0,0)
	Cursor: (-1.05313, 0.828125)
	Left-click to Zoom in
	Right-click ot Zoom out*/
}