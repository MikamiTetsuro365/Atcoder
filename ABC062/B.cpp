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

    ll H, W;
    cin >> H >> W;

    vector<vector<char > > vec(119, vector<char >(119, '#'));

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            cin >> vec[i][j];
        }
    }

    for(ll i = 0; i <= H + 1; i++){
        for(ll j = 0; j <= W + 1; j++){
            cout << vec[i][j];
        }
        cout << endl;
    }

}