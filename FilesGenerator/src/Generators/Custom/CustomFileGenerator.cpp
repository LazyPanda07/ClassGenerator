#include "CustomFileGenerator.h"

#include "Properties/CustomFileProperty.h"

using namespace std;

namespace generation
{
	namespace custom
	{
		vector<interfaces::IProperty*> CustomFileGenerator::getProperties() const
		{
			return { new CustomFileProperty() };
		}

		CustomFileGenerator::CustomFileGenerator(const json::JSONParser& settings) :
			BaseGenerator(settings)
		{

		}
	}
}
