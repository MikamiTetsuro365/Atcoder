#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

int main(){

    ll A, B, K;
    cin >> A >> B >> K;
    
    if(A - K < 0){
        B = max(0LL, B - abs(A - K) );
    }

    A = max(0LL, A - K);

    cout << A << " " << B << endl;
    

} 