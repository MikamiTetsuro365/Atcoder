#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//8近傍
ll dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
ll dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll ans[100][100];
ll input[100][100];

//シンプルに書け
int main() {

    ll H, W;
    cin >> H >> W;

    for(ll i = 1; i <= H; i++){
        string S;
        cin >> S;
        for(ll j = 1; j <= W; j++){
            input[i][j] = S[j-1];
        }
    }

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            for(ll k = 0; k < 8; k++){
                if(input[i][j] == '#') ans[i+dy[k]][j+dx[k]]++;
            }
        }
    }

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(input[i][j] == '#') cout << '#';
            else cout << ans[i][j];            
        }
        cout << endl;
    }
}