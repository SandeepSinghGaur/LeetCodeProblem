#include<iostream>  
using namespace std;  


struct Student {
    string student_name;
    int roll_number;
    float marks_in_math;
    float marks_in_science;
    float marks_in_english;
    Student(string student_name,int roll_number,float marks_in_math,float marks_in_science,float marks_in_english) : student_name(student_name),roll_number(roll_number),marks_in_math(marks_in_math),marks_in_science(marks_in_science),marks_in_english(marks_in_english){}
};
int  main()  
{  
    cout<<"insert Record of 10 Students"<<endl;
    for(int i=0;i<10;i++){
    string sname;
    int roll_number;
    float marks_in_math;
    float marks_in_science;
    float marks_in_english;
    cout<<"Insert the "<<i+1<<" "<<"Student name";
    cin>>sname;
    cout<<"Insert the "<<i+1<<" "<<"Student roll_number";
    cin>>roll_number;
    cout<<"Insert the "<<i+1<<" "<<"Student marks_in_math";
    cin>>marks_in_math;
    cout<<"Insert the "<<i+1<<" "<<"Student marks_in_science";
    cin>>marks_in_science;
    cout<<"Insert the "<<i+1<<" "<<"Student marks_in_english";
    cin>>marks_in_english;
    Student s1=Student(sname,roll_number,marks_in_math,marks_in_science,marks_in_english);
    }
 
} 