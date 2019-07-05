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
    
    //計算終了
    /*
    if(idx == end){
        //伝搬させておくと楽
        battleZone[idx] = battleZone[from];
        return 0;
    }
    */

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
        //どこからどこへ行く？
        where[to] = make_pair(idx, battleZone[idx]);
        //同じだったらもう処理しない
        if(to == from){
            continue;
        }
        //ここで終わり
        if(to == end){
            //伝搬させておくと楽
            battleZone[to] = battleZone[from];
            return 0;
        } 
        dfs(to, end, idx);
        
 
    }
    ans++;
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
 
    ll ans = 0;
    battleZone[0] = 0;
    battleZone[1] = 0;
    //Fennecが塗りつぶせる数 スタート：ノード１
    dfs(1, N);
    //dfs(N, 1);
    /*
    cout << battleZone[4] << endl;
    cout << battleZone[5] << endl;
    cout << battleZone[6] << endl;
    cout << battleZone[8] << endl;
    cout << battleZone[12] << endl;
    cout << battleZone[11] << endl;
    */
    
    ll j = N+1;
    vector<ll > battleZoneNode;
    while(j != 0){
        battleZoneNode.push_back(where[j].second);
        j = where[j].second;
        cout << where[j].second << endl;
    }
    
    
    for(ll i = 0; i <= N + 1; i++){
        cout << i << ":" << where[i].first << "," << where[i].second << endl;
    }
    cout << ans << endl;
    
    //cout << battleZone[N] << "," << Fennec << "," << Snuke << endl;
    //勝者は？？
    //最終的に取れるノード
    //Fennec = Fennec - battleZone[N] + battleZone[N] / 2 + battleZone[N] % 2;
    //Snuke = Snuke - battleZone[N] + battleZone[N] / 2;
    if(Fennec > Snuke){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
 
 
} 