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
typedef long long ll;
ll N;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

int main(){

    ll A, B;
    cin >> A >> B;

    if(A * B % 2 == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}