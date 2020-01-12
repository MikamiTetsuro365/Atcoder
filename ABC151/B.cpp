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

    ll N, K, M; cin >> N >> K >> M;


    ll sum = 0;
    for(ll i = 0; i < N - 1; i++){
        ll t = 0; cin >> t;
        sum += t;
    }    

    if(M * N <= sum){
        cout << 0 << endl;
    }else if(M * N - sum > K){
        cout << -1 << endl;
    }else{
        cout << M * N - sum << endl;    
    }
    


}