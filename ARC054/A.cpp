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

    double L, X, Y, S, D;
    cin >> L >> X >> Y >> S >> D;

    //スタート位置より後ろにある時
    double ans = INF;
    if(S > D){
        if(X < Y) ans = (S - D) / (Y - X);
        ans = min(ans, (L - S + D) / (X + Y));
    }else{
        if(X < Y) ans = (S + L - D) / (Y - X);
        ans = min(ans, (D - S) / (X + Y));        
    }

    cout << fixed << setprecision(15) << ans << endl;

}