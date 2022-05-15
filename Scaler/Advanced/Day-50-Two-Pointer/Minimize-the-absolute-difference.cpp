/*
problem description

Given three sorted arrays A, B and C of not necessarily same sizes.
Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that 
a, b, c belongs arrays A, B, C respectively. i.e. minimize | max(a,b,c) - min(a,b,c) |.

Input
A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output
1
*/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int p1=0,p2=0,p3=0;
    int ans=INT_MAX;
    int n=A.size(),m=B.size(),k=C.size();
    while(p1<=n-1 && p2<=m-1 && p3<=k-1){
        int max_val=max({A[p1],B[p2],C[p3]});
        // cout<<"max-val"<<" "<<max_val<<endl;
        int min_val=min({A[p1],B[p2],C[p3]});
        // cout<<"min-val"<<" "<<min_val<<endl;
        ans=min(ans,abs(max_val-min_val));
        // cout<<"ans"<<" "<<ans<<endl;
        if(min_val==A[p1] && min_val==B[p2] && min_val==C[p3]){
               int minp=min({p1,p2,p3});
               if(minp==p1){
                   p1++;
               }else if(minp==p2){
                   p2++;
               }else{
                   p3++;
               }
        }else if(min_val==A[p1]){
             if(min_val!=B[p2] && min_val!=C[p3])
               p1++;
            if(min_val==B[p2]){
                if(p1<=p2){
                    p1++;
                }else{
                    p2++;
                }
            }
            if(min_val==C[p3]){
                if(p1<=p3){
                    p1++;
                }else{
                    p3++;
                }
            }
           
        }else if(min_val==B[p2] ){
            if(min_val!=C[p3])
             p2++;
            if(min_val==C[p3]){
                if(p2<=p3){
                    p2++;
                }else{
                    p3++;
                }
            }
        }else if(min_val==C[p3]){
            p3++;
           
        }
    }
    return ans;
}
int main(){
    vector<int>A={-18, 0, 38, 42, 91, 94, 129, 152, 169, 204, 204, 225, 253, 298, 309, 343, 344, 370, 400, 409, 424, 459, 480, 485, 513, 518, 531, 534, 542, 553, 564, 573, 594, 639, 663, 679, 712, 731, 743, 778, 815, 841, 868, 911, 950, 972, 987, 1000, 1029, 1033, 1047, 1096, 1124, 1168, 1171, 1178, 1196, 1217, 1256, 1263, 1291, 1304, 1314 };
    vector<int>B={  36, 38, 38, 74, 84, 105, 121, 156, 170, 179, 191, 227, 249, 296, 315, 356, 366, 374, 415, 443, 451, 459, 472, 498, 505, 509, 558, 600, 619, 661, 684, 715, 754, 782, 796, 805, 815, 853, 868, 871, 891, 925, 929, 967, 999, 1006, 1006, 1048, 1059, 1092, 1132, 1175, 1221, 1252, 1290, 1331, 1361, 1406, 1444, 1462, 1487, 1526, 1572, 1586, 1629, 1647, 1690, 1692, 1704, 1734, 1757, 1773, 1810, 1823, 1846, 1860 };
    vector<int>C={ 0, 27, 57, 94, 102, 116, 140, 166, 207, 233, 239, 268, 296, 332, 343, 382, 383, 398, 411, 435, 444, 472, 486, 523, 531, 574, 597, 600, 607, 641, 651, 677, 692, 725, 728, 734, 736, 767, 793, 797, 832, 874, 904, 933, 938, 947, 961, 988, 1035, 1047 };
    cout<<solve(A,B,C);
}