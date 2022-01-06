#pragma once

#include "headers.h"
#include "Interfaces/IProperty.h"

namespace generation
{
	class BaseGenerator
	{
	protected:
		const json::JSONParser& settings;
		
	protected:
		virtual std::vector<interfaces::IProperty*> getProperties() const = 0;

	public:
		BaseGenerator(const json::JSONParser& settings);

		virtual void generate() const final;

		virtual ~BaseGenerator() = default;
	};
}
