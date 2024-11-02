#pragma once

#include <iostream>
#include <regex>
#include <stack>
#include <string>

namespace justanlsp
{
class XMLUtil
{
  public:
    void checkXMLTags(const std::string &xml)
    {
        std::stack<std::string> tags;
        std::regex tagRegex("<(/?)(\\w+)>"); // Match <tag> or </tag>
        auto tagsBegin = std::sregex_iterator(xml.begin(), xml.end(), tagRegex);
        auto tagsEnd = std::sregex_iterator();

        for (auto it = tagsBegin; it != tagsEnd; ++it)
        {
            std::smatch match = *it;
            std::string tagName = match[2].str();
            bool isClosing = (match[1].str() == "/");

            if (!isClosing)
            {
                tags.push(tagName);
            }
            else
            {
                if (tags.empty())
                {
                    std::cout << "Error: No matching opening tag for </" << tagName << ">\n";
                }
                else if (tags.top() == tagName)
                {
                    tags.pop();
                }
                else
                {
                    std::cout << "Error: Mismatched tag </" << tagName << ">, expected </" << tags.top()
                              << ">\n";
                    tags.pop();
                }
            }
        }

        while (!tags.empty())
        {
            std::cout << "Error: No matching closing tag for <" << tags.top() << ">\n";
            tags.pop();
        }
    }
};
} // namespace justanlsp
