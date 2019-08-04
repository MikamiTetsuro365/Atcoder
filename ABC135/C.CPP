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

//０以上N以下の整数で、ある条件を満たすものの個数を求めよ

int main(){

    ll N = 0;
    cin >> N;

    vector<ll > A(N+1);
    for(ll i = 0; i < N + 1; i++){
        cin >> A[i];
    }

    vector<ll > B(N);
    for(ll i = 0; i < N; i++){
        cin >> B[i];
    }

    //反転
    //reverse(A.begin(), A.end());
    //reverse(B.begin(), B.end());

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        if(A[i] >= B[i]){
            ans += B[i];
        }else{
            ans += A[i];
            B[i] -= A[i];

            if(A[i + 1] >= B[i]){
                ans += B[i]; 
                A[i + 1] -= B[i];              
            }else{
                ans += A[i + 1]; 
                A[i + 1] = 0;     
            }
            
        }
    }

    cout << ans << endl;
} 