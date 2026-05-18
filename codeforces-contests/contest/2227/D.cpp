#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    int size = 2 * n;
    vector<int> a(size);
    int L0 = -1, R0 = -1;
    vector<pair<int, int>> b(n);
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            if (L0 == -1){ L0 = i;}
            else{ R0 = i;}
        }
    }
 
    auto get_max_mex = [&](int left, int right) {
        int l = left;
        int r = right;
 
        while (l >= 0 && r < size && a[l] == a[r]) {
            l--;
            r++;
        }
 
        l++;
        r--;
 
        vector<bool> seen(n + 2, false);
        for (int i = l; i <= r; i++) {
            if (a[i] <= n) {
                seen[a[i]] = true;
            }
        }
 
        int current_mex = 0;
        while (seen[current_mex]) {
            current_mex++;
        }
 
        return current_mex;
    };
 
    int max_mex = 0;
 
    max_mex = max(max_mex, get_max_mex(L0, L0));
 
    max_mex = max(max_mex, get_max_mex(R0, R0));
 
    if ((L0 + R0) % 2 == 0) {
        int mid = (L0 + R0) / 2;
        max_mex = max(max_mex, get_max_mex(mid, mid));
    } else {
        int mid_left = (L0 + R0) / 2;
        int mid_right = mid_left + 1;
        max_mex = max(max_mex, get_max_mex(mid_left, mid_right));
    }
 
    cout << max_mex << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
 
/*#include <bits/stdc++.h>
using namespace std;
 
bool ispalindrome(const vector<int>& a, int l, int r) {
    while (l < r) {
        if (a[l] != a[r]) return false;
        l++;
        r--;
    }
    return true;
}
 
int get_mex(const vector<int>& a, int l, int r) {
    unordered_set<int> s;
    for (int i = l; i <= r; i++) {
        s.insert(a[i]);
    }
    int mex = 0;
    while (s.count(mex)) mex++;
    return mex;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int size = 2 * n;
        vector<int> a(size);
 
        for (int i = 0; i < size; i++) cin >> a[i];
 
        int ans = 0;
 
        for (int l = 0; l < size; l++) {
            for (int r = l; r < size; r++) {
                if (ispalindrome(a, l, r)) {
                    int mex = get_mex(a, l, r);
                    ans = max(ans, mex);
                }
            }
        }
 
        cout << ans << "\n";
    }
 
    return 0;
}
*/
/*
 * q3
* int n;
        cin >> n;
        vector<int> both;   // %6 == 0
        vector<int> two;
        vector<int> three;
        vector<int> none;   // neither
        for(int i=0;i<n;i++) {
            int x;
            cin >> x;
            if (x%2==0&&x%3==0) {both.push_back(x);}
            else if (x%2==0) {two.push_back(x);}
            else if (x%3==0) {three.push_back(x);}
            else {none.push_back(x);}
        }
        if (none.size()>0) {
            if (both.size()>0) {
                for (int i:both)cout <<i<<" ";
                for (int i:two)cout <<i<<" ";
                for (int i:none)cout<<i<<" ";
                for (int i:three)cout <<i<<" ";
                cout<<endl;
            }
            else {
                for (int i:three)cout <<i<<" ";
                for (int i:none)cout<<i<<" ";
                for (int i:two)cout <<i<<" ";
                cout<<endl;
            }
        }else {
            for (int i:two)cout <<i<<" ";
            for (int i:three)cout <<i<<" ";
            for (int i:both)cout <<i<<" ";
            cout<<endl;
        }
 */
