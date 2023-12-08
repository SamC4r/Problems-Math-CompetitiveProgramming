#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a,b,n;
        cin >> a >> b >> n;
        
        ll s = b;

        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            s+=min(x,a - 1);
        }
        cout << s << endl;

    }
}