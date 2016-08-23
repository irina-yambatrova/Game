class Fire
{
public:
	float x, y, w, h, speed;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Fire(String F, float X, float Y, float W, float H)
	{
		File = "fire1.png";
		image.loadFromFile("images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = 559; y = 418;
		sprite.setTextureRect(IntRect(0, 100, 100, 100));
		sprite.setPosition(x, y);
	}
}; 
Fire f("fire1.png", 0, 100, 100, 100);
f.sprite.setTextureRect(IntRect(0, 90 * int(currentFrameCats), 100, 90));
if (currentFrameCats > 2)
{
	currentFrameCats = 0;
}
void randomMapGenerate() {//рандомно расставляем камни

	int randomElementX = 0;//случайный элемент по горизонтали
	int randomElementY = 0;//случ эл-т по вертикали
	srand(time(0));//рандом	
	int countStone = 2;//количество камней

	while (countStone>0) {
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);//рандомное по иксу от 1 до ширина карты-1, чтобы не получать числа бордюра карты
		randomElementY = 1 + rand() % (HEIGHT_MAP - 1);//по игреку так же

		if (TileMap[randomElementY][randomElementX] == ' ') {//если встретили символ пробел, 
			TileMap[randomElementY][randomElementX] = 's'; //то ставим туда камень.
														   //std::cout << "coordinate of Stone X:" << randomElementX << "\n" << "coordinate of Stone Y:" << randomElementY << "\n\n";
			countStone--;
		}
	}
}