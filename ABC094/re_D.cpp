#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

//最大値の中央値あたりが怪しい
int main() {

    ll N;
    cin >> N;
    
    vector<ll > A(N, 0);
    
  	for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    
    double center = A[0] / 2;
    double t_abs = INF;
    ll t_idx = 0;
    for(ll i = 1; i < N; i++){
        
        if(t_abs > abs(center-A[i])){
            t_abs = abs(center-A[i]);
            t_idx = i;
        }
    }
    
    cout << A[0] << " " <<  A[t_idx] << endl;

}