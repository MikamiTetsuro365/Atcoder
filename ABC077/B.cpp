#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N;
    cin >> N;

    ll mx = -1;
    for(ll i = 1; i <= sqrt(N); i++){
        mx = i * i;
    }
    cout << mx << endl;

}