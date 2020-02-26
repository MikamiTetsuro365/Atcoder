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

    ll N;
    cin >> N;

    pair<ll, ll> p;
    p.first = -1;
    p.second = -1;
    for(ll i = 1; i <= N; i++){
        ll j = i;
        ll cn = 0;
        while(true){
            if(j % 2 == 0){
                j /= 2;
                cn++;
            }else{
                break;
            }
        }
        if(p.first < cn){
            p.first = cn;
            p.second = i;
        }
    }

    cout << p.second << endl;

}