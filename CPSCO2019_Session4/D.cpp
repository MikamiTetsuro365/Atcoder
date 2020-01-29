#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll N, K;
vector<ll > t;
//退屈さをX以下にするためには連続した要素をX毎に区切ることができると良い
//X+1個目の数字を変更していくと良い
//K回ですべて区切ることができるとYes
//できないとNo
bool check(ll mid){
    ll cn = 0;
    for(ll i = 0; i < t.size(); i++){
        cn += t[i]/(mid+1);
    }
    if(cn > K){
        return false;
    }
    return true;
}

int main() {
    
    cin >> N >> K;
    
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    //圧縮
    ll mx = -1;
    for(ll i = 0; i < N;){
        ll j = i;
        while(j < N && vec[i] == vec[j]) j++;
        //連続した個数
        mx = max(mx, j - i);
        t.push_back(j-i);
        //次の始点
        i = j;
    }

    //二分探査 最小
    //退屈さをX以下にできるか?
    ll ng = 0; ll ok = mx;
 
    //最小値を求める
    //rightを寄せていく
    while(ng + 1 < ok){
        ll mid = (ng + ok) / 2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    //最小値
    cout << ok << endl;

}