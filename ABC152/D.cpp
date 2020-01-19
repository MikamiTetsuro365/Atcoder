#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N;
    cin >> N;

    map<vector<ll >, ll> ans;

    for(ll i = 1; i <= N; i++){
        if(to_string(i).length() == 1){
            ans[vector<ll >{i}]++;
        }else{
            ll a = to_string(i)[0];
            ll b = to_string(i)[to_string(i).length()-1];
            //baみたいなやつと一緒になる
            
        }
    }


}