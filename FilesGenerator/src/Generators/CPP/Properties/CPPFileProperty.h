#pragma once

#include "Interfaces/IProperty.h"

namespace generation
{
	namespace cpp
	{
		class CPPFileProperty : public interfaces::IProperty
		{
		private:
			std::string getPropertyName() const final override;

		public:
			CPPFileProperty() = default;

			~CPPFileProperty() = default;
		};
	}
}
