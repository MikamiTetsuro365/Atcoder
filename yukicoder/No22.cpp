#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;


int main() {

    ll N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    stack<ll > st;

    for(ll i = 0; i < N; i++){
        if(S[i] == '(') st.push(i+1);
        else{
            if(i+1 == K){
                cout << st.top() << endl;
                return 0;
            }
            if(st.top() == K){
                cout << i+1 << endl;
                return 0;
            }
            st.pop();
        }
    }

}