#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = ll(1e18)+1919;

//なるべく右端を見つける
ll plus_check(ll tmp, ll comp, ll ok, ll ng){
    while(ok + 1 < ng){
        ll mid = (ng + ok) / 2;
        if(tmp * vec[mid] <= comp){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

//なるべく左端を見つける
ll minus_check(ll tmp, ll comp, ll ok, ll ng){
    while(ng + 1 < ok){
        ll mid = (ng + ok) / 2;
        if(tmp * vec[mid] <= comp){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    return ok;
}

int main() {

    ll N, K;
    cin >> N >> K;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());

    //K個目になる(条件を満たす)最小値
    ll ng = -INF; ll ok = INF;
    while(ng + 1 < ok){
        ll mid = (ng + ok) / 2;
        //midを満たすような（以下になる）組み合わせはいくつ？
        ll cn = 0;
        //さらに二分探査
        for(ll i = 0; i < N - 1; i++){
            ll tmp = vec[i];
            //プラスとマイナスで二分探査の向きが逆転
            if(tmp > 0){
                //プラスのとき
                if(tmp * vec[i+1] > mid) continue; //そもそも条件を最初から満たしていないとき,自分かける自分はされないのでvec[i+1]
                else if(tmp * vec[N-1] <= mid) cn += N-i-1; //全て条件を満たしているとき
                else{
                    //条件を満たす中で最大の値
                    ll ok2 = i + 1; ll ng2 = N - 1;
                    while(ok2 + 1 < ng2){
                        ll mid2 = (ng2 + ok2) / 2;
                        if(tmp * vec[mid2] <= mid){
                            ok2 = mid2;
                        }else{
                            ng2 = mid2;
                        }
                    }
                    cn += ok2 - i;
                    //cn += plus_check(tmp ,mid ,i+1 , N-1) - i;
                }
            }else if(tmp == 0){
                //0が条件に当てはまる可能性があるとき
                if(0 <= mid) cn += N-i-1;
            }else{
                //マイナスのとき
                if(tmp * vec[N-1] > mid) continue;
                else if(tmp * vec[i+1] <= mid) cn += N-i-1;
                else{
                    //cn += N - minus_check(tmp ,mid ,i+1 , N-1);
                    ll ng2 = i + 1; ll ok2 = N - 1;
                    while(ng2 + 1 < ok2){
                        ll mid2 = (ng2 + ok2) / 2;
                        if(tmp * vec[mid2] <= mid){
                            ok2 = mid2;
                        }else{
                            ng2 = mid2;
                        }
                    }
                    cn += N - ok2;
                }
            }
        }

        //条件を満たしているか？
        //cn--;
        if(cn >= K){
            ok = mid;
        }else{
            ng = mid;
        }
        //cout << mid << " " << cn << endl;
    }
    //最小値
    cout << ok << endl;    

}
