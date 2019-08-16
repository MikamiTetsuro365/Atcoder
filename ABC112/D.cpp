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
typedef long long ll;
ll N;

ll GCD(ll a, ll b){
    return b ? GCD(b, a % b) : a;
}

//約数を求める
vector<ll > divisor(ll n){
    vector<ll > ans;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            ans.push_back(i);
            //重複を防ぐ
            if(i * i != n){
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){

    ll N, M;
    cin >> N >> M;

    //ll ans = GCD(M / N, M / N + M % N);
    ll ans = 0;
    vector<ll > ret = divisor(M);

    for(ll i = 0; i < ret.size(); i++){
        if(M - N * ret[i] >= 0){
            ans = max(ans, ret[i]);
        }
    }

    cout << ans << endl; 

} 