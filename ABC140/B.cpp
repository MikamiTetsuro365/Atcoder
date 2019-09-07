#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <map>

using namespace std;
typedef long long int ll;

int main(){

    ll N = 0;
    cin >> N;
    vector<ll > A(N);
    vector<ll > B(N);
    vector<ll > C(N - 1);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    for(ll i = 0; i < N; i++){
        cin >> B[i];
    }
    for(ll i = 0; i < N-1; i++){
        cin >> C[i];
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ans += B[A[i]-1];
        if(A[i] == A[i+1] - 1){
            ans += C[A[i] - 1];
        }
    }

    cout << ans << endl;


} 