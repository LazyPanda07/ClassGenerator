#include "CPPClassGenerator.h"

#include "Properties/HeaderFileProperty.h"
#include "Properties/CPPFileProperty.h"

using namespace std;

namespace generation
{
	namespace cpp
	{
		CPPClassGenerator::CPPClassGenerator(const filesystem::path& pathToSettings) :
			BaseGenerator(pathToSettings)
		{
			properties.emplace_back(new HeaderFileProperty());
			properties.emplace_back(new CPPFileProperty());
		}

		void CPPClassGenerator::generate() const
		{
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

				try
				{
					execution::runScript(settings.getString("script"), outPath);
				}
				catch (const json::exceptions::CantFindValueException&)
				{
					try
					{
						execution::runScriptFile(settings.getString("pathToScript"), outPath);
					}
					catch (const json::exceptions::CantFindValueException&)
					{

					}
				}
			}
		}
	}
}
