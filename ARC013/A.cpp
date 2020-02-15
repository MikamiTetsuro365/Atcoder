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

    ll N, M, L, P, Q, R;

    cin >> N >> M >> L >> P >> Q >> R;

    ll a = (N/P)*(M/Q)*(L/R);
    ll b = (N/P)*(M/R)*(L/Q);
    ll c = (N/Q)*(M/P)*(L/R);
    ll d = (N/Q)*(M/R)*(L/P);
    ll e = (N/R)*(M/P)*(L/Q);
    ll f = (N/R)*(M/Q)*(L/P);

    ll mx = max(a, max(b, max(c, max(d, max(e, f)))));

    cout << mx << endl;

}