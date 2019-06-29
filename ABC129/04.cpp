#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>

using namespace std;
typedef long long ll;
ll sum = 0;

int main(){

    ll H, W;
    cin >> H >> W;
    string s;

    vector<vector<ll > > grid(H+1, vector<ll >(W+1, -1));
    vector<vector<ll > > sum_grid(H+1, vector<ll >(W+1, -1));
    for(ll i = 0; i < H; i++){
        cin >> s;
        for(ll j = 0; j < s.length(); j++){
            if(s[j] == '.'){
                grid[i][j] = 1;
            }
        }
    }

    //横計算
    for(ll i = 0; i < H; i++){
        //すでに加算し終わっていたら
        vector <bool > done(W, false);
        for(ll j = 0; j < W; j++){
            if(grid[i][j] == -1){
                done[j] = true;
                continue;
            }
            if(done[j] == true){
                continue;
            }
            ll l = 0;
            while(j + l < W ){
                if(grid[i][j+l] == -1) break;
                ++l;
            }
            //反映
            for(ll k = 0; k < l; k++){
                sum_grid[i][j + k] = l;
                done[j + k] = true;
            }
        }
    } 
    //縦計算
    for(ll j = 0; j < W; j++){
        //すでに加算し終わっていたら
        vector <bool > done(W, false);
        for(ll i = 0; i < H; i++){
            if(grid[i][j] == -1){
                done[i] = true;
                continue;
            }
            if(done[i] == true){
                continue;
            }
            ll l = 0;
            while(i + l < H ){
                if(grid[i + l][j] == -1) break;
                ++l;
            }
            //反映
            for(ll k = 0; k < l; k++){
                sum_grid[i + k][j] += l;
                done[i + k] = true;
            }
        }
    } 

    ll ans = 0;
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            ans = max(sum_grid[i][j]- 1, ans);
        }
    }   

    cout << ans << endl;

    //確認
    /*
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            cout << h_grid[i][j] << "  ";
        }
        cout << endl;
    }
    */
    
} 