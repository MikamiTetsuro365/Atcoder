#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;


int main(){

    string wa;
    cin >> wa;
    int i = 0;
    /*
    for(i = 0; i < wa.length() - 1; i++ ){

        if(flag == 1){
            flag = 0;
            i = 0;
        }

        if(wa.substr(i,2) == "WA"){
            wa.replace(i,2,"AC");
            flag = 1;
            i = 0;
        }
    }
    */
    int start = 0;
    int w_num = 0;
    //交換flag
    int flag = 0;
    //交換終了flag 
    int f_flag = 0;
    for(i = 0; i < wa.length(); i++ ){

        //交換します
        if(flag == 1){
            wa.replace(start,1,"A");
            for(int j = 1; j <= w_num; j++){
                wa.replace(start + j, 1, "C");
            }

            flag = 0;
            f_flag = 0;
            w_num = 0;
            start = 0;
        }

        if(wa.substr(i,1) == "W"){
            //はじめまして
            w_num++;
           
            if(f_flag == 0){
                f_flag = 1;     
                start = i;
            }

            if(wa.substr(i + 1, 1) == "A"){
                //次交換します
                flag = 1;
            }else if(wa.substr(i + 1, 1) == "W"){
                //次はまだ様子見です
                flag = 0;
            }else{
                //見なかったことにします
                f_flag = 0;
                w_num = 0;
                start = 0;
            }
        }

    }

    cout << wa << endl;
}