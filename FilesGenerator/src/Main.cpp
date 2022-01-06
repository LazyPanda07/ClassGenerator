#include "headers.h"

#include "Generators/CPP/CPPClassGenerator.h"
#include "Generators/Custom/CustomFileGenerator.h"

#pragma comment (lib, "JSON.lib")

using namespace std;

unique_ptr<generation::BaseGenerator> chooseGenerator(const json::JSONParser& settings);

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
		json::JSONParser settings = ifstream(pathToSettings);
		
		chooseGenerator(settings)->generate();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

unique_ptr<generation::BaseGenerator> chooseGenerator(const json::JSONParser& settings)
{
	const string& generationMode = settings.getString("generationMode");
	unique_ptr<generation::BaseGenerator> result;

	if (generationMode == "CPP")
	{
		result = make_unique<generation::cpp::CPPClassGenerator>(settings);
	}
	else if (generationMode == "Custom")
	{
		result = make_unique<generation::custom::CustomFileGenerator>(settings);
	}
	else
	{
		throw runtime_error("Wrong generationMode setting: "s + generationMode);
	}

	return result;
}
