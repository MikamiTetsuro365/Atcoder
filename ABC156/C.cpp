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

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    ll mn = INF;
    for(ll i = 1; i <= 100; i++){
        ll sum = 0;
        for(ll j = 0; j < N; j++){
            
            sum += (vec[j] - i)  *  (vec[j] - i) ;
        }
        mn = min(mn , sum);
    }

    cout << mn << endl;

}

