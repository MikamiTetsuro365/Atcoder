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
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;
typedef long long int ll;
//考察が詰めきれず難しかった.
//クソコードにより添字地獄が発生して無限バグらせ死亡
int main(){

    ll N;
    cin >> N;
    //数列入力
    vector<ll > A(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> A[i];  
    }

    do{
        for(ll i = 0; i < A.size(); i++){
            cout << A[i];
        }
        cout << endl;
    }while(next_permutation(A.begin(), A.end()));

} 