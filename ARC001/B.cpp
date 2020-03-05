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
    A += 19;
    B += 19;
    vector<ll > O(4545, INF);
    O[A] = 0;

    for(ll i = A; i <= B; i++){
        O[i+1]  = min(O[i+1], O[i]+1);
        O[i+5]  = min(O[i+5], O[i]+1);
        O[i+10] = min(O[i+10], O[i]+1);
    }

    for(ll i = A; i <= B+10; i++){
        cout << O[i] << " ";
    }
    cout << endl;
    
    cout << O[B] << endl;

    for(ll i = B+10; i >= B; i--){
        O[i-1]  = min(O[i-1], O[i]+1);
        O[i-5]  = min(O[i-5], O[i]+1);
        O[i-10] = min(O[i-10], O[i]+1);
    }

    for(ll i = A; i <= B+10; i++){
        cout << O[i] << " ";
    }
    cout << endl;

    cout << O[B] << endl;

}