#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;
    vector<ll > X(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> X[i];
    }

    ll M;
    cin >> M;
    for(ll i = 0; i < M; i++){
        ll in;
        cin >> in;
        //cout << X[in - 1] << " " << X[in] << endl;
        if(X[in - 1] + 1 != X[in] && X[in - 1] != 2019 ){
            //cout << "a" << endl;
            X[in - 1]++;
        }
    } 

    for(ll i = 0; i < N; i++){
        cout << X[i] << endl;
    } 

}