#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

vector<vector<ll > > tG;

bool check(ll i, ll j){

    bool f = true;
    //縦横
    for(ll k = 0; k < 8; k++){
        if(tG[i][k] == 2 || tG[k][j] == 2){
            f = false;
        }
        tG[i][k] = 1;
        tG[k][j] = 1;
    }
    // \みたいな斜め
    ll cn = 0;
    for(ll k = max(0LL, i-j); k < i + min(8-i, 8-j); k++){
        //cout << k << " " << j-min(i, j)+cn << endl;
        if(tG[k][j-min(i, j)+cn] == 2){
            f = false;
        }
        tG[k][j-min(i, j)+cn] = 1;
        cn++;
    }
    // /みたいな斜め
    cn = 0;
    for(ll k = max(0LL, i-8-j); k < i + min(i, j); k++){
        if(tG[k][j+min(i, 8-j)+cn] == 2){
            f = false;
        }
        tG[k][j+min(i, 8-j)+cn] = 1;
        cn--;
    }
    tG[i][j] = 2;
    return f;
}

int main(){

    vector<vector<ll > > G(8, vector<ll >(8, 0));

    bool f = true;
    for(ll i = 0; i < 8; i++){
        for(ll j = 0; j < 8; j++){
            char c; cin >> c;
            if(c == 'Q'){
                //縦横
                for(ll k = 0; k < 8; k++){
                    if(G[i][k] == 2 || G[k][j] == 2){
                        f = false;
                    }
                    G[i][k] = 1;
                    G[k][j] = 1;
                }
                // \みたいな斜め
                ll cn = 0;
                for(ll k = max(0LL, i-j); k < i + min(8-i, 8-j); k++){
                    //cout << k << " " << j-min(i, j)+cn << endl;
                    if(G[k][j-min(i, j)+cn] == 2){
                        f = false;
                    }
                    G[k][j-min(i, j)+cn] = 1;
                    cn++;
                }
                // /みたいな斜め
                cn = 0;
                for(ll k = max(0LL, i-8-j); k < i + min(i, j); k++){
                    if(G[k][j+min(i, 8-j)+cn] == 2){
                        f = false;
                    }
                    G[k][j+min(i, 8-j)+cn] = 1;
                    cn--;
                }
                G[i][j] = 2;
            }

        }
    }

    if(f == false){
        cout << "No Answer" << endl;
        return 0;
    }

    //答えの候補を決めて
    vector<vector<pi > > kouho;
    for(ll i = 0; i < 8; i++){
        vector<pi > t;
        for(ll j = 0; j < 8; j++){
            if(G[i][j] == 0){
                t.push_back(make_pair(i, j));
            }
        }
        if(t.size() > 0){
            kouho.push_back(t);
        }
    }
    for(ll i = 0; i < 8; i++){
        for(ll j = 0; j < 8; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }

    //全探査
    for(ll i = 0; i < kouho[0].size(); i++){
        cout << kouho.size() << endl;
        //cout << kouho[0].size() << kouho[1].size() << kouho[2].size() << kouho[3].size() << endl;
        for(ll j = 0; j < kouho[1].size(); j++){
            for(ll k = 0; k < kouho[2].size(); k++){
                for(ll n = 0; n < kouho[3].size(); n++){
                    for(ll m = 0; m < kouho[4].size(); m++){
                        tG = G;
                        cout << i << j << k << n << m << endl;
                        if(tG[kouho[0][i].first][kouho[0][i].second] > 0) continue;
                        bool f1 = check(kouho[0][i].first, kouho[0][i].second);
                        if(tG[kouho[1][j].first][kouho[1][j].second] > 0) continue;
                        bool f2 = check(kouho[1][j].first, kouho[1][j].second);
                        if(tG[kouho[2][k].first][kouho[2][k].second] > 0) continue;
                        bool f3 = check(kouho[2][k].first, kouho[2][k].second);
                        if(tG[kouho[3][n].first][kouho[3][n].second] > 0) continue;
                        bool f4 = check(kouho[3][n].first, kouho[3][n].second);
                        if(tG[kouho[4][m].first][kouho[4][m].second] > 0) continue;
                        bool f5 = check(kouho[4][m].first, kouho[4][m].second);
                        // if((f1 & f2 & f3 & f4 & f5) == true){
                        //     cout << "yea!" << endl;
                        //     return 0;
                        // }
                    }
                }
            }
        }
    }

    cout << "No Answer" << endl;
    return 0;

}