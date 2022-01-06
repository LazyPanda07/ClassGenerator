#pragma once

#include "Generators/BaseGenerator.h"
#include "Interfaces/IProperty.h"

namespace generation
{
	namespace cpp
	{
		class CPPClassGenerator : public BaseGenerator
		{
		private:
			std::vector<std::unique_ptr<interfaces::IProperty>> properties;

		public:
			CPPClassGenerator(const std::filesystem::path& pathToSettings);

			virtual void generate() const final override;

			virtual ~CPPClassGenerator() = default;
		};
	}
}
