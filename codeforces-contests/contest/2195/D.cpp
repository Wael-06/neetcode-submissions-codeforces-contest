#include <bits/stdc++.h>
using namespace std;
 
bool isAdjacent(int a, int b) {
    if (a == b) return false;
    // Opposite faces: (1,6), (2,5), (3,4)
    if ((a == 1 && b == 6) || (a == 6 && b == 1)) return false;
    if ((a == 2 && b == 5) || (a == 5 && b == 2)) return false;
    if ((a == 3 && b == 4) || (a == 4 && b == 3)) return false;
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
 
        // dp[i][j] = min operations to make first i elements valid with a[i-1] = j
        const int INF = 1e9;
        vector<vector<int>> dp(n + 1, vector<int>(7, INF));
 
        // Base case: first element can be any value from 1 to 6
        for (int j = 1; j <= 6; j++) {
            dp[1][j] = (a[0] == j) ? 0 : 1;
        }
 
        // Fill DP table
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= 6; j++) {
                // Current element is j
                int cost = (a[i-1] == j) ? 0 : 1;
 
                // Try all possible previous values
                for (int prev = 1; prev <= 6; prev++) {
                    if (isAdjacent(prev, j)) {
                        dp[i][j] = min(dp[i][j], dp[i-1][prev] + cost);
                    }
                }
            }
        }
 
        // Find minimum over all possible last values
        int ans = INF;
        for (int j = 1; j <= 6; j++) {
            ans = min(ans, dp[n][j]);
        }
 
        cout << ans << "\n";
    }
 
    return 0;
}
