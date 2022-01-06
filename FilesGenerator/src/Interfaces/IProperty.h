#pragma once

#include <string>
#include <vector>

#include "JSONParser.h"

namespace interfaces
{
	class IProperty
	{
	protected:
		virtual std::string getPropertyName() const = 0;

	public:
		IProperty() = default;

		virtual const std::string& getPropertySample(const json::JSONParser& settings) const final;

		virtual const std::string& getPropertyOutPath(const json::JSONParser& settings) const final;

		virtual std::vector<std::string> getPropertyArguments(const json::JSONParser& settings) const final;

		virtual ~IProperty() = default;
	};
};
