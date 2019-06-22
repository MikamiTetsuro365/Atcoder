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
ll M;
string s;
vector<ll > input1;  
vector<vector <ll > > input2;
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
int main(){
    
    //cin >> N;
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll LCM = lcm(C, D);
    //cout << LCM << endl;

    ll ansA = B / C - A / C;
    if(A % C == 0){
        ansA += 1;
    }

    //cout << ansA << endl;

    ll ansB = B / D - A / D;
    if(A % D == 0){
        ansB += 1;
    }

    ll anslcm = B / LCM - A / LCM;
    if(A % LCM == 0){
        anslcm += 1;
    }
    //cout << anslcm << endl;
    ll ryouhou = ansA + ansB - anslcm;

    ll ans = (B - A + 1) - ryouhou;

    cout << ans << endl;
} 