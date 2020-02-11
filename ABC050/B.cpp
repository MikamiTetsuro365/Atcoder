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

    vector<ll > T(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> T[i];
    }

    ll M;
    cin >> M;
    vector<ll > P(M, 0);
    vector<ll > X(M, 0);

    for(ll i = 0; i < M; i++){
        cin >> P[i] >> X[i];
    }

    ll sum = INF;

    for(ll i = 0; i < M; i++){
        ll t_sum = 0;
        for(ll j = 0; j < N; j++){
            if(j == P[i]-1) t_sum += X[i];
            else t_sum += T[j];
        }        
        //sum = min(sum, t_sum);
        cout << t_sum << endl;
    }
}