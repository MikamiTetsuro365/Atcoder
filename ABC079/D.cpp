#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419191919;
ll N, M; 

vector<vector<ll > > G;
vector<vector<ll > > path;

//ワーシャルフロイドでひょいっと

bool warshall(){
    //中継点に関して
    for(ll reley = 0; reley < N; reley++){
        for(ll from = 0; from < N; from++){
            for(ll to = 0; to < N; to++){
                //中継した方がコストがかからないか否か
                //小さい順からコストが自明に決まっていく
                if(G[from][to] > G[from][reley] + G[reley][to]){
                    //負の辺対策 INFINITY＋INFINITYはマイナスになるので
                    //たまに最短距離を更新してしまう. 
                    if(G[from][reley] != INF && G[reley][to] != INF){
                        G[from][to] = G[from][reley] + G[reley][to];
                        //fromからtoへ到達する最短経路上のfromの1つ前の位置
                        path[from][to] = path[from][reley];
                    }
                }
            }

            //負の閉路がある時
            if(G[from][from] < 0){
                cout << "NEGATIVE CYCLE" << endl;
                return false;
            }
        }
    }

    return true;
}

vector<ll > get_path(ll start, ll end){
    vector<ll > ans;
    //endに向けて進んでいく中継地があれば拾っていく
    for(ll i = start; i != end; i = path[i][end]){
        cout << i << endl;
        ans.push_back(i);
    }
     ans.push_back(end);
    return ans;
}

int main(){

    //頂点数と辺の数
    ll H, W;
    cin >> H >> W;

    N = 10;

    G.assign(N, vector<ll >());
    path.assign(N, vector<ll >());
    
    //初期化
    for(ll i = 0; i <= 9; i++){
        for(ll j = 0; j <= 9; j++){
            if(i == j){
                //自分から自分へ
                G[i].push_back(0);
            }else{
                G[i].push_back(INF);
            }
            path[i].push_back(j);
        }       
    }

    //辺入力
    for(ll i = 0; i <= 9; i++){
        for(ll j = 0; j <= 9; j++){
            ll w; cin >> w;
            //有向か無向かでコメントアウト　多重辺も防止
            G[i][j] = min(G[i][j], w);
            //G[j][i] = min(G[j][i], w);
        }
    }

    //実行
    if(warshall() == false){
        return 0;
    }


    ll ans = 0;
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            ll t; cin >> t;
            if(t == 1 || t == -1) continue;
            ans += G[t][1];
        }
    }

    cout << ans << endl;

}