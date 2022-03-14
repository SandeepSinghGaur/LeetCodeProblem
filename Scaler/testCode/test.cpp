#include<iostream>  
using namespace std;  
int  main()  
{  
string str1 = "This is C language";  
string str2 = "C++";  
cout << "Before replacement, string is :"<<str1<<'\n';  
str1.replace(8,1,str2);   
cout << "After replacement, string is :"<<str1<<'\n';  
return 0;  
} 