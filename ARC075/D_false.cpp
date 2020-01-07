#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

//間違い解答:
//考えたこと
//体力が多いもの順から爆発を直撃させて倒していく
//その問体力がA以下になった時（倒しきれなかった）は放置
//他の敵を倒す間にBダメージを与えられて倒せそう．．．？
//駄目でした
int main(){

    ll N, A, B;
    cin >> N >> A >> B;

    priority_queue<ll > que;
    queue<ll > empty;
    queue<ll > tmp;
    //キューを空にするswap( q, empty );
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        que.push(t);
    }

    ll A_count = 0;
    while(!que.empty()){
        ll t = que.top();
        que.pop();
        cout << A_count << endl;
        if(t - A_count * B > 0){
            swap(tmp, empty);
            t -= A_count * B;
            A_count += t / A;
        }

        //爆破しきれなかったら他人の爆風でそのうち殺せるので放置
        if(t % A > 0){
            tmp.push(t % A);
        }
    }

    if(!tmp.empty()){
        A_count++;
    }

    cout << A_count << endl;

}