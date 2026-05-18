#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--) {
        int n;
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
    }
 
    return 0;
}
 
/*
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> div3, not_div3;
 
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 3 == 0) div3.push_back(x);
            else not_div3.push_back(x);
        }
 
        // print all multiples of 3 first
        for (int x : div3) cout << x << " ";
        for (int x : not_div3) cout << x << " ";
        cout << '\n';
    }
 
    return 0;
}*/
