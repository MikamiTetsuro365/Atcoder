#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 9223372036854775807;

int main(){

    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll cn = 0;
    for(ll i = 0; i <= 3000; i++){
        for(ll j = 0; j <= 3000; j++){
            //マイナスだとそんな買い方存在しません
            if(N - R*i - G*j < 0) continue;
            if((N - R*i - G*j) % B == 0) cn++;
        }        
    }

    cout << cn << endl;

}
