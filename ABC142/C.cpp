#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;

    vector<pair<ll, ll > > A;

    for(ll i = 0; i < N; i++){
        ll in; cin >> in;
        A.push_back(make_pair(in, i + 1));
    }

    sort(A.begin(), A.end());


    for(ll i = 0; i < N - 1; i++){
        cout << A[i].second << " ";
    }  
    cout << A[N - 1].second << endl;

}