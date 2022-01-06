#pragma once

#include "Interfaces/IProperty.h"

namespace generation
{
	namespace custom
	{
		class CustomFileProperty : public interfaces::IProperty
		{
		private:
			std::string getPropertyName() const override;

		public:
			CustomFileProperty() = default;

			~CustomFileProperty() = default;
		};
	}
}
