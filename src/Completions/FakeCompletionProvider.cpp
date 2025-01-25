#include "FakeCompletionProvider.h"

#include <vector>

namespace justanlsp
{
std::vector<CompletionItem> FakeCompletionProvider::getCompletions()
{
    std::vector<CompletionItem> completions;
    fillFakeComletions(completions);
    return completions;
}

void FakeCompletionProvider::fillFakeCompletions(std::vector<CompletionItem> &completions)
{
    completions.emplace_back(
        {"dnsClient", "DNS client test 1", "DNS client test 1 documentation", "dnsClient"});
    completions.emplace_back(
        {"dnsClientId", "DNS client test 1", "DNS client id test 1 documentation", "dnsClientId"});
    completions.emplace_back({"dnsClientIpAddress", "DNS client ip address test 1",
                              "DNS client ip address test 1 documentation", "dnsClientIpAddress"});
    completions.emplace_back(
        {"dnsClient", "DNS client test 1", "DNS client test 1 documentation", "dnsClient"});
}
} // namespace justanlsp
