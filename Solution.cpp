
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        int maxLength = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
                }
                else if (s[i - 1] == ')') {
                    int j = i - dp[i - 1] - 1;

                    if (j >= 0 && s[j] == '(') {
                        dp[i] = dp[i - 1] + 2
                              + (j >= 1 ? dp[j - 1] : 0);
                    }
                }
                maxLength = max(maxLength, dp[i]);
            }
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.longestValidParentheses(s) << endl;
    return 0;
}
