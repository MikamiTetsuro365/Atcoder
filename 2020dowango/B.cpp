#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<double > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;



int main() {

    double N; cin >> N;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    //確率
    //1/(N-1) 1/(N-2) 1/(N-3)
    vector<double > P(N + 1919, 0);

    //累積ワ
    vector<double > R(N, 0);
    for(ll i = 0; i < N - 1; i++){
        if(i == 0) R[i + 1] = vec[i+1] - vec[i];
        else R[i + 1] = vec[i+1] - vec[i] + R[i];
        //cout << R[i + 1] << " " ;
    }
    //cout << endl;
    
    //最も左の座標は1から
    for(ll i = 0; i < N; i++){
        ll cn = 2;
        for(ll j = i + 2; j < N; j++){
            P[cn] += R[j] - R[i];
            //cout << R[j] << " " << R[i] << endl;
            cn++;
        }
    }

    for(ll i = 0; i < N + 5; i++){
        cout << P[i] << " " ;
    }
    cout << endl;

    
    //累積和Rはidx = 1 が 1/(N-1)
    ll sum = 0;
    for(ll i = 1; i < N; i++){
        double tmp = 1 / (N-i) * (R[N-1-i] + P[i+1]);
        cout << tmp << endl;
        cout << R[i] << " " << P[i+1] << endl;
        sum += tmp;
    }

    cout << sum << endl;

    


}