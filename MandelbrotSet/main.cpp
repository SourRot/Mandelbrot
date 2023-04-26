#include "complexPlane.cpp"

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{


	// Create a video mode object
	// Values for desktop scaling
	float width = VideoMode::getDesktopMode().width;
	float height = VideoMode::getDesktopMode().height;
	View view(FloatRect(0.f, 0.f, width, height));
	VideoMode vm(width, height);


	// Create and open a window for the game
	RenderWindow window(vm, "Mandel-What???", Style::Default);

	// Create vectors
	vector<Vector2f> vertices;	// Initial 3 points (user clicks)
	vector<Vector2f> newPoints;	// Halfway points that are generated

	// Loading font
	Font font;
	font.loadFromFile("./Kanit-Thin.ttf");
	Text messageText;

	// Set font and font size
	messageText.setFont(font);
	messageText.setCharacterSize(44);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Backround sprite creation
	Sprite spriteBackground;

	// Setting the texture of the sprite and scaling it to our window
	Vector2u TextureSize;  // Added to store texture size.
	Vector2u WindowSize;   // Added to store window size.

	if (!textureBackground.loadFromFile("./background_stars.png"))
	{
		return -1;
	}
	else
	{
		TextureSize = textureBackground.getSize(); // Get size of texture.
		WindowSize = window.getSize();             // Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     // Calculate scale.

		spriteBackground.setTexture(textureBackground);
		spriteBackground.setScale(ScaleX, ScaleY);      // Set scale.  
	}

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

}