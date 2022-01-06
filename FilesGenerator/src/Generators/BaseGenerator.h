#pragma once

#include "headers.h"

namespace generation
{
	class BaseGenerator
	{
	protected:
		json::JSONParser settings;

	public:
		BaseGenerator(const std::filesystem::path& pathToSettings);

		virtual void generate() const = 0;

		virtual ~BaseGenerator() = default;
	};
}
