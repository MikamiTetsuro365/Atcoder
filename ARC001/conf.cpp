#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){
    
    // for(ll i = 0; i < 8; i++){
    //     for(ll j = 0; j < 8; j++){
    //         vector<vector<ll > > G(8, vector<ll >(8, 0));
    //         ll cn = 0;
    //         // /みたいな斜め
    //         for(ll k = 0; k < 8; k++){
    //             if(i-k >= 0 && j+k < 8) G[i-k][j+k] = 1;
    //             if(i+k < 8 && j-k >= 0) G[i+k][j-k] = 1;
    //         }
    //         for(ll u = 0; u < 8; u++){
    //             for(ll n = 0; n < 8; n++){
    //                 cout << G[u][n] << " ";
    //             }            
    //             cout << endl;
    //         }
    //         cout << endl;
    //     }
    // }

    for(ll i = 0; i < 8; i++){
        for(ll j = 0; j < 8; j++){
            vector<vector<ll > > G(8, vector<ll >(8, 0));
            ll cn = 0;
            // /みたいな斜め
            for(ll k = 0; k < 8; k++){
                if(i+k < 8  && j+k < 8)  G[i+k][j+k] = 1; 
                if(i-k >= 0 && j-k >= 0) G[i-k][j-k] = 1;
            }
            for(ll u = 0; u < 8; u++){
                for(ll n = 0; n < 8; n++){
                    cout << G[u][n] << " ";
                }            
                cout << endl;
            }
            cout << endl;
        }
    }

}