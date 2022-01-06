#include <iostream>

#include "Generators/CPP/CPPClassGenerator.h"

#pragma comment (lib, "JSON.lib")

using namespace std;

int main(int argc, char** argv)
{
	string pathToSettings;

	if (argc == 1)
	{
		cout << "Enter path to settings: ";

		getline(cin, pathToSettings);
	}
	else
	{
		pathToSettings = argv[1];
	}

	try
	{
		generation::cpp::CPPClassGenerator generator(pathToSettings);

		generator.generate();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
