#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
ll D, N;

int main(){
    
    cin >> N;

    vector<vector<ll > > card(N, vector<ll >(3, 0));
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < 3; j++){
           cin >> card[i][j];
        }
    }
    vector<ll > ans(N, 0);
    
    for(ll j = 0; j < 3; j++){
        map<ll, vector<ll > > tmp;
        for(ll i = 0; i < N; i++){
            tmp[card[i][j]].push_back(i);
        }
        //点数算出
        auto begin = tmp.begin(), end = tmp.end();
        for (auto iter = begin; iter != end; iter++) {
            //cout << iter->first << endl;
            if(tmp[iter->first].size() == 1){
                ans[tmp[iter->first][0]] += iter->first;
                //cout << ans[tmp[iter->first][0]] << endl;
            }
        }
    }  

    for(ll i = 0; i < N; i++){
        cout << ans[i] << endl;
    }

    //out << ans << endl;

}