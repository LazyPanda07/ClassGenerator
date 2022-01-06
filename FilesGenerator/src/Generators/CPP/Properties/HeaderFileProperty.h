#pragma once

#include "Interfaces/IProperty.h"

namespace generation
{
	namespace cpp
	{
		class HeaderFileProperty : public interfaces::IProperty
		{
		private:
			std::string getPropertyName() const final override;

		public:
			HeaderFileProperty() = default;

			~HeaderFileProperty() = default;
		};
	}
}
