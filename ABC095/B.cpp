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
    ll N, X;
    cin >> N >> X;
    
    ll sum = 0;
    vector<ll > A(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    }
    sort(A.begin(), A.end());
    
    cout << N + (X - sum) / A[0] << endl;

}