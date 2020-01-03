#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x3 = x2 - (y2 - y1);
    ll y3 = y2 + (x2 - x1);
    ll x4 = x3 - (y3 - y2);
    ll y4 = y3 + (x3 - x2);

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}