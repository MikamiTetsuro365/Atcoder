#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll G[1919][1919];
ll tmp[1919][1919];
ll op[1919][1919];
ll H, W;
int main(){

    ll H, W;
    cin >> H >> W;
    //入力
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            char S; cin >> S;
            if(S == '#') G[i+2][j+2] = 1;
            else G[i+2][j+2] = 0;
        }
    }

    //最短経路
    for(ll i = 2; i < H+2; i++){
        for(ll j = 2; j < W+2; j++){
            //cout << G[i][j] ;
            if(i == 2 && j == 2){
                if(G[i][j] == 1) op[i][j] = 1;
                continue;
            }else if(i == 2 && j != 2){
                //G[i][j] += G[i][j-1];
                if(G[i][j] !=  G[i][j-1] && G[i][j] == 1) op[i][j] = op[i][j-1]+1;
                else op[i][j] = op[i][j-1];
            }else if(i != 2 && j == 2){
                if(G[i][j] !=  G[i-1][j] && G[i][j] == 1) op[i][j] = op[i-1][j]+1;
                else op[i][j] = op[i-1][j];
            }else{
                ll t1 = op[i][j-1];
                if(!(G[i][j] == 0 && G[i][j-1] == 1)){
                    t1 += G[i][j]^G[i][j-1];
                }
                ll t2 = op[i-1][j];
                if(!(G[i][j] == 0 && G[i-1][j] == 1)){
                    t2 += G[i][j]^G[i-1][j];
                }
                op[i][j] = min(t1, t2);
                //if(G[i-1][j] !=G[i][j-1])
                //G[i][j] += min(G[i-1][j],G[i][j-1]);
            }               
        }
        //cout << endl;
    }

    cout << op[H+1][W+1] << endl;

}