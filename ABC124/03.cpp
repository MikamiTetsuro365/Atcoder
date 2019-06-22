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
    string s;
    cin >> s;
    int N = s.length();

    vector<int > t_s(N, 0);
    vector<int > p1(N, 0);
    vector<int > p2(N, 0);

    for(int i = 1; i <= N; i++){
        if(s.substr(i-1,1) == "0"){
            t_s[i-1] = 0;
        }else{
            t_s[i-1] = 1;
        }  

        if(i % 2 == 0){
            p1[i-1] = 1;
            p2[i-1] = 0;
        }else{
            p1[i-1] = 0;
            p2[i-1] = 1;            
        }  
    }

    int ans1 = 0;
    int ans2 = 0;
    for(int i = 0; i < N; i++){
        if(t_s[i] == 0 && p1[i] == 1){
            ans1++;
        }
        if(t_s[i] == 1 && p1[i] == 0){
            ans1++;
        }
        if(t_s[i] == 0 && p2[i] == 1){
            ans2++;
        }
                if(t_s[i] == 0 && p2[i] == 1){
            ans2++;
        }
    }
    
    if(ans1 > ans2){
        cout << ans2 << endl;
    }else{
        cout << ans1 << endl;
    }

} 