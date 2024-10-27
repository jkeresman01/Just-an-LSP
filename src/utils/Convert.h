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
            LOG_ERROR << "Conversion failed: invalid input '" << input << "'";
        }

        if (!converter.eof())
        {
            LOG_ERROR << "Conversion failed: extra characters in input '" << input << "'";
        }

        return result;
    }
};

} // namespace justanlsp
