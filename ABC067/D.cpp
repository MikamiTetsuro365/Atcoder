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
#include <map>
 
using namespace std;
typedef long long int ll;
ll f_flg[1145141];
ll s_flg[1145141];
vector<ll > G[1145141];
//各スタート位置から対戦相手のノードに到るまで繋がっているノードの総数
ll Fennec = -1;
ll Snuke = -1;
//FennecがSnukeまでたどり着くのに到達するまでにどの頂点を通ったか？とスターチ位置からの距離を格納するやつ
vector<pair <ll, ll > > where(1145141);
//取り合うことで勝負が決まる　ノードとノードで挟まれた回廊
ll battleZone[1145141];
ll N = 0;
ll ans = 0;
//flg = 1 すでに到達済み 0＝まだ到達していない
//player == 0 Fennec, player == 1 sunuke

ll dfs(ll idx, ll end , ll from = -1){
    
    //どこからどこへ行く？
    if(idx != 1) where[idx] = make_pair(from, battleZone[from]);  

    if(idx == end){
        //伝搬させておくと楽
        battleZone[idx] = battleZone[from];
        return 0;
    }

    if(from != -1){
        //はじめ以外伝搬
        battleZone[idx] = battleZone[from] + 1;
    }  

    if(f_flg[idx] == 1){
        return 0;
    }
    f_flg[idx] = 1;

    //cout << from << endl;
    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i];

        //同じだったらもう処理しない
        if(to == from){
            continue;
        }
        dfs(to, end, idx);
        ans++;
    }
    
    return 0;
}
 
int main(){
 
    cin >> N;
    vector<ll > u(N-1);
    vector<ll > v(N-1);
 
    for(ll i = 0; i < N-1; i++){
        cin >> u[i];
        cin >> v[i];
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
 
    battleZone[0] = 0;
    battleZone[1] = 0;
    //Fennecが塗りつぶせる数 スタート：ノード１
    dfs(1, N);
    
    ll j = N;
    ll battaleZoneDistance = 0;
    vector<ll > battleZoneNode;

    while(j != 1){
        if(where[j].first != 0){
            //cout << where[j].first << endl;
            battleZoneNode.insert(battleZoneNode.begin(), where[j].first);
            j = where[j].first;
            battaleZoneDistance++;
        }
        if(where[j].first == 1){
            break;
        }
    }

    ll trueGoal = battleZoneNode[where[N].second / 2 + where[N].second % 2 ];
    //フラグ初期化
    for(ll i = 0; i < 1145141; i++){
        f_flg[i] = 0;
    }
    //cout << ans << endl;
    ans = 0;
    dfs(1,trueGoal);
    //cout << ans << "," << trueGoal << endl;

    if(N - ans - 1 < ans - 1){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
 
 
} 