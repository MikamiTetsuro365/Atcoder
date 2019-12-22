#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

vector<ll > A;
vector<ll > B;
ll N, K;
//二分探査of二分探査
//行ごとに列ごとにそれぞれに単調性があります
//小さい方からK番目ということは数字がK個あるということ
//よってある数列においてある数X以下の数字がK個に近づく（になる）位置はどこでしょうかという問題
//二分探査で求めていく！
//逆に考えてX以上になる数がK個以上になる最大？
ll check(ll mid){
    //mid以下の個数
    ll sum = 0;
    for(ll i = 0; i < N; i++){
        // a * b <= mid -> b <= mid / a に式変形できる
        // mid / a以下のbを探す
        ll tmp = mid / A[i];
        //mid以下つまりtmp以下になるような個数
        //二分探査
        sum += upper_bound(B.begin(), B.end(), tmp) - B.begin();
    }

    if(K <= sum){
        return true;
    }
    return false;
}

int main(){
     
    cin >> N >> K;

    A.assign(N, 0);
    B.assign(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    for(ll i = 0; i < N; i++){
        cin >> B[i];
    }

    //予めソート
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    //条件を満たすような最小値を求める
    ll left = -1; ll right = A[N-1] * B[N-1];
 
    //最小値を求める
    //rightを寄せていく
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        if(check(mid)){
            right = mid;
        }else{
            left = mid;
        }
    }

    cout << right << endl;

}