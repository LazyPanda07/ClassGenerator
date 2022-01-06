#include "BaseGenerator.h"

using namespace std;

namespace generation
{
	BaseGenerator::BaseGenerator(const json::JSONParser& settings) :
		settings(settings)
	{

	}

	void BaseGenerator::generate() const
	{
		vector<interfaces::IProperty*> properties = this->getProperties();

		for (const auto& i : properties)
		{
			const string& pathToHeaderSample = i->getPropertySample(settings);
			const string& outPath = i->getPropertyOutPath(settings);
			vector<string> arguments = i->getPropertyArguments(settings);
			string result;

			if (!filesystem::exists(pathToHeaderSample))
			{
				throw exceptions::DoesNotExistException(pathToHeaderSample);
			}

			if (!filesystem::exists(outPath))
			{
				filesystem::create_directories(outPath);

				filesystem::remove(outPath);
			}

			result = (ostringstream() << ifstream(pathToHeaderSample).rdbuf()).str();

			for (size_t i = 0; i < arguments.size(); i++)
			{
				string replaceSymbols = '{' + to_string(i) + '}';

				while (result.find(replaceSymbols) != string::npos)
				{
					auto replaceBegin = result.begin() + result.find(replaceSymbols);

					result.replace(replaceBegin, replaceBegin + replaceSymbols.size(), arguments[i]);
				}
			}

			ofstream(outPath) << result;

			if (settings.contains("script", json::utility::variantTypeEnum::jString))
			{
				execution::runScript(settings.getString("script"), outPath);
			}

			if (settings.contains("pathToScript", json::utility::variantTypeEnum::jString))
			{
				execution::runScriptFile(settings.getString("pathToScript"), outPath);
			}
		}

		for (auto& i : properties)
		{
			delete i;
		}
	}
}
