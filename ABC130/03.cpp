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
//四角形の中点に座標がしていされていれば分け方はいっぱいある
//それ以外はNG
//基本的に座標が指定されても面積は二分割できる
int main(){
    
    //cin >> N;
    double W, H, x , y;
    cin >> W >> H >> x >> y;

    cout << fixed << setprecision(9)  << W * H / 2.0;

    if(W / 2 == x && H / 2 == y){
        cout << " 1"  << endl;
    }else{
        cout << " 0"  << endl;
    }

} 