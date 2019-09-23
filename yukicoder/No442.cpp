#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

int main(){
    
    ll A, B;
    cin >> A >> B;
    if(A < B){
        swap(A, B);
    }
    ll G = gcd(A, B);
    ll ans = G * gcd(A / G + B / G, G);

    cout << ans << endl;

} 