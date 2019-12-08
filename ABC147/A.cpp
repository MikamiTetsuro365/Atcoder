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

    ll A, B, C; cin >> A >> B >> C;
    ll ans = A + B + C;

    if(ans >= 22){
        cout << "bust" << endl;
    }else if(ans <= 21){
        cout << "win" << endl;
    }

}