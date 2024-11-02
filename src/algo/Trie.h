#pragma once

#include "TrieNode.h"

#include <memory>
#include <string>
#include <vector>

namespace justanlsp
{
class Trie
{
  public:
    Trie() = default;

    void insert(const std::string &word);

    std::vector<std::string> getCompletionWords(const std::string &prefix);

  private:
    std::shared_ptr<TrieNode> getTrieNode(const std::string &prefix) const;

    void findAllWords(std::shared_ptr<TrieNode> node, const std::string &prefix,
                      std::vector<std::string> &results) const;

  private:
    std::shared_ptr<TrieNode> m_root = std::make_shared<TrieNode>();

    static constexpr uint32_t MAX_CHAR_NO = 26;
};
} // namespace justanlsp
