#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    double _myPow(double x, long long n) {
        if (n == 0) return 1.0;
        if (fabs(x) < 1e-10) return 0.0;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double half = _myPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        else return half * half * x;
    }
    double myPow(double x, int n) {
        return _myPow(x, static_cast<long long>(n));
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif