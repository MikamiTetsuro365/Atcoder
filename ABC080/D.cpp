#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<double, double > pi; 
typedef pair<pair<double, double >, double > pii; 
int main(){

    ll N, C;
    cin >> N >> C;

    priority_queue<pii, vector<pii>, greater<pii> >  que;
    
    //重複は削除
    map<ll, map<pair<ll, ll>, ll > > mp;
    for(ll i = 0; i < N; i++){
        ll S, T, C; cin >> S >> T >> C;
        que.push(make_pair(make_pair(S, T), C));
    }

    
    priority_queue<pii, vector<pii>, greater<pii> > t_que;
    ll n = 0;
    ll ans = 0;
    //切り替えフラグ
    bool f = false;
    //録画機に最適に割り振る処理　割り振れなくなったら新しい録画機を使う
    //優先度付きQueを使っているので最悪でもO(nlog^2)くらい？
    while(n < N){
        //cout << n << endl;
        pair<pair<double, double >, double >  tmp;
        
        if(f == false){
            tmp = que.top();
            que.pop();
            n++;
            while(!que.empty()){
                //同じチャンネル同士で終了時間と開始時間が同じ番組は継続して録画できるので
                //切り替えはしない
                ll t_t = tmp.first.second;
                ll t_s = que.top().first.first;
                if(t_t < t_s || (t_t == t_s && tmp.second == que.top().second) ){
                    //cout << "*";
                    tmp = que.top();
                    que.pop();
                    n++;
                }else{
                    t_que.push(que.top());
                    que.pop();
                }
            }
            f = true;
        }else{
            tmp = t_que.top();
            t_que.pop();
            n++;
            while(!t_que.empty()){
                ll t_t = tmp.first.second;
                ll t_s = t_que.top().first.first;
                if(t_t < t_s || (t_t == t_s && tmp.second == t_que.top().second)){
                    tmp = t_que.top();
                    t_que.pop();
                    n++;
                }else{
                    que.push(t_que.top());
                    t_que.pop();
                }
            }
            f = false;
        }
        //cout << endl;
        ans++;
    }

    cout << ans << endl;

}