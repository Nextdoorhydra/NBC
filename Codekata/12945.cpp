#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution1(int n) {
    // --init--
    int answer = 0, idx = 2, m = 1234567;
    vector<int> dp(100'001, 0);

    // --main--
    dp[1] = 1;

    while (n >= idx) {
        dp[idx] = (dp[idx - 1] + dp[idx - 2]) % m;
        idx++;
    }

    answer = dp[n];
    return answer;
}