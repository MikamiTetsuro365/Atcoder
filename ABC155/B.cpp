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

    ll N;
    cin >> N;

    ll cn = 0;
    ll cn2 = 0;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
        if(t % 2 == 0 ){
            cn2++;
            if(t % 3 == 0 || t % 5 == 0){
                cn++;
                //cout << "APPROVED" << endl;
            }else{
                //cout << "DENIED" << endl;
            }
        }else{
            //cout << "DENIED" << endl;
        }
    }

    if(cn == cn2){
        cout << "APPROVED" << endl;
    }else{
        cout << "DENIED" << endl;
    }

}

