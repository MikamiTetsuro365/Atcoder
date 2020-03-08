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

    string S;
    cin >> S;

    ll Q;
    cin >> Q;

    ll rev = 0;
    deque<char > deq;
    for(ll i = 0; i < S.length(); i++){
        //push_frontは反転しちゃう＞＜
        deq.push_back(S[i]);
    }

    for(ll i = 0; i < Q; i++){
        ll t; cin >> t;
        if(t == 1){
            rev++;
        }else{
            ll f; cin >> f;
            char c; cin >> c;
            if(rev % 2 == 0){
                if(f == 1) deq.push_front(c);
                if(f == 2) deq.push_back(c);
            }else{
                if(f == 1) deq.push_back(c);
                if(f == 2) deq.push_front(c);                
            }
        }
    }

    while(!deq.empty()){
        if(rev % 2 == 0){
            cout << (char)(deq.front());
            deq.pop_front();
        }else{
            cout << (char)(deq.back());
            deq.pop_back();
        }
    }
    cout << endl;
    

}