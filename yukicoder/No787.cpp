#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll N, M;

int main(){

    double P, Q; cin >> P >> Q;
    P *= 0.01;
    Q *= 0.01;

    double ans = (P * Q) / (P * Q + (1-P) * (1-Q));
    ans *= 100;

    cout << fixed << setprecision(20) << ans << endl;

}