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

    string S;
    cin >> S;

    bool k = true;
     bool g = true;
    for(ll i = 1; i <= S.length(); i++){
        if(i % 2 == 0){
            if(S[i-1] == 'R'){
                g = false;
            }
        }else{
            if(S[i-1] == 'L'){
                k = false;
            }        
        }
    }

    if(k == true && g == true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    


} 