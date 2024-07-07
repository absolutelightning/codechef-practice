//
// Created by Ashesh Vidyut
//

// https://www.codechef.com/problems/K1

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

const int MAX = (int)2e5 + 1;
const int MOD = (int)1e9 + 7;

class Solution {
public:
    double calc(double x, long a, long b, long c, vector<vector<int>> &xy) {
        double y = -1 * ( c + a * x) / b;
        double sum = 0.0;
        for(auto p : xy) {
            double num = pow(p[0]-x,2) + pow(p[1]-y,2);
            sum = sum + sqrt(num);
        }
        return sum;
    }
    void solve() {
        int tc; cin >> tc;
        while(tc--) {
            int n; double a, b, c; cin >> n;
            cin >> a >> b >> c;
            vector<vector<int>> xy;
            for (int i = 0; i < n; ++i) {
                vector<int> ar(2);
                cin >> ar[0] >> ar[1];
                xy.push_back(ar);
            }
            double ans = -1e9;
            double l = -5e3, r = 5e3;
            while((r - l) >= (1e-6)) {
                double x1 = l + ((r - l) / 3);
                double x2 = r - ((r - l) / 3);
                double c1 = calc(x1, a, b, c, xy);
                double c2 = calc(x2, a, b, c, xy);
                if (c1 < c2) {
                    ans = x1;
                    r = x2;
                }
                else {
                    ans = x2;
                    l = x1;
                }
            }
            cout << fixed << setprecision(6) << calc(ans, a, b, c, xy) << endl;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    auto solution = new Solution();
    solution->solve();
    delete(solution);
    return 0;
}