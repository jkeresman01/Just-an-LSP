#include "Trie.h"
#include <memory>

namespace justanlsp
{
void Trie::insert(const std::string &word)
{
    std::shared_ptr<TrieNode> current = m_root;

    for (const char &ch : word)
    {
        if (current->children[ch - 'a'] == nullptr)
        {
            std::shared_ptr<TrieNode> newTrieNode = std::make_shared<TrieNode>();
            current->children[ch - 'a'] = newTrieNode;
        }

        current = current->children[ch - 'a'];
    }

    current->isLeaf = true;
}

std::vector<std::string> Trie::getCompletionWords(const std::string &prefix)
{
    std::vector<std::string> completionOptions;

    std::shared_ptr<TrieNode> node = getTrieNode(prefix);

    if (node != nullptr)
    {
        findAllWords(node, prefix, completionOptions);
    }

    return completionOptions;
}

std::shared_ptr<TrieNode> Trie::getTrieNode(const std::string &prefix) const
{
    std::shared_ptr<TrieNode> current = m_root;

    for (const char &ch : prefix)
    {
        int index = ch - 'a';

        if (current->children[index] == nullptr)
        {
            return nullptr;
        }

        current = current->children[index];
    }

    return current;
}

void Trie::findAllWords(std::shared_ptr<TrieNode> node, const std::string &prefix,
                        std::vector<std::string> &results) const
{
    if (node->isLeaf)
    {
        results.push_back(prefix);
    }

    for (size_t i = 0; i < MAX_CHAR_NO; ++i)
    {
        if (node->children[i] != nullptr)
        {
            char nextChar = 'a' + i;
            findAllWords(node->children[i], prefix + nextChar, results);
        }
    }
}

} // namespace justanlsp
