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

int main(){
    
    //cin >> N;
    string s;
    cin >> s;

   if(s[0] == s[1]){
       cout << "Bad" << endl;
       return 0;
   }else if(s[1] == s[2]){
        cout << "Bad" << endl;
        return 0;
   }else if(s[2] == s[3]){
    cout << "Bad" << endl;
    return 0;
   }

     cout << "Good" << endl;

} 