#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;

using namespace std;

int main(){

    string A;
    cin >> A;
    ll B;
    cin >> B;
    //cout << A[3] << endl;
    if(A.length() >= B){
        cout << A[B-1] << endl;
    }else{
        if(B % A.length() == 0){
            cout << A[A.length()-1] << endl;
        }else{
            cout << A[B % A.length() - 1] << endl;
        }
    }

}