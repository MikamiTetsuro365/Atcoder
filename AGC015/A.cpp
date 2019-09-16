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
#include <queue>
#include <functional> 

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

int main(){
    //制約に注意 
    //AとBを必ず１つ使うこと
    ll N, A, B;
    cin >> N >> A >> B;

    if(A > B){
        cout << "0" << endl;
        return 0;
    }else if(N == 1 && B - A >= 1){
        cout << "0" << endl;
        return 0;     
    }

    cout << (N - 2) * (B - A) + 1 << endl;



} 