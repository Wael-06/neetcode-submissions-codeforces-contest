#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--) {
        int x,y;
        cin >> x >> y;
        if (x%2==0&&y%2==0){cout<<"YES"<<endl;continue;}
        if (x%2==0||y%2==0){cout<<"YES"<<endl;continue;}
        else cout<<"NO"<<endl;
    }
    return 0;
}
