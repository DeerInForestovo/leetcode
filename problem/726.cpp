#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    std::string::iterator next_digit_string_iter(std::string::iterator iter, std::string::iterator end) {
        auto iter_not_digit = find_if(iter, end, [](char ch) {
                return !std::isdigit(ch);
        });
        return iter_not_digit;
    }
    std::string::iterator next_letter_string_iter(std::string::iterator iter, std::string::iterator end) {
        auto iter_not_letter = find_if(iter + 1, end, [](char ch) {
                return !std::islower(ch);
        });
        return iter_not_letter;
    }
    std::map<std::string, int> _count_atoms(std::string::iterator &iter, std::string::iterator end) {
        std::map<std::string, int> map_result;
        while (*iter != ')') {
            if (*iter == '(') {
                ++iter;
                auto cur_map = _count_atoms(iter, end);
                ++iter;
                int val = 1;
                if (iter != end && std::isdigit(*iter)) {
                    auto digit_str_end = next_digit_string_iter(iter, end);
                    val = std::stoi(std::string(iter, digit_str_end));
                    iter = digit_str_end;
                }
                for (auto map_iter = cur_map.begin(); map_iter != cur_map.end(); ++map_iter)
                    map_result[map_iter->first] += map_iter->second * val;
            } else {  // c is an upper letter
                auto letter_str_end = iter + 1;
                if (letter_str_end != end && std::islower(*letter_str_end))
                    letter_str_end = next_letter_string_iter(letter_str_end, end);  // search from a lower letter
                std::string name_string(iter, letter_str_end);
                iter = letter_str_end;
                int val = 1;
                if (iter != end && std::isdigit(*iter)) {
                    auto digit_str_end = next_digit_string_iter(iter, end);
                    val = std::stoi(std::string(iter, digit_str_end));
                    iter = digit_str_end;
                }
                map_result[name_string] += val;
            }
        }
        return map_result;
    }
    std::string countOfAtoms(std::string formula) {
        formula.push_back(')');
        auto iter = formula.begin();
        auto map_result = _count_atoms(iter, formula.end());
        std::string result;
        for (auto iter = map_result.begin(); iter != map_result.end(); ++iter) {
            result.append(iter->first);
            if (iter->second != 1)
                result.append(std::to_string(iter->second));
        }
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    cout << sol.countOfAtoms("H2O") << endl; // Expected: H2O
    return 0;
}
#endif