#include "Converter.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "nothing to convert.." << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		// shitcoded
		std::string newPath = argv[i];
		newPath.resize(newPath.size() - 4);
		newPath += ".txt";
		//

		Converter* convertidor = new Converter(argv[i], newPath.c_str());
		convertidor->processImage();
		delete convertidor;
	}

	return 0;
}