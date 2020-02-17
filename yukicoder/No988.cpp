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

    ll N, M, K;
    cin >> N >> M >> K;
    
    MOD = K;

    char op;
    cin >> op;
    
    vector<ll > A(M, 0);
    vector<ll > B(N, 0);
    
    for(ll i = 0; i < M; i++){
        cin >> A[i];
    }
    
    ll sum = 0;
    for(ll i = 0; i < N; i++){
        cin >> B[i];
        sum += B[i];
        sum %= MOD;
    }
    
    ll t_sum = 0;
    for(ll i = 0; i < M; i++){
        if(op == '*'){
            t_sum += sum * A[i];
            t_sum %= MOD;
        }else{
            t_sum += sum + A[i] * N % MOD;
            t_sum %= MOD;
        }
    }
    
    cout << t_sum << endl;

}