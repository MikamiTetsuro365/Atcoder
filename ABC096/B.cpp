#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    vector<ll > ABC(3, 0);
    cin >> ABC[0] >> ABC[1] >> ABC[2];
    sort(ABC.begin(), ABC.end());

    ll K;
    cin >> K;

    cout << ABC[0] + ABC[1] + pow(2, K) * ABC[2] << endl;

}