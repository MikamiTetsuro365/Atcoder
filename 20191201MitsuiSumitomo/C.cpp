#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    ll X = 0;
    cin >> X;

    vector<ll > dp(100010, -1);
    dp[0] = 0;

    vector<ll > product(6, 0);
    product[0] = 100;
    product[1] = 101;
    product[2] = 102;
    product[3] = 103;
    product[4] = 104;
    product[5] = 105;

    for(ll i = 0; i < 100001; i++){
        if(dp[i] != -1){
            for(ll j = 0; j < 6; j++){
                if(i + product[j] <= 100001){
                    dp[i+product[j]] = max(dp[i]+1, dp[i+product[j]]);
                }
            }
        }
    }

    if(dp[X] == -1){
        cout << "0" << endl;
    }else{
        cout << "1" << endl;
    }

}