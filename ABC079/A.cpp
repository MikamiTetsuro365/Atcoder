#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

void Yes(bool Yes){cout << (Yes ? "Yes" : "No") << endl;};
void YES(bool YES){cout << (YES ? "YES" : "NO") << endl;};

int main(){

    string N; cin >> N;

    if(N[0]==N[1] && N[1] == N[2]){
        cout << "Yes" << endl;
    }else if(N[1]==N[2] && N[2] == N[3]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}