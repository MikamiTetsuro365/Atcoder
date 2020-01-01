#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    ll N; cin >> N;

    vector<vector<ll > > vec(N, vector<ll >(26, 0));

    for(ll i = 0; i < N; i++){
        string t; cin >> t;
        for(ll j = 0; j < t.length(); j++){
            vec[i][t[j] - 'a'] += 1;
        }
    }

    string ans = ""; 
    for(ll i = 0; i < 26; i++){
        bool f = true;
        ll len = INF;
        for(ll j = 0; j < N; j++){
            if(vec[j][i] == 0){
                f = false;
                break;
            }
            //cout << vec[j][i] << endl;
            len = min(len, vec[j][i]);
        }
        if(f == true){
            //cout << len << endl;
            for(ll j = 0; j < len; j++){
                //cout << i + 'a' << endl;
                ans += i + 'a';
            }
        }
    }

    cout << ans << endl;

}