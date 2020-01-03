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

    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;

    vector<ll > A(X,0);
    vector<ll > B(Y,0);
    vector<ll > C(Z,0);

    for(ll i = 0; i < X; i++){
        cin >> A[i];
    }

    for(ll i = 0; i < Y; i++){
        cin >> B[i];
    }

    for(ll i = 0; i < Z; i++){
        cin >> C[i];
    }

    sort(C.rbegin(), C.rend());

    vector<ll > AB;

    for(ll i = 0; i < X; i++){
        for(ll j = 0; j < Y; j++){
            AB.push_back(A[i]+B[j]);
           //cout << A[i]+B[j] << endl;
        }        
    }
    
    sort(AB.rbegin(), AB.rend());

    vector<ll > ans;

    ll cn = 0;
    for(ll i = 0; i < AB.size(); i++){
        for(ll j = 0; j < Z; j++){
            ans.push_back(AB[i] + C[j]);
            cn++;
            if(cn >= K * K){
                break;
            }
        }
        if(cn >= K * K){
            break;
        }
    }
    
    sort(ans.rbegin(), ans.rend());
    for(ll i = 0; i < K; i++){
        cout << ans[i] << endl;
    }

}