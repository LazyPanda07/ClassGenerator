#pragma once

#include "Generators/BaseGenerator.h"

namespace generation
{
	namespace cpp
	{
		class CPPClassGenerator : public BaseGenerator
		{
		private:
			std::vector<interfaces::IProperty*> getProperties() const override;

		public:
			CPPClassGenerator(const json::JSONParser& settings);

			~CPPClassGenerator() = default;
		};
	}
}
