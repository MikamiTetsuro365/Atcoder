#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi; 
typedef pair<pair<double, double >, double > pii; 

int main(){

    ll N, C;
    cin >> N >> C;

    //入力　チャンネルごと
    vector<priority_queue<pi, vector<pi>, greater<pi > > > input(C);
    for(ll i = 0; i < N; i++){
        ll S, T, C; cin >> S >> T >> C;
        input[C-1].push(make_pair(S-1, T-1));
    }

    //前処理
    //連続して録画できる映像をまとめる
    vector<vector<ll > > memo(C, vector<ll >(100010, 0));
    for(ll i = 0; i < C; i++){
        ll t_1 = 0;
        while(!input[i].empty()){
            ll s = input[i].top().first;
            ll t = input[i].top().second;
            //cout << s << " " << t << endl;
            input[i].pop();
            memo[i][t+1]--;
            //開始時間が前の終了時刻より小さい/同じだったら連続して録画できる
            if(s <= t_1){
                //-1を書き込んでいたところを0に戻して連続に
                memo[i][t_1 + 1]++;
            }else{
                //連続して録画できないなら新しい開始時刻をチェックする
                memo[i][s]++;
            }
            //更新
            t_1 = t;
        }
    }

    //計算　いもす法
    vector<ll > t_ans(100010, 0);
    for(ll i = 1; i < 100010; i++){
        ll sum = 0;
        for(ll j = 0; j < C; j++){
            sum += memo[j][i];
        }
        //1つ前の区間を今見てるところと足して挿入
        sum += t_ans[i-1];
        t_ans[i] = sum;
    }

    //重なりが一番多いところを探す
    ll mx = 0;
    for(ll i = 1; i <100010; i++){
        mx = max(mx, t_ans[i]);
    }

    cout << mx << endl;

}