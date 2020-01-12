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

    char out[1000][1000];

    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            cin >> out[i][j];
        }        
    }

    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            cout << out[i][j];
        } 
        cout << endl;   
        for(ll j = 0; j < W; j++){
            cout << out[i][j];
        }       
        cout << endl;   
    }

}