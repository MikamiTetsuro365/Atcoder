#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {  

    ll N; cin >> N;

    multiset<ll > st;
    st.insert(-INF);
 
    for(ll i = 0; i < N; i++){
        ll A; cin >> A;
        A *= -1;
        auto it = st.lower_bound(A);
        it--;
        if(*it != -INF) st.erase(it);
        st.insert(A);
        //cout << "size:" << st.size() << endl;
    }    

    cout << st.size()-1 << endl;

}