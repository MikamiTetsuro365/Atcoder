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

//方針：大きいノードから小さいノードに向かって有向グラフを作る
//ワーシャルフロイドで遠回りの距離を求めて，その中で最短距離が2になるものをピックアップ
//パスを復元してエッジを取り出して答えとする
//結果：一部テストケース通らず駄目でした!残念！

vector<vector<ll > > G;
vector<vector<ll > > path;

vector<vector<ll > > warshall(vector<vector<ll > > GRAPH){
    //中継点に関して
    for(ll reley = 0; reley < N; reley++){
        for(ll from = 0; from < N; from++){
            for(ll to = 0; to < N; to++){
                if(GRAPH[from][to] < GRAPH[from][reley] + GRAPH[reley][to]){
                    if(G[from][reley] != -INF && G[reley][to] != -INF){
                        GRAPH[from][to] = GRAPH[from][reley] + GRAPH[reley][to];
                        path[from][to] = path[from][reley];
                    }
                }
                //GRAPH[from][to] = max(GRAPH[from][to], GRAPH[from][reley] + GRAPH[reley][to]);
                //fromからtoへ到達する最短経路上のfromの1つ前の位置
                
            }
        }
    }

    return GRAPH;
}

vector<ll > get_path(ll start, ll end){
    vector<ll > ans;
    //endに向けて進んでいく中継地があれば拾っていく
    for(ll i = start; i != end; i = path[i][end]){
        ans.push_back(i);
    }
    
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
            }else if(j < i){
                G[i].push_back(1);
            }else{
                G[i].push_back(-INF);
            }
            //経路保存用（てきとうに初期化）
            path[i].push_back(j);
        }       
    }

    //実行
    vector<vector<ll > > wG = warshall(G);

    //距離2になるペアのノード保存用
    vector<vector<ll > > node(N);
    //辺を保存
    vector<vector<ll > > edge(N, vector<ll >(N, -1));
    ll nodeCn = 0;
    ll edgeCn = 0;

    //確認
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            //cout << wG[i][j] << " ";
            if(wG[i][j] == 2){
                node[i].push_back(j);
                vector<ll > tmp = get_path(i, j);
                //辺を保存
                for(ll i = 0; i < tmp.size()-1; i++){
                    //cout << tmp[i] << " " << tmp[i+1] << endl;
                    if(edge[tmp[i]][tmp[i+1]] == -1){
                        edge[tmp[i]][tmp[i+1]] = 1;
                        edgeCn++;
                    }
                    
                }
                nodeCn++;
            }
        }       
    }

    if(nodeCn == M){
        cout << edgeCn << endl;
        for(ll i = 0; i < N; i++){
            /*
            for(ll j = 0; j < node[i].size(); j++){
                cout <<":" << i + 1 << " " << node[i][j] + 1 << endl;
            }
            */
           for(ll j = 0; j < N; j++){
               if(edge[i][j] == 1){
                   cout << i + 1 << " " << j + 1 << endl;
               }
           }
        }
    }else{
        cout << -1 << endl;
    }

}