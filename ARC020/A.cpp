#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll A, B;
    cin >> A >> B;

    ll a = 0;
    ll b = 0;

    if(A > 0){
        a = A;
    }else{
        a = 0 - A;
    }

    if(B > 0){
        b = B;
    }else{
        b = 0 - B;
    }

    if(a > b){
        cout << "Bug" << endl;
    }else if(a < b){
        cout << "Ant" << endl;
    }else{
        cout << "Draw" << endl;
    }

}