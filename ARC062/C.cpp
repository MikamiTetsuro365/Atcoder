#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}

int main() {

    ll N; cin >> N;
    
    //初期値
    ll T, A;
    cin >> T >> A;

    ll ans = T + A;
    for(ll i = 0; i < N - 1; i++){
        ll t, a; cin >> t >> a;
        ll cn = 1;
        for(cn;;cn++){
            if((t+a)*cn >= ans && t * cn >= T && a * cn >= A){
                //cout << ";;" << t * cn << " " << a * cn << endl;
                break;
            }
        }
        //cout << cn << endl;
        ans = (t + a)*cn;
        T = t * cn;
        A = a * cn;
        //cout << ans << endl;
    }

    cout << ans << endl;
}

