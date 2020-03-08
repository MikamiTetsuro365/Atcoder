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

    double A, B;
    cin >> A >> B;

    if(floor(A / 0.08 * 0.1) != B && floor(B / 0.1 * 0.08) != A){
        cout << "-1" << endl;
    }else{
        double idx = 1;
        while(true){
            if(floor(idx * 0.08) == A && floor(idx * 0.1) == B){
                cout << idx << endl;
                return 0;
            }
            idx++;
        }
    }
}