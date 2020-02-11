#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<double > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//片方を固定して考える
//Aokiくんが全部食べると-(sum(B))
//ここからTakahashi君が食べるとA+Bは必ず増える
//A+Bを交互に取り合う
//線形？
//「最終的に自分が得る幸福度の総和」から「最終的に相手が得る幸福度の総和」の差分
//が両者で最大になるようにするためには幸福度の和が高いものを交互に取り合えば良い
int main() {

    ll N;
    cin >> N;
    
    ll ans = 0;
    vector<ll > A(N, 0);
    vector<ll > B(N, 0);
    vector<ll > sum(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        sum[i] = A[i] + B[i];
        ans -= B[i];
    }

    sort(sum.rbegin(), sum.rend());

    for(ll i = 0; i < N; i++){
        if(i % 2 == 0) ans += sum[i];
    }

    cout << ans << endl;

}

