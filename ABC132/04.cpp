#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>

using namespace std;
typedef long long int ll;

void comb(vector<vector <ll > > &v){
    for(ll i = 0; i < v.size(); i++){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for(ll k = 1; k < v.size(); k++){
        for(ll j = 1; j < k; j++){
            v[k][j] = v[k-1][j-1] + v[k-1][j];
        }        
    }
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<vector<ll > > v(N+1,vector<ll >(N+1,0));
    ll waru = 1000000007;

    comb(v);
    
    for(ll i = 1; i <= K; i++){
        ll ans = v[N-K-1][i] * v[K-1][i-1] % waru;
        cout << ans << endl;
    }

} 