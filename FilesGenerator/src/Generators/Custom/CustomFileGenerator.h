#pragma once

#include "Generators/BaseGenerator.h"

namespace generation
{
	namespace custom
	{
		class CustomFileGenerator : public BaseGenerator
		{
		private:
			std::vector<interfaces::IProperty*> getProperties() const override;

		public:
			CustomFileGenerator(const json::JSONParser& settings);

			~CustomFileGenerator() = default;
		};
	}
}
