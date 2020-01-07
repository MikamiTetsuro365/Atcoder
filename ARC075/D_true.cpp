#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

//二分探査
ll INF = 10e9;
ll N, A, B;
vector<ll > vec;

bool check(ll mid){

    //基本的に全員に一様に与えられるダメージ
    ll basic = mid * B;
    //cout << basic << endl;
    //mid人に与えられる追加ダメージ
    ll add = A - B;

    vector<ll > t_vec = vec;

    //撃破できた人数
    ll cn = 0;
    for(ll i = 0; i < N; i++){
        t_vec[i] -= basic;
        if(t_vec[i] <= 0){
            cn++;
            continue;
        }
        //残りの追加ダメージ数が何回必要か
        ll tmp = t_vec[i] / add;
        if(t_vec[i] % add > 0){
            tmp++;
        } 
        //追加ダメージを与えられるか与えられないならfalseを返す
        if(tmp > mid){
            return false;
        }
        //残り追加ダメージ回数を更新
        mid -= tmp;
        //体力を更新
        t_vec[i] -= add * tmp;
        //体力を0似できた人の数を更新
        cn++;
    }

    if(cn == N){
        return true;
    }

    return false;
}

int main(){

    cin >> N >> A >> B;

    for(ll i = 0; i < N; i++){
        ll t = 0;
        cin >> t;
        vec.push_back(t);
    }

    sort(vec.rbegin(), vec.rend());

    //当てはまる中で最小の境界を見つける
    //INFが大きすぎるとオーバーフローの危険性あり
    //今回はAとBが10^9の範囲まであるので10^18くらいで
    ll ng = -1; ll ok = INF;

    while(ng + 1 < ok){
        ll mid = (ng + ok) / 2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;


}