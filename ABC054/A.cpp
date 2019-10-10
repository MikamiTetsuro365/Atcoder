#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  

int main(){

    ll A, B; cin >> A >> B;

    A -= 2;
    if(A < 0)A += 100;
    B -= 2;
    if(B < 0)B += 100;

    if(A == B){
        cout << "Draw" << endl;
        return 0;
    }
    
    if(A > B){
        cout << "Alice" << endl;
        return 0;
    }else{
        cout << "Bob" << endl;
        return 0;
    }

}