#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll N, M;

int main(){

    ll H, W; cin >> H >> W;
    vector<vector<ll > > input(H, vector<ll >(W, 0));
    //余白をもたせる
    vector<vector<ll > > O(H+1, vector<ll >(W+1, 0));
    vector<vector<ll > > I(H+1, vector<ll >(W+1, 0));

    // orb = 1 ingot = -1
    for(ll row = 1; row <= H; row++){
        for(ll col = 1; col <= W; col++){
            char t; cin >> t;
            O[row][col] = O[row][col-1];
            I[row][col] = I[row-1][col];
            if(t == 'O'){
                input[row-1][col-1] = 1;
                O[row][col]++;
            }else if(t == 'I'){
                input[row-1][col-1] = -1;
                I[row][col]++;
            } 
            //前処理も同時に
        }        
    }

    ll ans = 0;
    for(ll row = 1; row <= H; row++){
        for(ll col = 1; col <= W; col++){
            ll orb = 0;
            ll ingot = 0;
            if(input[row-1][col-1] == 0){
                orb = O[row][W] - O[row][col-1];
                ingot = I[H][col] - I[row-1][col];
                ans += orb * ingot;
            }
        }        
    }

    cout << ans << endl;

    //確認
    /*
    for(ll row = 1; row <= H; row++){
        for(ll col = 1; col <= W; col++){
            cout << O[row][col] << " ";
        }
        cout << endl;
    }

    for(ll row = 1; row <= H; row++){
        for(ll col = 1; col <= W; col++){
            cout << I[row][col] << " ";
        }
        cout << endl;
    }
    */
}