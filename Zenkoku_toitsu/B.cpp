#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<double > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N;
    string A, B, C;
    cin >> N >> A >> B >> C;

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        if(A[i] == B[i] && B[i] == C[i] && C[i] == A[i]) continue;
        if(A[i] != B[i] && B[i] != C[i] && C[i] != A[i]){
            ans += 2;
        }else{
            ans += 1;
        }
    }

    cout << ans << endl;

}