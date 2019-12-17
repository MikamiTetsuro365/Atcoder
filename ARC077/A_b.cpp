#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//デキューを使うと両端に追加していける
int main() {

    ll N; cin >> N;
    
    deque<ll > deq;

    for(ll i = 0; i < N; i++){
        ll n; cin >> n;
        if(i % 2 == 0){
            if(N % 2 == 0) deq.push_back(n);
            else deq.push_front(n);
        }else{
            if(N % 2 == 0) deq.push_front(n);
            else deq.push_back(n);
            
        }
    }

    for_each(deq.begin(), deq.end(), [](int x) {
        cout << x << " ";
    });

}