#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

bool check(ll N, ll K, vector<ll > A, vector<ll > F, ll mid){
    //mid（最小のコスト）にたどり着くまで何回トレーニングしなければいけないか
    ll training_cost = 0;
    for(ll i = 0; i < N; i++){
        //コストを減らす必要がない時
        if(A[i] * F[i] <= mid) continue;
        training_cost += A[i] - (mid / F[i]); 
    }

    if(training_cost > K) return false;

    return true;
}

int main(){

    ll N, K; cin >> N >> K;
    vector<ll > A(N, 0);
    vector<ll > F(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    for(ll i = 0; i < N; i++){
        cin >> F[i];
    }
    
    sort(A.rbegin(), A.rend());
    sort(F.begin(), F.end());

    //最小の値なのでleftは当てはまらない数, rigthは当てはまりそうな数
    ll left = -1; ll right = A[0] * F[F.size()-1] + 1;

    //最小値を求める
    //rightを寄せていく
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        if(check(N, K, A, F, mid)){
            right = mid;
        }else{
            left = mid;
        }
    }
    //最小値
    cout << right << endl;
}