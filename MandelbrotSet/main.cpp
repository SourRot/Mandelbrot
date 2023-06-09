#include "complexPlane.cpp"

// PARTNERS: Tareq Anwaryar, Rachael Greer

// Make code easier to type with "using namespace"

// I put the instructions and organized it to be readable

/*

vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvDONEvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
	Get the desktop resolution using:
		VideoMode::getDesktopMode().width;
		VideoMode::getDesktopMode().height;


	Calculate the aspect ratio of the monitor
		height / width
		Our complex plane needs to know this so the plane is not distorted


	Construct your window

	Construct an object of type ComplexPlane

	Construct a VertexArray
		Set its primitive type to Points
		Resize it to screen width * height

		We will use this to draw a color for each pixel
		Refer to BGP Chapters 8 and 9 for an intro on these
		https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1VertexArray.php


	Construct Font and Text objects

	Create an enum class state variable with states CALCULATING and DISPLAYING
		Initialize it to CALCULATING
		When the program starts or when the user clicks the mouse, we will calculate a new view for the complex plane
		This is very CPU intense, so we will set the state variable back to DISPLAYING after it is done so we only have to do it once per click


	Begin the main loop
	
	
	Draw Scene segment
			Clear the window
			Draw the VertexArray
			Draw the Text
			Display
			Don't worry about setting any views, I tried to do it but the small fractional coordinates caused screen tearing
				We can get away with using the default view for drawing because the VertexArray has a 1:1 mapping to every pixel on the screen, and we only used the ComplexPlane's view to map between pixel coordinates and the complex plane
				Setting the ComplexPlane's view before drawing would force the engine to map from the complex plane float coordinates to pixels, but we already did that when we calculated the iterations and loaded the VertexArray, so it's not necessary





// Unsure if more needs to be tweaked on these, functions need to be finished to see
		Handle Input segment
				Poll Windows queue events

				Handle Event::Closed event to close the window

				Handle Event::MouseButtonPressed
					Use mapPixelToCoords to find the Vector2f coordinate in the ComplexPlane View that corresponds to the screen mouse click
					Right click will zoomOut and setCenter of the ComplexPlane object
					Left click will zoomIn and setCenter of the ComplexPlane object
					Set the state to CALCULATING to generate the new complex plane view in the update segment


				Handle Event::MouseMoved
					Use mapPixelToCoords to find the Vector2f coordinate in the ComplexPlane View that corresponds to the screen mouse location
					setMouseLocation on the ComplexPlane object to store this coordinate
					This will be used later to display the mouse coordinates as it moves

				Check if Keyboard::isKeyPressed(Keyboard::Escape) to close the window
							// This one is the hard part
		Update Scene segment
			If the state is CALCULATING
				Double for loop to loop through all pixels in the screen height and width

					Use j for x and i for y

					Set the position variable in the element of VertexArray that corresponds to the screen coordinate j,i
					This is difficult, so study the line of code below:
						vArray[j + i * pixelWidth].position = { (float)j,(float)i };

					Use mapPixelToCoords to find the Vector2f coordinate in the ComplexPlane View that corresponds to the screen pixel location at j,i

					Call ComplexPlane::countIterations for the Vector2f coordinate in the ComplexPlane and store the number of iterations

					Declare three local Uint8 variables r,g,b to store the RGB values for the current pixel
						Uint8 is an alias for unsigned char

					Pass the number of iterations and the RGB variables into ComplexPlane::iterationsToRGB
						This will assign the RGB values by reference

					Set the color variable in the element of VertexArray that corresponds to the screen coordinate j,i
						vArray[j + i * pixelWidth].color = { r,g,b };

			Set the state to DISPLAYING
			Call loadText from the ComplexPlane object



^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^DONE^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


*/

int main()
{


	//Creating all of our objects

		// Create a video mode object
		// Values for desktop scaling
		float width = VideoMode::getDesktopMode().width;
		float height = VideoMode::getDesktopMode().height;
		float aspectRatio = height / width;

		//	View view(FloatRect(0.f, 0.f, width, height)); // Instructions say view might not be necessary
		VideoMode vm(width, height);


		// Create and open a window for the game
		RenderWindow window(vm, "Mandel-What???", Style::Default);	//Window name is placeholder, feel free to change - no I love it

		// Our ComplexPlane
		ComplexPlane plane(aspectRatio);

		// Our VertexArray
		//VertexArray background;
		VertexArray background(Points);
		background.setPrimitiveType(Points);
		background.resize(width * height);

		// Loading font
		Font font;
		font.loadFromFile("./Kanit-Thin.ttf");
		Text messageText;

		// Set font and font size
		messageText.setFont(font);
		messageText.setCharacterSize(44);
		messageText.setColor(Color::Cyan);

		enum state
		{
			CALCULATING, DISPLAYING
		};

		state current = CALCULATING;

	while (window.isOpen())
	{

		// Handle player's input

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
			{
				auto mouse_pos = Mouse::getPosition(window);
				auto translated_pos = window.mapPixelToCoords(mouse_pos, plane.getView());

				if (event.mouseButton.button == Mouse::Left)
				{
					plane.zoomIn();
					plane.setCenter(translated_pos);
					current = CALCULATING;
				}
				else if (event.mouseButton.button == Mouse::Right)
				{
					plane.zoomOut();
					plane.setCenter(translated_pos);
					current = CALCULATING;
				}
				

			}

			if (event.type == Event::MouseMoved)
			{
				auto mouse_pos = Mouse::getPosition(window);
				auto translated_pos = window.mapPixelToCoords(mouse_pos, plane.getView());
				plane.setMouseLocation(translated_pos);
			}
		
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Update Scene segment

		// If the state is CALCULATING
		if (current == CALCULATING)
		{
			size_t iterations = 0;

			for (int j = 0; j < width; j++)
			{
				for (int i = 0; i < height; i++)
				{

					background[j + i * width].position = { float(j),float(i) };
					
					Vector2i pixels;
					pixels.x = j;
					pixels.y = i;

					Vector2f pixel_pos = window.mapPixelToCoords(pixels, plane.getView());

					iterations = plane.countIterations(pixel_pos);
				
					// Use mapPixelToCoords to find the Vector2f coordinate in the ComplexPlane View that corresponds to the screen pixel location at j, i
					
					Uint8 r = 0;
					Uint8 g = 0;
					Uint8 b = 0;


					plane.iterationsToRGB(iterations, r, g, b);

					background[j + i * width].color = { r, g, b };

				}
			}
			current = DISPLAYING;

		}
		
		//window.setView(plane.getView());

		// Call loadText from the ComplexPlane object
		plane.loadText(messageText);

		messageText.setPosition(0.0f, 0.0f);

		//plane.loadText(messageText);
		window.clear();

		window.draw(background);

		// Basic message text
		window.draw(messageText);

		window.display();

	}

	return 0;
}