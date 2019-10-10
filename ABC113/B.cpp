#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<double, double > pi; 
typedef pair<pair<ll ,ll >,ll > pii; 

int main(){
    
    ll N, T ,A;
    cin >> N >> T >> A;

    priority_queue<pi, vector<pi>, greater<pi > > ans;
    
    for(ll i = 0; i < N; i++){
        double H; cin >> H;
        ans.push(make_pair(abs((double)A - (T - H * 0.006)), i + 1));
    }

    cout << ans.top().second << endl;


}