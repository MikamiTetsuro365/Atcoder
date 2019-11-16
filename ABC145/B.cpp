#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    ll N; 
    string S;
    cin >> N >> S;

    vector<ll > A(N, 0);

    if(S.size() % 2 != 0){
        cout << "No" << endl;
        return 0;
    }

    if(S.substr(0, S.size()/2) == S.substr(S.size()/2, S.size()/2)){
        cout << "Yes" << endl;
        return 0;
    }else{
        cout << "No" << endl;
    }


}