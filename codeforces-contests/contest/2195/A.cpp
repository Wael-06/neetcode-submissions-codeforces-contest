#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--)  {
        int n;
        cin >> n;
 
        bool found = false;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 67) {
                found = true;
            }
        }
 
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
