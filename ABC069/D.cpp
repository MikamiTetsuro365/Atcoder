#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
typedef pair<ll, pair<ll, ll > > iip;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll H, W, N; 
    cin >> H >> W >> N;
    
    ll s = 0;
    ll e = 0;
    vector<ll > ans(H * W, 0);
    for(ll i = 0; i < N; i++){
        ll t = 0;
        cin >> t;
        e += t;
        for(ll j = s; j < e; j++){
            ans[j] = i+1;
        }
        s = e;
    }

    //conf
    for(ll i = 0; i < H; i++){
        if(i % 2 == 0){
            for(ll j = 0; j < W; j++){
                cout << ( j ? " " : "" ) << ans[i * W + j];
            }
        }else{
            for(ll j = W; j > 0; j--){
                //cout << i * W + j - 1 << endl;
                cout << ans[i * W + j - 1] <<  ( j ? " " : "" );
            }
        }
        cout << endl;
    }
}