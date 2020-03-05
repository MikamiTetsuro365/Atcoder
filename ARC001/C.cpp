#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

vector<vector<ll > > ans;
map<ll, ll> mp;
bool f = false;

void dfs(vector<ll > g, ll r = -1, ll d = -1){
    
    //判定
    if(d != -1) g.push_back(r);
    //列挙終了->条件を満たすか確認
    if(d == 7){
        vector<vector<ll > > G(8, vector<ll >(8, 0));
        for(ll i = 0; i < 8; i++){
            ll j = g[i];
            //縦横ナナメ45度にクイーンがいないか確認
            for(ll k = 0; k < 8; k++){
                //縦横
                if(G[i][k] == 1 || G[k][j] == 1) return;
                // \みたいな斜め
                if(i-k >= 0 && j+k < 8) if(G[i-k][j+k] == 1) return; 
                if(i+k < 8 && j-k >= 0) if(G[i+k][j-k] == 1) return;
                // /みたいな斜め
                if(i+k < 8  && j+k < 8)  if(G[i+k][j+k] == 1) return; 
                if(i-k >= 0 && j-k >= 0) if(G[i-k][j-k] == 1) return;
            }

            G[i][j] = 1;
        }

        f = true;
        ans = G;
        return;
    }
    //すでに置かれている3つか？
    auto it = mp.find(d + 1);
    if(it != mp.end()){
        //cout << it->second << endl;
        dfs(g, it->second, d + 1);
    }else{
        for(ll i = 0; i < 8; i++){
            dfs(g, i, d + 1);
        }
    }

    return;
}

int main(){

    for(ll i = 0; i < 8; i++){
        for(ll j = 0; j < 8; j++){
            char c; cin >> c;
            if(c == 'Q') mp[i] = j;
        }
    }

    vector<ll > g;
    dfs(g);

    if(f == false){
        cout << "No Answer" << endl;
    }else{
        //cout << "Yes Answer" << endl;
        for(ll i = 0; i < 8; i++){
            for(ll j = 0; j < 8; j++){
                if(ans[i][j] == 0) cout << ".";
                else cout << "Q";
            }            
            cout << endl;
        }
    }


}