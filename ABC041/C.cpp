#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    ll N;
    cin >> N;

    vector<pair<ll, ll > > vec;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(make_pair(t, i + 1));
    }

    sort(vec.rbegin(), vec.rend());

    for(ll i = 0; i < N; i++){
        cout << vec[i].second<< endl;
    }
 
}