#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

int main(){
    
    ll N;
    cin >> N;

    vector<pair<ll, ll > > vec;


    for(ll i = 0; i < N; i++){
        ll v, w;
        cin >> v >> w;
        vec.push_back(make_pair(v, w));
    }

    ll V;
    cin >> V;

    vector<ll > dp(1919191, 0);
    
    for(ll i = 0; i < N; i++){
        
        for (ll j = dp.size() - 1; j >= 1 ; j--){
            if(j - vec[i].second < 0){
                break;
            }
            dp[j] = max(dp[j], dp[j - vec[i].second] + vec[i].first);

        }  
    }

    ll max_w = 0;
    ll min_w = 0;

    for(ll i = 0; i < dp.size(); i++){
        if(dp[i] == V && min_w == 0){
            min_w = 1;
            if(i == 0){
                cout << "1" << endl;
            }else{
                cout << i << endl;
            }
        }
        if(dp[i] > V && max_w == 0){
            max_w = 1;
            cout << i - 1 << endl;
        } 
    }
    if(max_w == 0){
        cout << "inf" << endl;
    }
} 