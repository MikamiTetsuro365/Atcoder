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

int main(){

    ll A;
    string S;
    string T;
    cin >> S >> T;

    ll ans = 0;
    if(S[0] == T[0]){
        ans++;
    }
    if(S[1] == T[1]){
        ans++;
    }
    if(S[2] == T[2]){
        ans++;
    }


    cout << ans << endl;
    

}