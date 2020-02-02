#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//もっと簡単に考えろ
int main() {

    ll l1, l2, l3;
    cin >> l1 >> l2 >> l3;

    if((l2 == l3) &&(l1 < l2 || l1 > l2 )){
        cout << l1 << endl;
    }else if(l1 == l2 && (l2 < l3 || l2 > l3)){
        cout << l3 << endl;
    }else if(l1 == l3 && (l1 < l2 || l1 > l2)){
        cout << l2 << endl;
    }else{
        cout << l1 << endl;
    }

}