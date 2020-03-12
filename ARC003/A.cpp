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

    double ans = 0;

    for(ll i = 0; i < N; i++){
        char r; cin >> r;
        if(r == 'A') ans += 4;
        else if(r == 'B') ans += 3;
        else if(r == 'C') ans += 2;
        else if(r == 'D') ans += 1;
        else if(r == 'F') ans += 0;
    }

    cout << fixed << setprecision(15) << ans / N << endl;

}