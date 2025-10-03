#include <string>
#include <unordered_map>
#include <vector>

class Solution {
private:
    std::unordered_map<int, std::vector<std::string>> cache;

public:
    Solution()
        : cache(std::unordered_map<int, std::vector<std::string>>())
    {
    }

    std::vector<std::string> generateParenthesis(int n)
    {
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }

        if (n == 1) {
            auto result = std::vector<std::string> { "()" };
            cache[n] = result;
            return result;
        }

        std::vector<std::string> result {};
        std::unordered_map<std::string, bool> doubleCounter {};
        for (int i = 1; i <= n - 1; i++) {
            auto parenLeft = generateParenthesis(i);
            auto parenRight = generateParenthesis(n - i);
            for (auto leftString : parenLeft) {
                for (auto rightString : parenRight) {
                    if (doubleCounter[leftString + rightString])
                        continue;
                    doubleCounter[leftString + rightString] = true;
                    result.push_back(leftString + rightString);
                }
            }
        }

        for (auto string : generateParenthesis(n - 1)) {
            result.push_back("(" + string + ")");
        }
        cache[n] = result;
        return result;
    }
};
