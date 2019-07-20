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

    ll N;
    cin >> N ;
    vector<ll > A(N, 0);
    vector<ll > result(N,0);
    vector<ll > ans;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    for(ll i = N - 1; i >= 0 ; i--){
        vector<ll > rat = divisor(i + 1);
        //cout << result[i] << ":" << A[i] << endl;
        if((result[i] + 1 ) % 2 == A[i] ){
            for(ll j = 0; j < rat.size(); j++){
                result[rat[j] - 1] ++;
                //cout << rat[j] << ":" << result[rat[j] - 1] << endl;
            }
            ans.push_back(i + 1);
            //cout << i + 1 << endl;
        }else{
            ans.push_back(-1);
        }
    }

    reverse(ans.begin(), ans.end());

    ll cn = 0;
    vector<ll > true_ans;
    for(ll i = 0; i < ans.size(); i++){
        if(ans[i] != -1){
            cn++;
            true_ans.push_back(ans[i]);
        }
    }

    if(cn != 0){
        cout << cn << endl;
        for(ll i = 0; i < true_ans.size() - 1 ; i++){
            cout << true_ans[i] << " ";
        }
        cout << true_ans[true_ans.size() - 1] << endl;
    }else{
        cout << "0" << endl;

    }


    
}