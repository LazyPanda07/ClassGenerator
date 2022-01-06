#include "CPPClassGenerator.h"

#include "Properties/HeaderFileProperty.h"
#include "Properties/CPPFileProperty.h"

using namespace std;

namespace generation
{
	namespace cpp
	{
		vector<interfaces::IProperty*> CPPClassGenerator::getProperties() const
		{
			return
			{
				new HeaderFileProperty(),
				new CPPFileProperty()
			};
		}

		CPPClassGenerator::CPPClassGenerator(const json::JSONParser& settings) :
			BaseGenerator(settings)
		{

		}
	}
}
