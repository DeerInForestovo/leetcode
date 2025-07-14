#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        for (int i = 0, j = 0; i < n; i = j) {
            int lineLength = 0;
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            int spaces = maxWidth - lineLength, numWords = j - i;
            string line;

            if (numWords == 1 || j == n) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += ' ';
                }
                line += string(spaces - (numWords - 1), ' ');
            } else {
                int spaceBetweenWords = spaces / (numWords - 1), extraSpaces = spaces % (numWords - 1);
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += string(spaceBetweenWords + (int)(k - i < extraSpaces), ' ');
                }
            }

            result.push_back(line);
        }
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif