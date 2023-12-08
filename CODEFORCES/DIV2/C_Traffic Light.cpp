    #include<bits/stdc++.h>

    #define vc vector<char>
    #define vi vector<int>
    #define pb push_back
    #define endl "\n"

    using namespace std;
    int main(){
        int t;
        cin >> t;
        while(t--){
            int n;
            char c;
            cin >> n >> c;
        
            vi cs; //currents
            vi gs; //greens
            string s;
            cin >> s;
            s+=s;
            for(int i = 0; i<s.length();i++){

                if(i<n && s[i % n] == c) cs.pb(i);

                if(s[i % n] == 'g') gs.pb(i);

            }
            int ans = 0;
            for(auto a : cs){
                auto pos = lower_bound(gs.begin(),gs.end(),a);
                ans = max(*pos - a,ans);
            }
            cout << ans << endl;
        }
    }