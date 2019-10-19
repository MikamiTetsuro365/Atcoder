#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N; string S;
    cin >> N >> S;

    for(ll i = 0; i < S.size();){
        ll j = i;
        //一緒の間ループを回し続けて，切れ目を探す
        while(j < S.size() && S[j] == S[i]){
            ++j;
        }
        vec.push_back(j - i);
        //次の始点へすっ飛ばす
        i = j;
    }

    cout << vec.size() << endl;

}