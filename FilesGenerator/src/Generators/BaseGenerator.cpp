#include "BaseGenerator.h"

using namespace std;

namespace generation
{
	BaseGenerator::BaseGenerator(const filesystem::path& pathToSettings) 
	{
		if (!filesystem::exists(pathToSettings))
		{
			throw exceptions::DoesNotExistException(pathToSettings);
		}

		settings = ifstream(pathToSettings);
	}
}
