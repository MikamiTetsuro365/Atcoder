#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi; 
typedef pair<pair<ll ,ll >,ll > pii; 

int main(){

    ll N;
    cin >> N;

    ll t_N = N;
    ll sum = 0;

    while(t_N > 0){
        sum += t_N % 10;
        t_N = t_N / 10;
    }

    if(N % sum == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}