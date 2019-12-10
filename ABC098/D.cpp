#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {

    ll N; cin >> N;
    vector<ll > A(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    //ll left = 0;
    ll right = 0;
    ll SUM = 0;
    ll XOR = 0;
    ll ans = 0;

    for(ll left = 0; left < N; left++){
        //rightがデータ数の最大を超えず 条件を満たし続ける限り右へ伸ばし続ける
        while(right < N && (SUM + A[right]) == (XOR ^ A[right])){
            SUM += A[right];
            XOR ^= A[right];
            right++;
        }

        //leftからrightまでの条件を満たす個数
        ans += right - left;
        
        //right側が条件を満たさない限りleftを右へ伸ばし続ける
        if(right == left){
            right++;
        }else{
            SUM -= A[left];
            //同じものをXORするともとに戻る
            XOR ^= A[left];
        }
    }

    cout << ans << endl;
}