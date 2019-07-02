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

    string s;
    cin >> s;
    
    for(ll i = 0; i < s.length(); i++){
        if(s[i] == s[i+1]){
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }

        if(i < s.length()-2 && s[i] == s[i+2]){
            cout << i + 1 << " " << i + 3 << endl;
            return 0;            
        }

    }

    cout << "-1 -1" << endl;

} 