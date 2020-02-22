#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll mod = 1000000007;
ll INF = 1145141919454519;

//愚直にシミュレーションしてもそんなに計算量はない
int main() {

    ll A, B, C;
    cin >> A >> B >> C;

    if(A % 2 == 1 || B % 2 == 1 || C % 2 == 1){
        cout << 0 << endl;
        return 0;
    }else if(A == B && B == C && A == C){
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;

    while(true){
        
        ll t_A = B / 2 + C / 2;
        ll t_B = A / 2 + C / 2;
        ll t_C = A / 2 + B / 2;

        A = t_A;
        B = t_B;
        C = t_C;

        ans++;

        if(t_A % 2 == 1 || t_B % 2 == 1 || t_C % 2 == 1){
            cout << ans << endl;
            return 0;
        }
    }

}