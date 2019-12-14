#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//どの変数を先に求めると後々がすべて決まるか考える（そんな高尚なことでもない
int main() { 

    double N, A, B; cin >> N >> A >> B;
    ll sum = 0;
    vector<ll > V(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> V[i];
        sum += V[i];
    }
    sort(V.begin(), V.end());

    if(V[N-1] - V[0] == 0){
        cout << "-1" << endl;
        return 0;
    }

    //最大値と最小値を合わせる
    double P = B / (V[N-1] - V[0]);

    //現在の平均値
    double ave = sum / N * P;

    //平均を揃える
    double Q = A - ave;

    cout << fixed << setprecision(7) << P << " " << Q << endl; 

}