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
    vector<int> sliding_window_minimum(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < arr.size(); ++i) {
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && arr[dq.back()] >= arr[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
                result.push_back(arr[dq.front()]);
        }
        return result;
    }
    void solve() {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];

        vector<vector<int>> row_minimums(n, vector<int>(n - k + 1));
        vector<vector<int>> result(n - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i < n; ++i) {
            row_minimums[i] = sliding_window_minimum(matrix[i], k);
        }

        for (int j = 0; j <= n - k; ++j) {
            deque<int> dq;
            for (int i = 0; i < n; ++i) {
                if (!dq.empty() && dq.front() <= i - k)
                    dq.pop_front();
                while (!dq.empty() && row_minimums[dq.back()][j] >= row_minimums[i][j])
                    dq.pop_back();
                dq.push_back(i);
                if (i >= k - 1)
                    result[i - k + 1][j] = row_minimums[dq.front()][j];
            }
        }

        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
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