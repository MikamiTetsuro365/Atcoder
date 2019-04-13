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

    int A, B;
    cin >> A >> B;

    int ans = 0;
    if(A > B){
        ans += A;
        A--;
        if(A > B){
            ans+= A;
        }else{
            ans+= B;
        }
    }else{

           ans += B;
           B--;
        if(A < B){
            ans+= B;
        }else{
            ans+= A;
        }     
    }

    cout << ans << endl;



} 