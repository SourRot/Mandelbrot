#include "complexPlane.h"

ComplexPlane::ComplexPlane(float aspectRatio)
{
	/*Store the aspectRatio into m_aspectRatio
		DONE
	setSize of the m_view variable to BASE_WIDTH, -BASE_HEIGHT * m_aspectRatio
	Negative size for the height will invert the vertical axis
		DONE
	setCenter of the m_view variable to 0.0, 0.0
		DONE
	Set m_zoomCount to 0
		DONE*/
	m_aspectRatio = aspectRatio;
	m_view.setSize(Vector2f(BASE_WIDTH, -BASE_HEIGHT * m_aspectRatio));
	m_view.setCenter(Vector2f(0.f, 0.f));
	m_zoomCount = 0;

}

void ComplexPlane::zoomIn()
{
	/*Increment m_zoomCount
		DONE
	Set a local variable for the x size to BASE_WIDTH * (BASE_ZOOM to the m_ZoomCount power)
		DONE
	Set a local variable for the y size to BASE_HEIGHT * m_aspectRatio * (BASE_ZOOM to the m_ZoomCount power)
		DONE
	setSize in m_view to the new size
		DONE*/
	m_zoomCount++;
	float xSize = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
	float ySize = BASE_WIDTH * m_aspectRatio * (pow(BASE_ZOOM, m_zoomCount));
	m_view.setSize(xSize, ySize);
}

void ComplexPlane::zoomOut()
{
	/*Same as zoomIn, just decrement m_zoomCount instead of incrementing it
		DONE*/
	m_zoomCount--;
	float xSize = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
	float ySize = BASE_WIDTH * m_aspectRatio * (pow(BASE_ZOOM, m_zoomCount));
	m_view.setSize(xSize, ySize);
}

void ComplexPlane::setCenter(Vector2f coord)
{
	/*setCenter for m_view to the given coordinate
		DONE*/
	m_view.setCenter(coord.x, coord.y);
}

void ComplexPlane::setMouseLocation(Vector2f coord)
{
	/*Store the given value in the m_mouseLocation variable
		DONE*/
	m_mouseLocation = coord;
}

void ComplexPlane::loadText(Text& text)
{
	/*Use a stringstream and the corresponding member variables to create the following output:
	Mandelbrot Set
	Center: (0,0)
	Cursor: (-1.05313, 0.828125)
	Left-click to Zoom in
	Right-click to Zoom out*/

}

size_t ComplexPlane::countIterations(Vector2f coord)
{
	/*Count the number of iterations of the set for the given coordinate as specified above*/
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& nb)
{
	/*Map the given iteration count to an r,g,b color and assign the given reference variables
	You are free to create and experiment with your own color scheme
	You may want to start with gray scale, where r,g,b are always the same value in the range [0,255]
	I used the following strategy:
	At MAX_ITER I colored the pixel black {0,0,0}
	Between [0 : MAX_ITER) I divided the colors into 5 regions:
	Purple / blue for low iteration counts
	Turquoise
	Green
	Yellow
	Red for high iteration counts
	You can experiment with HSV color mapping to see which values to assign for each region
	Set S to 100% and V to 50% and slide the H*/
}