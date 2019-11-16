#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    ll N; cin >> N;
    double ans = 0;
    vector<ll > A(N, 0);
    vector<ll > X(N, 0);
    vector<ll > Y(N, 0);

    ll mod = 1;
    for(ll i = N; i > 0; i--){
        mod *= i;
    }

    for(ll i = 0; i < N; i++){
        A[i] = i;  
    }

    for(ll i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }

    do{
        double average = 0;
        
        for(ll i = 1; i < A.size(); i++){
            average += sqrt(pow(X[A[i-1]]-X[A[i]],2)+pow(Y[A[i-1]]-Y[A[i]],2));
        }

        ans += average;
  
    }while(next_permutation(A.begin(), A.end()));

    cout << fixed << setprecision(10) << ans / mod << endl;

}