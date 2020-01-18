#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {
    
    ll H, W, N;
    cin >> H >> W >> N;

    ll ans1 = N / H;
    if(N % H > 0) ans1++;

    ll ans2 = N / W;
    if(N % W > 0) ans2++;

    cout << min(ans1, ans2) << endl;
}