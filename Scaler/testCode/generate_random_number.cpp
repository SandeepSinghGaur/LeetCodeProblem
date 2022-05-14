#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(0);
    for(int i=0;i<5;i++){
        long long random_num = (rand() * rand()) % 1000000000;
        cout<<random_num<<" ";
    }
}