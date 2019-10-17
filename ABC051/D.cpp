#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = INFINITY;
ll N, M; 

vector<vector<ll > > G;
vector<vector<ll > > path;

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
    cout << end << endl;
    ans.push_back(end);
    return ans;
}

int main(){

    //頂点数と辺の数
    cin >> N >> M;

    G.assign(N, vector<ll >());
    path.assign(N, vector<ll >());
    
    //初期化
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(i == j){
                //自分から自分へ
                G[i].push_back(0);
            }else{
                G[i].push_back(INF);
            }
            path[i].push_back(j);
        }       
    }
    //cout << G.size() << " " << G[0].size() << endl;
    //辺入力
    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        //適宜揃える
        u--;
        v--;
        //有向か無向かでコメントアウト　多重辺も防止
        G[u][v] = min(G[u][v], w);
        G[v][u] = min(G[v][u], w);
    }

    //実行
    if(warshall() == false){
        return 0;
    }

    //確認
    
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(G[i][j] == INF){ 
                cout <<  ( j ? " " : "" ) << "INF"; 
            }else{
                cout <<  ( j ? " " : "" ) <<  G[i][j]; 
            }
            
        }       
        cout << endl;
    }
    
    /*
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            G[i][path[i][j]] = -1;
            G[path[i][j]][i] = -1;
        }       
    }

    //確認
    ll ans = 0;    
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            cout <<  ( j ? " " : "" ) <<  G[i][j]; 
            if(G[i][j] != -1) ans++;
        }
        cout << endl;
    }
    cout << ans << endl;
    */
    //get_path(0, 2);

}