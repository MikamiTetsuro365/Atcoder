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
 
ll N = 0;
ll M = 0;
ll x = 0;
ll y = 0;

const int MAX = 510000;
const int MOD = 1000000007;

/* 
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
*/


bool areAnagram(string str1, string str2) 
{ 
    // Get lengths of both strings 
    int n1 = str1.length(); 
    int n2 = str2.length(); 
  
    // If length of both strings is not same, then they 
    // cannot be anagram 
    if (n1 != n2) 
        return false; 
  
    // Sort both the strings 
    sort(str1.begin(), str1.end()); 
    sort(str2.begin(), str2.end()); 
  
    // Compare sorted strings 
    for (int i = 0; i < n1; i++) 
        if (str1[i] != str2[i]) 
            return false; 
  
    return true; 
} 
 
int main(){
    //初期化
    //COMinit();

    //入力
    cin >> N;
    //初期化


    vector<string > s(N);

    for(ll i = 0; i < N; i++){
        string S;
        cin >> S;
        sort(S.begin(), S.end()); 
        s[i] = S;
    }
    sort(s.begin(), s.end()); 

    //カウント用
    map<string, ll> count;
    //答えを格納する
    ll ans = 0;
    for(ll i = 0; i < N ; i++){

        if(count[s[i]] >= 1){
            ans += count[s[i]];
        }

        count[s[i]]++;

    }

    cout << ans << endl; 
    
}