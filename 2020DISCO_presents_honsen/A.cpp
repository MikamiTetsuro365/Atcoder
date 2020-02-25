#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//Nimを思い出そう
int main() {

    ll N;
    cin >> N;

    ll ans = 0;
    ll sum = 0;
    
    for(ll i = 0; i < N; i++){
        ll A; cin >> A;
        //素因数の数を数える
        ll cnt = 0;
        ll j = 2;
        while(A >= j * j){
            if(A % j == 0){
                cnt++;
                A /= j;
            }else{
                j++;
            }
        }
        //1は素因数分解できない
        if(A != 1){
            cnt++;
        }
        ans ^= cnt;
    }

    if(ans > 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}