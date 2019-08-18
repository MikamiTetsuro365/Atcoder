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

using namespace std;
typedef long long ll;

ll flg[1145141];
vector<ll > G[1145141];
vector<ll > ans;
//flg = 1 すでに到達済み 0＝まだ到達していない
void dfs(ll idx, ll from = -1){
    /*
    ll f = 1;
    if(flg[idx] == 1){
        return 0;
    }
    */

    //参照したので到達済みフラグを１にする
    //flg[idx] = 1;

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i];
        //同じだったらもう処理しない
        //頂点に戻ってきたら
        if(to == from){
            continue;
        }

        ans[to] += ans[idx];
        dfs(to, idx);
        //閉路は無い想定なので不要！
        //from = idx > toへ
        //もしすでに到達済みの場所を参照したら、木ではなく閉路のある無向グラフ
        /*
        if(dfs(to, idx) == 1){
            //閉路ですよ
            f = 0;
        }
        */
    }
    //1が帰ったら木ですよ
    /* 
    return f;
    */

}

int main(){

    ll N, Q;
    cin >> N >> Q;
    ans.resize(N);
    //グラフを貼ります(今回は木)
    vector<ll > u(N-1);
    vector<ll > v(N-1);
    for(ll i = 0; i < N-1; i++){
        cin >> u[i];
        cin >> v[i];
        u[i]--;
        v[i]--;
        //双方向に貼りましょうね
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    //あるノードからそれ以下のノードに流し込むコストをどんどん加算していく
    for(ll i = 0; i < Q; i++){
        ll p, x;
        cin >> p >> x;
        ans[p-1] += x;
    }
    //伝搬実行
    dfs(0);
    for(ll i = 0; i < N - 1; i++){
        cout << ans[i] << " ";
    }
    
    cout << ans[N - 1] << endl;


}