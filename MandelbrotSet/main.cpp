#include "complexPlane.cpp"

// Make code easier to type with "using namespace"

int main()
{


	// Create a video mode object
	// Values for desktop scaling
	float width = VideoMode::getDesktopMode().width;
	float height = VideoMode::getDesktopMode().height;
	View view(FloatRect(0.f, 0.f, width, height));
	VideoMode vm(width, height);


	// Create and open a window for the game
	RenderWindow window(vm, "Mandel-What???", Style::Default);	//Window name is placeholder, feel free to change

	// Loading font
	Font font;
	font.loadFromFile("./Kanit-Thin.ttf");
	Text messageText;

	// Set font and font size
	messageText.setFont(font);
	messageText.setCharacterSize(44);

	// Setting the texture of the sprite and scaling it to our window
	Vector2u TextureSize;  // Added to store texture size.
	Vector2u WindowSize;   // Added to store window size.

}