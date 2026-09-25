#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        int index = 0;
        std::set<std::string> resultSet = parseExpr(expression, index);
        return std::vector<std::string>(resultSet.begin(), resultSet.end());
    }

private:
    // Helper to compute Cartesian product of two sets
    std::set<std::string> cartesianProduct(const std::set<std::string>& A, const std::set<std::string>& B) {
        std::set<std::string> result;
        for (const std::string& a : A) {
            for (const std::string& b : B) {
                result.insert(a + b);
            }
        }
        return result;
    }

    // Handles comma-separated unions
    std::set<std::string> parseExpr(const std::string& s, int& idx) {
        std::set<std::string> unionSet;

        while (idx < s.size()) {
            std::set<std::string> termSet = parseTerm(s, idx);
            unionSet.insert(termSet.begin(), termSet.end());

            if (idx < s.size() && s[idx] == ',') {
                idx++; // Consume ',' and continue parsing the next term in union
            } else {
                break; // Stopped at '}' or end of string
            }
        }

        return unionSet;
    }

    // Handles adjacent concatenations
    std::set<std::string> parseTerm(const std::string& s, int& idx) {
        std::set<std::string> prodSet = {""};

        while (idx < s.size() && s[idx] != ',' && s[idx] != '}') {
            std::set<std::string> factor;

            if (s[idx] == '{') {
                idx++; // Consume '{'
                factor = parseExpr(s, idx);
                idx++; // Consume '}'
            } else if (std::isalpha(s[idx])) {
                factor = {std::string(1, s[idx])};
                idx++; // Consume the character
            }

            prodSet = cartesianProduct(prodSet, factor);
        }

        return prodSet;
    }
};