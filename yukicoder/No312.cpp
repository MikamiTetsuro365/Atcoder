#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

vector<ll > divisor(ll n){
    vector<ll > div;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            div.push_back(i);
            if(i * i != n) div.push_back(n / i);
        }
    }
    sort(div.begin(), div.end());
    return div;
}

int main() {

    ll N;
    cin >> N;

    vector<ll > div = divisor(N);

    ll idx = 0;
    while(true){
        if(div[idx] != 1 && div[idx] != 2){
            cout << div[idx] << endl;
            return 0;
        }
        idx++;
    }

}