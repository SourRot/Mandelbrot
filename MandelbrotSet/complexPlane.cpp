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
	m_view.setCenter(Vector2f(0.0f, 0.0f));
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

View ComplexPlane::getView()
{
	return m_view;
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
	stringstream ss;
	

	ss << "Mandelbrot Set" << '\n'
		<< "Center: (" << m_view.getCenter().x << ", " << m_view.getCenter().y << ")" << '\n'
		<< "Cursor: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")"	//Not sure why this doesn't work ********* possibly fixed?
		<< '\n' << "Left-click to Zoom in" << '\n'
		<< "Right-click to Zoom out";
	text.setString(ss.str());

}

size_t ComplexPlane::countIterations(Vector2f coord)
{
	/*Count the number of iterations of the set for the given coordinate as specified above*/
	
	complex<double> c(coord.x, coord.y);
	complex<double> z;
	size_t iterCount = 0;
	
	/*
	The Mandelbrot set is generated by picking each point on the complex plane c = a + bi
	and iterating the formula zi + 1 = zi^2 + c where z0 = 0:
	z1 = 0 + c
	z2 = z1 * z1 + c
	z3 = z2 * z2 + c
	...
	
	If the absolute value of z never goes above 2.0, then c is considered to be part of the Madelbrot set.
	If c is part of the set, then color its corresponding pixel black.  If it is not, record 
	the number of iterations it took to grow beyond 2.0




	*/

	for (size_t i = 0; i < MAX_ITER; i++)
	{
		z = z * z + c;
		if (abs(z) > 2.0)
		{
			return i;
		}
		iterCount++;
	}

	/*while (iterCount <= MAX_ITER && abs(z) <= 2)
		{
			z = (z * z) + c;
			iterCount++;
		}*/

		return iterCount;
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{
	/*
		Map the given iteration count to an r,g,b color and assign the given reference variables
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
		Set S to 100% and V to 50% and slide the H
	*/

	if (count != MAX_ITER)
	{
		if (count > 0 && count < 50)
		{ 
			r = count * 91 / MAX_ITER;
			g = count * 23 / MAX_ITER;
			b = count * 41/ MAX_ITER;
		}
		else if (count >= 50 && count < 100)
		{
			r = count * 131 / MAX_ITER;
			g = count * 105 / MAX_ITER;
			b = count * 105 / MAX_ITER;
		}
		else if (count >= 100 && count < 150)
		{
			r = count * 204 / MAX_ITER;
			g = count * 108 / MAX_ITER;
			b = count * 94 / MAX_ITER;
		}
		else if (count >= 150 && count < 200)
		{
			r = count * 230 / MAX_ITER;
			g = count * 159 / MAX_ITER;
			b = count * 150 / MAX_ITER;
		}
		else if (count >= 200 && count < 256)
		{
			r = count * 255 / MAX_ITER;
			g = count * 255 / MAX_ITER;
			b = count * 255 / MAX_ITER;
		}
	}
	else
	{
		r = 0;
		g = 0;
		b = 0;
	}

}