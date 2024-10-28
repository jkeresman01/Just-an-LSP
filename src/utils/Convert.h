#pragma once

#include <sstream>
#include <string>

#include "../utils/Logger.h"

namespace justanlsp
{
class Converter
{
  public:
    Converter() = delete;

    template <typename T> static T convert(const std::string &input)
    {
        T result;
        std::stringstream converter(input);

        if (!(converter >> result))
        {
            LOG_ERROR(STR("Conversion failed: invalid input '%s'", input));
        }

        if (!converter.eof())
        {
            LOG_ERROR(STR("Conversion failed: extra characters in input '%s'", input));
        }

        return result;
    }
};

} // namespace justanlsp
