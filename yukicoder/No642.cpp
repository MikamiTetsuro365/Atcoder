#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;


int main(){
    //条件を逆に読み替えた
    //Nが１になるまで +1 するか 2で割る
    ll N;
    cin >> N;
    ll ans = 0;
    while(N > 1){
        if(N % 2 == 1){
            N++;
            
        }else{
            N /= 2;
        }

        ans++;
    }
    cout << ans << endl;
} 