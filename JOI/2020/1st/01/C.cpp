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

    ll N, M;
    cin >> N >> M;

    queue<ll > A;
    queue<ll > B;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        A.push(t);
    } 

    for(ll i = 0; i < M; i++){
        ll t; cin >> t;
        B.push(t);
    } 

    while(!(A.empty()) || !(B.empty())){
        if(A.empty() && !(B.empty())){
            cout << B.front() << endl;
            B.pop();
        }else if(!(A.empty()) && B.empty()){
            cout << A.front() << endl;
            A.pop();           
        }else{
            if(A.front() > B.front()){
                cout << B.front() << endl;
                B.pop();
            }else{
                cout << A.front() << endl;
                A.pop();
            }
        }
    }

}