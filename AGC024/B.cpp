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

    ll N;
    cin >> N;

    set<ll > st;
    st.insert(-INF);
    
    for(ll i = 0; i < N; i++){
        ll A; cin >> A;
        auto it = st.lower_bound(A);
        it--;
        if(*it != -INF){
            if(*it + 1 == A){
                st.erase(it);
            }
        }
        st.insert(A);
    }

    //set列挙 一番連続しているところを探す
    ll tmp = 0;
    ll mx = -1;
    for (auto itr = st.begin(); itr != st.end(); itr++) {
        if(*itr != -INF){
            mx = max(mx, *itr-tmp);
            tmp = *itr;
        }
    }

    cout << N - mx << endl;

}