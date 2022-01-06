#pragma once

#include <filesystem>

namespace execution
{
	void runScript(const std::string& script, const std::filesystem::path& pathToCreatedFile);

	void runScriptFile(const std::filesystem::path& pathToScript, const std::filesystem::path& pathToCreatedFile);
}
