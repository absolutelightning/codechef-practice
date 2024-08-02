//
// Created by Ashesh Vidyut
//

#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <climits>
#include <algorithm>
#include <utility>
#include <bitset>
#include <iterator>
#include <iomanip>
#include <cmath>

#define ll long long int

using namespace std;

const int MAX = (int)2e6 + 1;
const int MOD = (int)1e9 + 7;

class Solution {
public:
    void solve() {
        int tc; cin >> tc;
        while(tc--) {
            int n, x; cin >> n >> x;
            int a[n];
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            ll dp[n][2];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 2; ++j) {
                    dp[i][j] = 0;
                }
            }
            for(int i = 1; i < n; i++) {
                // not added x in prev and cur
                ll op = a[i] ^ a[i-1];
                dp[i][0] = max(dp[i][0], dp[i - 1][0] + op);

                // not added x in cur but added in prev
                op = a[i] ^ (a[i - 1] + x);
                dp[i][0] = max(dp[i][0], dp[i - 1][1] + op);

                // added x in cur but not in prev
                op = (a[i] + x) ^ a[i - 1];
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + op);

                // added in x and added in prev
                op = (a[i] + x) ^ (a[i - 1] + x);
                dp[i][1] = max(dp[i][1], dp[i - 1][1] + op);
            }
            cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    auto solution = new Solution();
    solution->solve();
    delete(solution);
    return 0;
}