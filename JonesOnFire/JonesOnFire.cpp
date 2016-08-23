#include "stdafx.h"
#include "menu.h"
#include "Player.h"
#include "Cat.h"

using namespace sf;

void start_game() 
{
	RenderWindow window(sf::VideoMode(980, 600), "Jones On Fire");

	Music musiccat;
	musiccat.openFromFile("menu.ogg");
	musiccat.setVolume(100);
	musiccat.play();

	menu(window);

	Music musicMain;//
	musicMain.openFromFile("main.ogg");
	musicMain.setVolume(100);
	musicMain.play();


	Texture main;
	main.loadFromFile("images/man1.png");
	float CurrentFrame = 0;
	Player player(main);

	Cat cat1("cat2.png", 0, 60, 60, 60);
	cat1.sprite.setPosition(480, 210);
	Cat cat2("cat2.png", 60, 60, 60, 60);
	cat2.sprite.setPosition(666, 220);
	Cat cat3("cat2.png", 0, 60, 60, 60);
	cat3.sprite.setPosition(555, 240);

	int dir;
	float currentFrameCats = 0;

	/////////////////////////////////////////////////////
	Image map_image;
	map_image.loadFromFile("images/map2.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite mapsprite;
	mapsprite.setTexture(map);
	mapsprite.setTextureRect(IntRect(0, 0, 980, 600));
	mapsprite.setPosition(0, 0);
	///////////////////////////////////////////////////////

	float coordinatePlayerX, coordinatePlayerY = 0;
	coordinatePlayerX = player.getplayercoordinateX();
	coordinatePlayerY = player.getplayercoordinateY();

	Clock clock;
	RectangleShape rectangle(Vector2f(32, 32));

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if ((Keyboard::isKeyPressed(Keyboard::Left)))
		{
			player.dx = -0.1;
			std::cout << player.getplayercoordinateX() << ", " << player.getplayercoordinateY() << std::endl;
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right)))
		{
			player.dx = +0.1;
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)))
		{
			if (player.onGround)
			{
				player.dy = -0.45;
				player.onGround = false;
			};
		}

		currentFrameCats += time * 0.005;
		if (currentFrameCats > 2)
		{
			currentFrameCats = 0;
		}
		cat1.sprite.setTextureRect(IntRect(0, 60 * int(currentFrameCats), 60, 60));
		cat2.sprite.setTextureRect(IntRect(60, 60 * int(currentFrameCats), 60, 60));
		cat3.sprite.setTextureRect(IntRect(0, 60 * int(currentFrameCats), 60, 60));

		player.Player::Update(time);
		window.clear();
		
		window.draw(mapsprite);

		window.draw(player.sprite);
		window.draw(cat1.sprite);
		window.draw(cat2.sprite);
		window.draw(cat3.sprite);

		window.display();	
	}
}


int main()
{
	start_game();
	return 0;
}