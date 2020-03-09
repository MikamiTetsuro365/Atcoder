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

    ll X, N, M;
    cin >> X >> N >> M;

    map<ll, ll> mp;

    for(ll i = 0; i < N; i++){
        ll A;
        cin >> A;
        mp[A]+= 1;
    }

    for(ll i = 0; i < M; i++){
        ll B;
        cin >> B;
        mp[B]+= 2;
    }

    if(mp[X] == 0){
        cout << -1 << endl;
    }else if(mp[X] == 1){
        cout << "MrMax" << endl;
    }else if(mp[X] == 2){
        cout << "MaxValu" << endl;
    }else{
        cout << "MrMaxValu" << endl;
    }

}