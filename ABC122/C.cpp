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
    int N , Q;
    cin >> N >> Q;
    string b;
    cin >> b;
    vector<string > ss;
    vector<int > l;
    vector<int > r;

    int L, R;
    for(int i = 0; i < Q;i++){
        cin >> L >> R;
        l.push_back(L);
        r.push_back(R);
    }

/*
    for(int i = 0; i < Q;i++){
        string sss;
        sss = b.substr(l[i]-1, r[i]-l[i]+1);
        ss.push_back(sss);  
        //cout << sss << endl;
    }
*/

    vector<int > dp(11451419, 0);
    dp[0] = 0;
    for(int j = 0; j < b.length() - 1;j++){  
        string h = b.substr(j,2);
        if(h == "AC") {
            dp[j + 1] += dp[j] + 1;
        }else{
            dp[j + 1] = dp[j];
        } 
        //cout << dp[j] << " ";
    } 
    //cout << endl;

    
    int f = 0;
    for(int i = 0; i < Q;i++){
        int ans = 0;
        ans = dp[r[i]-1] - dp[l[i]-1];
        //cout << r[i]-1 << " " << l[i]-1 << endl;
        //cout << dp[r[i]-1]  << " " << dp[l[i]-1] << endl;
        //for(int j = l[i] - 1; j < r[i] - 1; j++){
            //cout << b.substr(l[i] - 1 , )
            //ans += dp[j] - ;
        //}

        cout << ans << endl;
    }

} 