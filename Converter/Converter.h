#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <fstream>

class Converter {
public:
	Converter(const char* imageLocation, const char* fileLocation) 
	{
		result.open(fileLocation);
		image.loadFromFile(imageLocation);
	}
	~Converter() { result.close(); }

	void processImage() 
	{
		sf::Vector2u size = image.getSize();
		result << "{";
		for (int i = 0; i < size.y; i++) {
			result << "\"" + std::to_string(i) + "\":{";
			for (int j = 0; j < size.x; j++) {
				sf::Color pixel_color = image.getPixel(i, j);
				float decimal_color = (pixel_color.r << 16) + (pixel_color.g << 8) + (pixel_color.b);
				if (j == size.x - 1)
					result << "\"" + std::to_string(j) + "\":" + std::to_string(decimal_color);
				else
					result << "\"" + std::to_string(j) + "\":" + std::to_string(decimal_color) + ",";
			}
			if (i == size.y - 1)
				result << "}";
			else
				result << "},\n";
		}
		result << "}";
		std::cout << "Image converted!" << std::endl;
	}

private:
	std::ofstream result;
	sf::Image image;
};