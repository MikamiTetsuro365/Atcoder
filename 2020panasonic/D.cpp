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

    if(N == 1){
        cout << "a" << endl;
        return 0;
    }

    map<ll, string > mp;
    for(ll i = 0; i < (1<<N); i++){
        //ビットの位置を数える
        for(ll j = 0; j < N; j++){
            //右シフトして最下位で立っているかどうか判定
            string s = "";
            mp[i] = s;
        }
    }

    
}
