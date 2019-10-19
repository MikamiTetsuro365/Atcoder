#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1<<28;

int main(){

    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string ans;
    //初期化
    char RL = 'R';
    if(sx > tx){
        swap(sx, tx);
        RL = 'L';
    }
    char UD = 'U';
    if(sy > ty){
        swap(sx, tx);
        UD = 'D';
    }  
    //１回目の行き
    for(ll i = sx; i < tx; i++){
        ans += RL;
    }
    //はんてん
    if(RL == 'R'){
        RL = 'L';
    }else{
        RL = 'R';
    }

    for(ll i = sy; i < ty; i++){
        ans +=UD;
    }
    //はんてん
    if(UD == 'U'){
        UD = 'D';
    }else{
        UD = 'U';
    }
    //１回目の帰り
    for(ll i = sx; i < tx; i++){
        ans += RL;
    }
    if(RL == 'R'){
        RL = 'L';
    }else{
        RL = 'R';
    }
    //すこし行きすぎる
    for(ll i = sy; i <= ty; i++){
        ans += UD;
    }
    //はんてん
    if(UD == 'U'){
        UD = 'D';
    }else{
        UD = 'U';
    }

    //2回目の行き帰り（大外を通る）
    for(ll i = sx; i <= tx; i++){
        ans += RL;
    }
    //はんてん
    if(RL == 'R'){
        RL = 'L';
    }else{
        RL = 'R';
    }

    for(ll i = sy; i <= ty; i++){
        ans += UD;
    }
    //ゴールへ少し戻る
    ans+= RL;
    ans+= UD;
    //はんてん
    if(UD == 'U'){
        UD = 'D';
    }else{
        UD = 'U';
    }

    for(ll i = sx; i <= tx; i++){
        ans += RL;
    }
    //はんてん
    if(RL == 'R'){
        RL = 'L';
    }else{
        RL = 'R';
    }

    for(ll i = sy; i <= ty; i++){
        ans += UD;
    }
    ans+= RL;

    cout << ans << endl;

}