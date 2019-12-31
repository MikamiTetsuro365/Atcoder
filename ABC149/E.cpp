#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > ruiseki;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll N, M;
//方針:M通り以上の握手ができる最小のXを見つける
ll check(ll num){
    //握手したとき（2つの数を決め打ちした時），ある数mid以上の数はいくつあるか
    //億マス計算をイメージ N*Nのマスがあって行と列で足し算して超えるか超えないか判断する
    ll sum = 0;
    //二分探査
    //cout << num << endl;
    for(ll i = 0; i < N; i++){
        ll left = 0; ll right = N;
        //最初に探索する数がmidの値より下回っているなら二分探査を実施しない
        if(vec[i] + vec[0] < num) continue;
        while(left + 1 < right){
            ll mid = (left + right) / 2;
            if(vec[i] + vec[mid] >= num){
                //vecは降順に並んでいることを忘れないで当てはまる境界値を左へ寄せていく
                left = mid;
            }else{
                right = mid;
            }            
        }
        //leftが配列上で当てはまる境界のindexなのでleft+1が当てはまっている個数ですわよ
        sum += left + 1;
    }

    /*
    if(sum <= M){
        return true;
    }else{
        return false;
    }
    */

   return sum;

}

ll calculator(ll num){
    //二分探査で割り出したM個ぴったり選ぶことのできる数Kを使って総和を計算
    //行のある数 * 列上でどこまであてはまるかの数 + 累積和 = 総和
    ll sum = 0;

    for(ll i = 0; i < N; i++){
        //M以下に当てはまる最大の値
        ll left = 0; ll right = N;
        if(vec[i] + vec[0] < num) continue;

        while(left + 1 < right){
            ll mid = (left + right) / 2;
            if(vec[i] + vec[mid] >= num){
                left = mid;
            }else{
                right = mid;
            }            
        }
        sum += vec[i] * (left + 1) + ruiseki[left];
    }

    return sum;

}

int main() {

    cin >> N >> M;
    //配列で言うP-1までは採用対象
    vec.assign(N, 0);
    ruiseki.assign(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> vec[i];
    }
    sort(vec.rbegin(), vec.rend());

    //累積和準備
    for(ll i = 0; i < N; i++){
        if(i == 0){
            ruiseki[0] = vec[0];
        }else{
            ruiseki[i] = ruiseki[i-1] + vec[i];
        }
        //cout << ruiseki[i] << endl;
    }

    //ある数midを与えた時それを満たすような握手のペアがいくつあるか？
    //今回は握手する回数がMで固定なのでM以下であるような境界を見つける
    //Mになるようなmidはたくさんあります.あくまでもM個になる最大値Kが見つかるだけ
    //条件を満たすような数で最小値を求めたい．その時，その最小値でペアを選ぶとM個以下であるとなお良い
    //二分探査ではどの数までならM以下になるか，どの数で初めてM個を超えるかしかわからない
    //ので誤差が（小さくなる方向で）生じる時がある.
    ll left = 0; ll right = INF;
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        //cout << left << " " << right << " " << check(mid) << endl;
        if(check(mid) <= M){
            right = mid;
        }else{
            left = mid;
        }
        //cout << check(mid) << endl;
        //cout << left << " " << right << endl;
    }

    ll ans = 0;

    //cout << left << " " << right << " " << calculator(right) << endl;
    //cout << check(right) << endl;
    //cout << check(left) << " " << check(right) << endl;
    cout << calculator(right) + (M - check(right)) * (right - 1)<< endl;
    //ではどのようなmidを実際にM個選んだ時の最大値を知ることができるか
    //cout << calculator(right) << endl;

}