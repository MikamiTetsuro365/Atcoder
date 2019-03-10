#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;

int H, W = 0;
//５がアレば変換できるなければ無理
//ラベリング→領域ごとの最大の変換回数の合計＋１
int main(){

    cin >> H >> W;

    /*
    int fiveF = 0;
    int six_sevenF = 0;
    int eightF = 0;
    int nineF = 0;
    int t = 0;
    for(int i = 0; i < H * W; i++){
        cin >> t;
        if(t == 5){
            fiveF  = 1;
        }else if(t == 6 || t == 7){
            six_sevenF = 1;
        }else if(t == 8){
            eightF = 2;
        }else if(t == 9){
            nineF = 3;
        }
    }

    int maxNum = max(six_sevenF,max(eightF, nineF));

    if(fiveF == 0){
        cout << "No" << endl;
    }else{
        cout << "Yes " << maxNum + 1 << endl;
    }
    */

}