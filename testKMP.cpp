// Time:  O(n)
// Space: O(n)
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


string preProcess(string s) {
    int n = s.length();
    if (n == 0) {
        return "^$";
    }
    string ret = "^";
    for (int i = 0; i < n; i++) {
        ret += "#" + s.substr(i, 1);
    }

    ret += "#$";
    cout << "Afert perform, string change to: " << ret << endl;
    return ret;
}

string longestPalindrome(string& s) {
    string T = preProcess(s);
    int n = T.length();
    vector<int> P(n);
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; ++i) {
        int i_mirror = 2*C-i; // equals to i' = C - (i-C)

        P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            ++P[i];
        }

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
        C = i;
        R = i + P[i];
        }
    }

    // Find the maximum element in P.
    int max_len = 0, center_index = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (P[i] > max_len) {
            max_len = P[i];
            center_index = i;
        }
    }

    return s.substr((center_index - 1 - max_len) / 2, max_len);
}


int main() {
    string s = "abcdzdcab";
    string res = longestPalindrome(s);
    cout << "longest palindrom is: " << res << endl;
}