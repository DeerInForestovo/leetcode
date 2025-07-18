#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    string concatHex36(int n) {
        int n2 = n * n, n3 = n2 * n;
        string result;
        while (n3) {
            int digit = n3 % 36;
            if (digit < 10)
                result += '0' + digit;
            else
                result += 'A' + (digit - 10);
            n3 /= 36;
        }
        while (n2) {
            int digit = n2 % 16;
            if (digit < 10)
                result += '0' + digit;
            else
                result += 'A' + (digit - 10);
            n2 /= 16;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    cout << sol.concatHex36(13); // Example usage
    return 0;
}
#endif