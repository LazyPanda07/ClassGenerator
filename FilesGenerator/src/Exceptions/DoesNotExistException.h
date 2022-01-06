#pragma once

#include <filesystem>
#include <stdexcept>

namespace exceptions
{
	class DoesNotExistException : public std::runtime_error
	{
	public:
		DoesNotExistException(const std::filesystem::path& pathToFile);

		~DoesNotExistException() = default;
	};
}
