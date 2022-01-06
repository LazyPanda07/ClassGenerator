#include "Execution.h"

#include "Exceptions/DoesNotExistException.h"

using namespace std;

namespace execution
{
	void runScript(const string& script, const filesystem::path& pathToCreatedFile)
	{
		system(format(R"("{}" "{}")", script, filesystem::absolute(pathToCreatedFile).string()).data());
	}

	void runScriptFile(const filesystem::path& pathToScript, const filesystem::path& pathToCreatedFile)
	{
		if (!filesystem::exists(pathToScript))
		{
			throw exceptions::DoesNotExistException(pathToScript);
		}

		system(format(R"("{}" "{}")", filesystem::absolute(pathToScript).string(), filesystem::absolute(pathToCreatedFile).string()).data());
	}
}
