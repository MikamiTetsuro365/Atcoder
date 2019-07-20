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

using namespace std;
typedef long long ll;
ll N;

vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main(){
    //ll P , Q , R;
    //cin >> P >> Q  >> R;

    ll N;
    cin >> N ;
    vector<ll > A(N, 0);
    vector<ll > result(N,0);
    vector<ll > ans;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    for(ll i = 0; i < N ; i++){
        vector<ll > rat = divisor(i + 1);
        //ll cn = 0;
        for(ll j = 0; j < rat.size(); j++){
            result[rat[j] - 1] += A[i];
        }
    }

    for(ll i = 0; i < N; i++){
        if(result[i] % 2 == A[i]){
            if(result[i] == 0){
                ans.push_back(-1);
            }else{
                ans.push_back(i + 1); 
            }
            
        }
    }

    if(result.empty()){
        cout << -1 << endl;
        return 0;
    }

    vector<ll > true_ans; 
    ll cn = 0;

    for(ll i = 0; i < ans.size(); i++){
        if(ans[i] != -1){
            cn++;
            true_ans.push_back(ans[i]);
        }
    }   

    if(cn == 0){
        cout << 0 << endl;
    }else{
        cout << cn << endl;
        for(ll i = 0; i < true_ans.size() - 1; i++){
            cout << true_ans[i] << " ";
        }
        cout << true_ans[true_ans.size() - 1] << endl;
    }
    
}