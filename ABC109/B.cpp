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

    ll N;
    cin >> N;

    map<string, ll> mp;

    string ans = "Yes";
    char back;
    for(ll i = 0; i < N; i++){
        string s;
        cin >> s;
        if(mp[s] == 0){
            mp[s]++;
            if(i != 0 && s[0] != back){
                ans = "No";
            }else{
                back = s[s.size()-1];
            }
        }else{
                ans = "No";
        }

    }

    cout << ans << endl;
    return 0;

}