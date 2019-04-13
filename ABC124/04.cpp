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
    //int N, K;
    //cin >> N >> K;
    string s;
    cin >> s;

    bool swi;
    if(s.substr(0, 1) == "0"){
        swi = 0;
    }else{
        swi = 1;
    }

    vector<int > ans;

    if(swi == 0){
        ans.push_back(0);
    }

    int f = 0;
    int cont = 1;
    for(int i = 0; i < s.length()-1; i++){
        if(swi == 0){
            if(s.substr(i, 1) == "0" && s.substr(i+1, 1) == "1"){
                ans.push_back(cont);
                swi = 1;
                cont = 1;
            }else{
                cont++;
            }
        }else{
            if(s.substr(i, 1) == "1" && s.substr(i+1, 1) == "0"){
                ans.push_back(cont);
                swi = 0;
                cont = 1;
            }else{
                cont++;
            }
        }

    }
    ans.push_back(cont);
    //数合わせ
    if(ans.size() % 2 != 0){
        ans.push_back(0);
    }

    int ff = 0;
    for(int i = 0; i < 1; i++){
        if(ff == 0){
            vector<int > temp;
            for(int j = 0; j < ans.size(); j += 2){
                cout << ans[j] + ans[j+1] + ans[j+2] << endl;
                temp.push_back(ans[j] + ans[j+1] + ans[j+2]);
            }
            for(int j = 0; j < temp.size(); j++){
                cout << temp[j] << endl;
            }
        } 
    }
    for(int i = 0; i < ans.size(); i++){

        
    }


} 