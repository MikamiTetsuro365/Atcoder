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

    string b;
    cin >> b;
    vector<string > ss;
    
    for(int i = 0; i < b.length();i++){
        string sss;
        for(int j = 0; j < b.length() - i;j++){      
            sss = b.substr(i,j + 1);
            //cout << sss << endl;   
            ss.push_back(sss); 
        }   
    }

    int ans = 0;
    int f = 0;
    for(int i = 0; i <ss.size();i++){
        for(int j = 0; j < ss[i].length();j++){  
            string h = ss[i].substr(j,1);    
            if(!( h == "A" ||  h == "C" ||  h == "G" ||  h == "T")){
                f = 1;
            }
        }   
        if(f != 1){
            int size = ss[i].length();
            ans = max(ans, size);
        }
        f = 0;
    }
    cout << ans << endl;
} 