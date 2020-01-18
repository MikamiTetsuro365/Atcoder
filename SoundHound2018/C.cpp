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

    double n, m, d; cin >> n >> m >> d;

    double ans = 0;

    if(d == 0){
        ans = n*(m-1) / (n*n);

    }else{
        ans = (2 * (n-d) * (m-1)) / (n*n);
    }

    cout << fixed << setprecision(10) << ans << endl;

}