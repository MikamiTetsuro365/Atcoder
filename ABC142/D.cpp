#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

vector<bool > prime;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

map<ll, ll> primeFactor(ll num){

    //素因数と指数部の並び
    map<ll, ll > PF;

    ll i = 2;

    while(num >= i * i){
        if(num % i == 0){
            PF[i]++;
            num /= i;
        }else{
            i++;
        }
    }
    //1は素因数分解できない
    if(num != 1){
        PF[num]++;
    }
    
    return PF;
}



int main(){

    ll A, B;
    cin >> A >> B;

    if(A < B){
        swap(A, B);
    }

    ll GCD = gcd(A, B);

    map<ll, ll> PF = primeFactor(GCD);

    ll ans = 0;

    auto begin = PF.begin(), end = PF.end();
    for (auto iter = begin; iter != end; iter++) {
        ans++;
    }

    ans++;

    cout << ans << endl;
    


}