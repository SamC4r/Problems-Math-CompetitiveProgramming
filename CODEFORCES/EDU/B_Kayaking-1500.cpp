#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> people(2*n);
    for(int i = 0; i<2*n;i++){
        cin >> people[i];
    }

    sort(people.begin(),people.end());

    int total_insta = 1001;

    for(int i = 0; i<2*n;i++){
        
        for(int j = i + 1; j<2*n;j++){

            //calculate total_insta
            
            vector<int> provisional;
            int provisional_insta = 0;
            for(int k = 0;k<2*n;k++){
                if(k == j || k == i) continue;
                provisional.push_back(people[k]);
                
            }

            for(int k = 0; k<2*n - 2;k+=2){
                provisional_insta += abs(provisional[k]-provisional[k+1]);
            }
            
            total_insta = min(total_insta,provisional_insta);

        }
    }
    
    cout << total_insta;


}