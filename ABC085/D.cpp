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

    ll N, H;
    cin >> N >> H;
    vector<ll > A;
    vector<ll > B;

    for(ll i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        //cout << B[i] << endl;
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    ll ans = 0;
    for(ll i = 0; i < B.size(); i++){
        //HPを削りきったら終わり
        if(H <= 0) break;
        //投げるより切り続けるほうがよい攻撃力のある刀があれば終わり
        if(B[i] < A[0]) break;
        H -= B[i];
        ans++;
    }
    //切り続ける
    if(H > 0){
        ans += ceil((double)H / A[0]);
    }

    cout << ans << endl;

    


} 