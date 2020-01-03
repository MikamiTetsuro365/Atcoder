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

    ll A, B, X;
    cin >> A >> B >> X;
    /*
    if(A > X){
        cout << "NO" << endl;
    }else if(A == X){
        cout << "YES" << endl;
    }else{
        if(B >= X - A){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    */

   if(X >= A && A + B >= X){
       cout << "YES" << endl; 
   }else{
       cout << "NO" << endl;
   }

}