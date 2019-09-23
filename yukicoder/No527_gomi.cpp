#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

int main(){
    
    ll N;
    cin >> N;

    vector<pair<ll, ll > > vec;

    ll max_w = 1145141919;
    ll min_w = 1145141919;
    for(ll i = 0; i < N; i++){
        ll v, w;
        cin >> v >> w;
        vec.push_back(make_pair(v, w));
        if(min_w > w){
            min_w = w;
        }
    }

    //sort(vec.begin(), vec.end());

    ll V;
    cin >> V;

    vector<ll > dp(101010, 1145141919);
    dp[0] = 0;
    
    for(ll i = 0; i < vec.size(); i++){
        ll v = vec[i].first;
        ll w = vec[i].second;
        for (ll j = 100000; j >= 1 ; j--){
            //cout << j << endl;
            if(j - v < 0) break;
            dp[j] = min(dp[j], dp[j - v] + w);
            /* 
            if(dp[j] != 1145141919){
                dp[j + v] = min(dp[j + v], dp[j] + w);
            }
            */

        }  
    }
    //cout << dp[V  + 1] << endl;
    if(dp[V] == 0){
        cout << "1" << endl;
        cout << min_w - 1  << endl;
    }else{
        cout << dp[V] << endl;
        for(ll i = V + 1; i < 100000; i++){
            if(dp[i] != 1145141919){
                max_w = dp[i];
                break;
            }
        }
        if(max_w == 1145141919){
            cout << "inf" << endl;
        }else{
            cout << max_w - 1 << endl;
        }
    }
} 