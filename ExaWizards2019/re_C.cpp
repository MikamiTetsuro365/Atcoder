#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
ll N, Q;
string S;
char t[19191919];
char d[19191919];

ll check(ll mid){
    //midにいる位置のゴーレムは左に飛び出して消滅するか？
    for(ll i = 0; i < Q; i++){
        if(S[mid] == t[i]){
            if(d[i] == 'L'){
                mid--;
            }else{
                mid++;
            }
        }
        if(mid < 0){
            return 1;
        }
        if(mid > N - 1){
            return 2;
        }
    }
    return 3;
}

int main() {
        
    cin >> N >> Q >> S;
    for(ll i = 0; i < Q; i++){
        cin >> t[i] >> d[i];
    }
    
    //左にはみ出て消滅するようなゴレームの中で最小の位置を探す
    ll ok = -1; ll ng = N;
    while(ok + 1 < ng){
        ll mid = (ok + ng) / 2;
        if(check(mid) == 1){
            ok = mid;
        }else{
            ng = mid;
        }
        //cout << mid << endl;
    }

    //左にはみ出ないようなゴーレムの位置の最小
    ll left = ok;
    //cout << left << endl;

    //右にはみ出て消滅するようなゴレームの中で最大の位置を探す
    ng = -1; ok = N;
    while(ng + 1 < ok){
        ll mid = (ok + ng) / 2;
        if(check(mid) == 2){
            ok = mid;
        }else{
            ng = mid;
        }
        //cout << mid << endl;
    }
    ll right = ok;
    //cout << right << endl;

    cout << max(0LL, right - left - 1) << endl;

}