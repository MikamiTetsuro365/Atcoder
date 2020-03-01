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

    ll N, K;
    cin >> N >> K;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    ll sum = 0;

    //ロボットAとBで交互にボールを取っていってその最小をだす
    for(ll i = 0; i < N; i++){
        sum += min(vec[i] * 2, (K-vec[i]) * 2);
    }


    cout << sum << endl;

}