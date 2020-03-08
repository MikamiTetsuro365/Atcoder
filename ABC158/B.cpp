#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll N, A, B;
    cin >> N >> A >> B;

    ll ans = N / (A+B) * A;

    if(N % (A+B) > 0){
        if(N % (A+B) >= A){
            ans += A;
        }else{
            ans += N % (A+B);
        }
    }

    cout << ans << endl;

}