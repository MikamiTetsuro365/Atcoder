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
    int N, L;
    cin >> N >> L;
    //vector<int>ans(N, 0);
    vector< pair<ll, ll > > ans2(N);
    //int ans = 0;
    //pair<ll, ll> ans;
    for(int i = 0; i < N; i++){
        int temp = 0;
        int temp2 = 0;
        for(int j = 0; j < N; j++){
            if(j == i){
                temp += L + j+1 - 1;
                continue;
            }
            temp  += L + j+1 - 1;
            temp2 += L + j+1 - 1;
        }
        //cout << temp << endl;
        ans2[i] = make_pair(abs(temp - temp2), temp2);
        //ans[i] = temp - temp2;
    }

    sort(ans2.begin(), ans2.end());

    

    cout << ans2[0].second << endl;

} 