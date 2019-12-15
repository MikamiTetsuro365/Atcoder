#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N, M; cin >> N >> M;
    vector<ll > A(M, 0);
    vector<ll > used(N+1919, -1);
    //初期化
    for(ll i = 0; i < M; i++){
        cin >> A[i];
    }

    //後ろからクエリを見ていって最後に先頭になっているスレッドを表示していく
    //1度先頭になったやつはそれ以降二度と先頭に来ない
    for(ll i = M-1; i >= 0; i--){
        if(used[A[i]] == -1){
            used[A[i]] = 1;
            cout << A[i] << endl;
        }
    }

    //一度も入れ替わりが起きなかったスレッドを表示させる
    for(ll i = 1; i <= N; i++){
        if(used[i] == -1){
            cout << i << endl;
        }
    }    
}