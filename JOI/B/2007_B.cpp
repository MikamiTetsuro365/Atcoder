#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    vector<bool > vec(30, false);

    for(ll i = 0; i < 28; i++){
        ll t = 0; cin >> t;
        vec[t-1] = true;
    }

    for(ll i = 0; i < 30; i++){
        if(vec[i] == false){
            cout << i + 1 << endl;
        }
    }

}