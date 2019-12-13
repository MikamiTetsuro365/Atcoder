#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
ll N;
//これだと処理を進めていく上である区間全てに対して交換回数の変更を加えることができない！
int main() {    
    cin >> N;
    ll a = 0;
    ll b = 0;
    vector<ll > A(N, 0);
    vector<ll > index(N, 0);
    vector<vector<ll > > vec(N, vector<ll >(2, 0));
    ll ans = 0;

    for(ll i = 0; i < N; i++){
        cin >> index[i];
        index[i]--;
        A[index[i]] = i;
        //cout << index[i] << " " << A[index[i]] << endl;
    }
    //sort(A.begin(), A.end());

    for(ll i = 0; i < N; i++){
        cout << A[i] << " " << N - A[i] - 1 <<  endl;
        vec[i][0] = A[i];
        vec[i][1] = N - A[i] - 1; 
    }
    
    for(ll i = 0; i < N; i++){
        cout << vec[i][0]-a << " " <<vec[i][1]-b <<  endl;
        if(vec[i][0] == 0 && vec[i][1] == 0) continue;
        if(vec[i][0] >= vec[i][1]){
            //if(vec[i][1] == 0) continue;
            ans += vec[i][1] - b;
            b++;
        }else{
            //if(vec[i][0] == 0) continue;
            ans += vec[i][0] - a;
            a++;            
        }
    }

    cout << ans << endl;

}