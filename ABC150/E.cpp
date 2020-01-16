#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

using namespace std;

int main(){

    //N桁あることになる
    ll N;
    cin >> N;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    //1桁目に大が来ていると最小コストになりやすい
    sort(vec.rbegin(), vec.rend());

    //1桁目が異なる組み合わせ, 2桁目...1桁目と2桁目が異なる組み合わせでまとめる
    



}