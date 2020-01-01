#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

//奇数同士でマッチングを取るために最短経路を求めて...とか考えていたがそんな必要なかったんやが
//縦と横に順番に奇数を運んでマッチングとっていくだけ
//偶数個奇数があれば全部偶数にできるし奇数個だと1つ余る
int main(){

    ll H, W; cin >> H >> W;

    vector<vector<ll > > vec(H, vector<ll >(W, 0));

    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            ll t; cin >> t;
            if(t % 2 == 0){
                vec[i][j] = 0;
            }else{
                vec[i][j] = 1;
            }
        }
    }

    //右端へ奇数をまとめる
    ll N = 0;
    vector<vector<ll > > ans(191919, vector<ll >(4, 0));

    ll sx, sy;
    for(ll i = 0; i < H; i++){
        bool f = false;
        for(ll j = 0; j < W; j++){ 
            if(f == false){
                if(vec[i][j] == 1){
                    sy = i + 1;
                    sx = j + 1;
                    //vec[i][j] = 0;
                    f = true;
                }
            }else if(f == true){
                ans[N][0] = sy;
                ans[N][1] = sx;
                ans[N][2] = i+1;
                ans[N][3] = j+1;
                N++;
                //cout << sy << " " << sx << " " << i + 1 << " " << j + 1 << endl;
                vec[i][j] += 1;
                sy = i + 1;
                sx = j + 1;
                if(vec[i][j] % 2 == 0){
                    vec[i][j] = 0;
                    f = false;
                }
            }
        }
    }

    //右端の奇数を縦にまとめる
    bool f = false;
    for(ll i = 0; i < H; i++){
            if(f == false){
                if(vec[i][W-1] == 1){
                    sy = i + 1;
                    sx = W;
                    //vec[i][W-1] = 0;
                    f = true;
                }
            }else if(f == true){
                ans[N][0] = sy;
                ans[N][1] = sx;
                ans[N][2] = i+1;
                ans[N][3] = W;
                N++;
                //cout << sy << " " << sx << " " << i + 1 << " " << W << endl;
                vec[i][W-1] += 1;
                sy = i + 1;
                sx = W;
                if(vec[i][W-1] % 2 == 0){
                    //vec[i][W-1] = 0;
                    f = false;
                }
            }        
    }


    /*
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            cout << vec[i][j];
        }
        cout << endl;
    }
    */

    //表示
    cout << N << endl;
    for(ll i = 0; i < N; i++){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;       
    }


}