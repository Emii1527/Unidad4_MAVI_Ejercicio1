#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;

//////Variables//////
Texture texture_crosshair;
Sprite sprite_crosshair;

float escalaX; float escalaY;
float height_crosshair, width_crosshair;

/////Punto de entrada a la aplicación//////
int main()
{

	texture_crosshair.loadFromFile("crosshair.png");
	sprite_crosshair.setTexture(texture_crosshair);

	height_crosshair = (float)texture_crosshair.getSize().y;
	width_crosshair = (float)texture_crosshair.getSize().x;

	sprite_crosshair.setPosition((800 / 2) - 64, (600 / 2) - 64);


	/////Creamos la ventana//////
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Que Ventana horrible");
	/////Loop principal//////
	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter) == true)
				App.close();
			App.draw(sprite_crosshair);
		}
		App.display();
	}
	return 0;
}
