#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

bool check(ll N, vector<pi > SH, ll mid){
    //mid（最小のコスト）にたどり着くまで何回トレーニングしなければいけないか
    vector<ll > t;
    for(ll i = 0; i < N; i++){
        //コストを減らす必要がない時
        //if(A[i] * F[i] <= mid) continue;
        //高度midを超える風船がある時, 高度midまでで全てを割り切ることはできない
        if(mid < SH[i].second) return false;
        //高度midまでである風船を割り切らないとイケない秒数
        t.push_back((mid - SH[i].second) / SH[i].first);
    }

    sort(t.begin(), t.end());
    //同じ秒数までに割り切らないといけない風船が複数あるときは
    //高度midまでに全ての風船を割り切ることはできない
    for(ll i = 0; i < N; i++){
        if(t[i] < i){
            return false;
        }
    }

    return true;
}

int main(){

    ll N; cin >> N;
    ll mx = 0;
    vector<ll > H(N, 0);
    vector<ll > S(N, 0);
    vector<pi > SH;
    for(ll i = 0; i < N; i++){
        cin >> H[i] >> S[i];
        SH.push_back(make_pair(S[i], H[i]));
        //cout << H[i] + S[i] * (N - 1) << endl;
        //二分探査の最大値
        mx = max(mx, H[i] + S[i] * (N - 1));
    }

    //最小の値なのでleftは当てはまらない数, rigthは当てはまりそうな数
    ll left = -1; ll right = mx + 1;

    //最小値を求める
    //rightを寄せていく
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        if(check(N, SH, mid)){
            right = mid;
        }else{
            left = mid;
        }
        //cout << right << endl;
    }
    //最小値
    cout << right << endl;
}