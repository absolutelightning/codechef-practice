//
// Created by Ashesh Vidyut
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
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
#include <numeric>

#define ll long long int

using namespace std;

class Main {
public:
 void solve() {
        int n = 100;
         for (int i = 0; i < n; ++i) {
             for (int j = i + 1; j < n; ++j) {
                if ((i ^ j) == n) {
                    cout << i << " " << j << " " << (j - i) << endl;
                }
             }
         }
    }
};

int main() {
    auto main = new Main();
    main->solve();
};
