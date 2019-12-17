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

    ll N; cin >> N;

    stack<ll > F; 
    queue<ll > F2;  
    queue<ll > B; 
    stack<ll > B2;

    bool f = true;
    //ll n; cin >> n; B.push(n);
    for(ll i = 0; i < N; i++){
        ll n; cin >> n;
        if(f == true){
            B.push(n);
            B2.push(n);
            f = false;
        }else{
            F.push(n);
            F2.push(n);
            f = true;
        }
    }

    if(N % 2 == 0){
        while(!F.empty()){
            cout << F.top() << " ";
            F.pop();
        }
        while(!B.empty()){
            cout << B.front() << " ";
            B.pop();
        } 
    }else{
        while(!B2.empty()){
            cout << B2.top() << " ";
            B2.pop();
        }
        while(!F2.empty()){
            cout << F2.front() << " ";
            F2.pop();
        }         
    }
   

}