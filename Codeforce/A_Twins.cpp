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

    sort(vec.rbegin(), vec.rend());

    vector<ll > R(N, 0);
    
    for(ll i = 0; i < N; i++){
        if(i == 0) R[i] = vec[i];
        else R[i] = R[i-1] + vec[i];
    }


    for(ll i = 0; i < N; i++){
        //cout << R[i] << " " << R[N-1] - R[i] << endl;
        if(R[i] > R[N-1] - R[i]){
            cout << i + 1 << endl;
            return 0;
        }
    }

}