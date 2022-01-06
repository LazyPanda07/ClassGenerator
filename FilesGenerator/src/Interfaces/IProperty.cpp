#include "IProperty.h"

#include "JSONArrayWrapper.h"

using namespace std;

namespace interfaces
{
	const string& IProperty::getPropertySample(const json::JSONParser& settings) const
	{
		return settings.getString(this->getPropertyName() + "SamplePath");
	}

	const string& IProperty::getPropertyOutPath(const json::JSONParser& settings) const
	{
		return settings.getString(this->getPropertyName() + "OutPath");
	}

	vector<string> IProperty::getPropertyArguments(const json::JSONParser& settings) const
	{
		return json::utility::JSONArrayWrapper(settings.getArray(this->getPropertyName() + "SampleArguments")).getAsStringArray();
	}
}
