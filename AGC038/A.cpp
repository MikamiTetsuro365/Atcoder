#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll H, W, A, B;
    cin >> H >> W >> A >> B;

    ll n_rows = H;
    ll n_cols = W;
    ll value = 0;
    vector<vector<ll > > vec(H, vector<ll >(W, 0));;

    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            if(i < B && j < A){
                vec[i][j] = 0;
            }else if(i >= B && j < A){
                vec[i][j] = 1;
            }else if(i < B && j >= A){
                vec[i][j] = 1;
            }else if(i >= B && j >= A){
                vec[i][j] = 0;
            }
        }  


    }

    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            cout << vec[i][j];
        }  
        cout << endl;
    }

} 