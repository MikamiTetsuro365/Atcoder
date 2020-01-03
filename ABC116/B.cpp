#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){
    ll s; cin >> s;
    vector<ll > vec;
    vec.push_back(s);
    ll cn = 1;
    while(true){
        if(s % 2 == 0){
            vec.push_back(s/2);
        }else{
            vec.push_back(3 * s + 1);
        }
        s = vec[cn];
        for(ll i = 0; i < cn-1; i++){
            if(vec[i] == vec[cn]){
                cout << cn + 1 << endl;
                return 0;
            }
        }
        cn++;
    }
}