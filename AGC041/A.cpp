#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N, A, B;
    cin >> N >> A >> B;

    if(B - A == 1){
        //cout << "a" << endl;
        cout << min(B - 1, N - A) << endl;
    }else{
        if((B - A - 1) % 2 == 1){
            //cout << "a" << endl;
            cout << (B - A - 1) / 2 + 1 << endl;
        }else{
            //cout << "a" << endl;
            cout << min(B - 1, N - A) << endl;
        }
    }

}