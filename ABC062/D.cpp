#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//前半と後半で赤と青がまぜこぜで選ばれることはない
//Nこずつしか選ばれない
//ある地点を境界としたときそこまでで赤と青をそれぞれN個選んだときの合計値を効率良く求める

int main() {

    ll N;
    cin >> N;

    for(ll i = 0; i < N*3; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    //前から大きくなるような累積ワ
    vector<ll > maxF(N*2+19, 0);
    for(ll i = 0; i < N*2; i++){
        maxF[i+1] = vec[i] + maxF[i]; 
    }
    //小さい数字なるべく吐き出す
    priority_queue<ll, vector<ll >, greater<ll > > queF;
    for(ll i = 0; i < N*2; i++){
        if(i < N) queF.push(vec[i]);
        else{
            //今までに選ばれている数字より大きい数じが来たら更新
            ll top = queF.top();
            if(vec[i] > top){
                //次の合計値を更新（最大化）
                maxF[i+1] = maxF[i] - top + vec[i];
                queF.pop();
                queF.push(vec[i]);
            }else{
                maxF[i+1] = maxF[i];
            }
        }
   }

    //後から大きくなるような累積ワ
    vector<ll > minB(N*2+19, 0);
    for(ll i = 0; i < N; i++){
         minB[i+1] = vec[N*3-1-i] + minB[i]; 
    }
    priority_queue<ll > queB;
    //なるべく大きい数字を吐き出す
    for(ll i = 0; i < N*2; i++){
        if(i < N) queB.push(vec[N*3-1-i]);
        else{
            ll top = queB.top();
            if(vec[N*3-1-i] < top){
                //次の合計値を更新（最小化）
                minB[i+1] = minB[i] - top + vec[N*3-1-i];
                queB.pop();
                queB.push(vec[N*3-1-i]);
            }else{
                minB[i+1] = minB[i];
            }
        }
   }

    //選ぶ 
    ll ans = -INF;
    for(ll i = N; i <= N*2; i++){
        //cout << i << " " << N*3-i << endl;
        ans = max(maxF[i]-minB[N*3-i], ans);
    }
    cout << ans << endl;

}