#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;
typedef pair<ll, pair<ll, ll > > iip;
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
//差を考える
int main() {

    //fstream in("input.txt");
    //cin.rdbuf(in.rdbuf());

    ll N; cin >> N;
    vector<iip> A;

    for(ll i = 0; i < N; i++){
        ll a; cin >> a;
        A.push_back(make_pair(0, make_pair(a, 0)));
    }

    for(ll i = 0; i < N; i++){
        ll b; cin >> b;
        A[i].first = b - A[i].second.first;
        A[i].second.second = b;
    }

    sort(A.rbegin(), A.rend());

    ll stock = 0;

    for(ll i = 0; i < N; i++){
        //cout << i << " " << stock << " " << A[i].first << endl;
        if(A[i].first >= 0){
            stock += A[i].first / 2;
            /*
            if(A[i].first % 2 == 1){
                stock--;
            }
            */
        }else{
            stock -= abs(A[i].first);
        }
    }

    if(stock < 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    
 
}