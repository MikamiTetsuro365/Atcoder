#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int N, M;
vector<ll> A;
ll num[9] = {2,5,5,4,5,6,3,7,6};

int main(){
    cin >> N >> M;

    ll t = 0;
    for(ll i = 0; i < M; i++){
        cin >> t;
        A.push_back(t);
    }
    sort(A.rbegin(),A.rend());

    vector<ll > dp(N + 1, -1);
    dp[0] = 0;

    //最大桁数
    int flag = 0;
    for(ll i = 0; i < N; i++){
        if(dp[i] > -1){
            for(ll j = 0; j < A.size(); j++){
                if(i + num[A[j]-1] <= N && dp[i + num[A[j]-1]] < dp[i] + 1){
                    dp[i + num[A[j]-1]] = dp[i] + 1;    
                }
            }   
        }
    }
    ll mx = dp[dp.size() - 1];

    //たどる
    string ans;
    for(ll i = 1; i <= mx; i++){
        for(ll j = 0; j < A.size(); j++){
            if((dp[N - num[A[j]-1]]) == (mx - i) && N >= num[A[j]-1]){
                ans += to_string(A[j]);
                N = N - num[A[j]-1];
                break;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}