#include "DoesNotExistException.h"

using namespace std;

namespace exceptions
{
	DoesNotExistException::DoesNotExistException(const filesystem::path& pathToFile) :
		runtime_error(format(R"("{}" doesn't exist)", filesystem::absolute(pathToFile).string()))
	{

	}
}
