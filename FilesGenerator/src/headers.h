#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <format>

#include "Execution.h"
#include "Interfaces/IProperty.h"

#include "Exceptions/DoesNotExistException.h"

#include "JSONParser.h"
#include "JSONArrayWrapper.h"

#include "Exceptions/CantFindValueException.h"
