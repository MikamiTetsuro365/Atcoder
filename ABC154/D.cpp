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

    ll N, K;
    cin >> N >> K;

    ll sum = 0;
    vector<double> in;
    vector<double> in2;
    for(ll i = 0; i < N; i++){
        double t; cin >> t;
        in.push_back(t*(t+1)/2 / t);
        in2.push_back(t);
        //cout << in[i] << endl;
    }

    vector<double> r(N+19, 0);
    vector<double> r2(N+19, 0);
    for(ll i = 1; i <= N; i++){
        r[i] = r[i-1] + in[i-1];
        r2[i] = r2[i-1] + in2[i-1];
        //cout << r[i] << endl;
    }

    double ans = -1;
    ll idx = 1;
    for(ll i = K; i <= N; i++){
        //cout << (r[i] - r[idx-1]) << endl; 
        ans = max(r[i] - r[idx-1], ans);
        idx++;
    }

    cout << fixed << std::setprecision(15) << ans << endl;

}
