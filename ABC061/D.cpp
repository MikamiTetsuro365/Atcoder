#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll MIN_INF = -1000000000000;
ll N, M; 

vector<vector<ll > > G;

bool warshall(){
    //中継点に関して
    for(ll reley = 0; reley < N; reley++){
        for(ll from = 0; from < N; from++){
            for(ll to = 0; to < N; to++){
                //大きくなる方を取っていく
                if(G[from][to] < G[from][reley] + G[reley][to]){
                    G[from][to] = G[from][reley] + G[reley][to];
                }
            }

            //s以外でスタートしたときは感がなくて良いので省く
            //もしも独立したグラフが2つあるような入力がされたとき，どっちか片方に
            //無限に増える閉路があったらご検出してしまう
            /*
            if(G[from][from] > 0){
                cout << "inf" << endl;
                return false;
            }
            */
        }
    }

    return true;
}

int main(){

    //頂点数と辺の数
    cin >> N >> M;
    G.assign(N, vector<ll >());
    
    //初期化
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(i == j){
                //自分から自分へ
                G[i].push_back(0);
            }else{
                G[i].push_back(MIN_INF);
            }
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
        G[u][v] = w;
    }

    //実行
    if(warshall() == false){
        return 0;
    }
    
    //どうせ0番目からしかスタートしないので0番目からスタートした時に無限に大きくなるような
    //閉路があるかどうかをチェックする
    if(G[0][0] > 0){
        cout << "inf" << endl;
    }else{
        cout << G[0][N-1] << endl;
    }
    

}