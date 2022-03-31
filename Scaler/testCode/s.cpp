#include <bits/stdc++.h>
using namespace std;

struct student
{
    string name;
    int roll;
   float marks_in_math;
   float marks_in_science;
   float marks_in_english;
} s[10];

bool cmp(student s1,student s2){
    if(s1.name<s2.name)
    return true ;
    else return false;
}
int main()
{
    vector<student>student_name;
    cout << "Enter information of students: " << endl;

    // storing information
    for(int i = 0; i < 10; ++i)
    {
        s[i].roll = i+1;
        cout << "For roll number" << s[i].roll << "," << endl;

        cout << "Enter name: ";
        cin >> s[i].name;

        cout << "Enter marks_in_math: ";
        cin >> s[i].marks_in_math;

        cout << "Enter marks_in_science: ";
        cin >> s[i].marks_in_science;

        cout << "Enter marks_in_english: ";
        cin >> s[i].marks_in_english;
        
        student_name.push_back({s[i].name,s[i].roll,s[i].marks_in_math,s[i].marks_in_science,s[i].marks_in_english});
        cout << endl;
    }
   
    
   sort(student_name.begin(),student_name.end(),cmp);
    cout << "Displaying Information: " << endl;
     

    // Displaying information
    for(int i = 0; i < 10; ++i)
    {
        cout << "Name: " << student_name[i].name << endl;
        cout << "Roll number: " << student_name[i].roll << endl;
        cout << "Marks: " << student_name[i].marks_in_math << endl;
        cout << "Marks: " << student_name[i].marks_in_science << endl;
        cout << "Marks: " << student_name[i].marks_in_english << endl;
    }

    cout << "Displaying Average Marks Student Name: " << endl;

    unordered_map<string,float>um;
    for(auto it:student_name){
        float avg_marks=(it.marks_in_math+it.marks_in_science+it.marks_in_english)/3;
        um.insert({it.name,avg_marks});
    }
    float max_marks=INT_MIN;
  for(auto it:um){
      max_marks=max(max_marks,it.second);
  }
  cout<<"Max Average marks is"<<max_marks;
  for(auto it:um){
      if(it.second==max_marks){
          cout<<"This student score max avg marks:"<<" "<<it.first<<" ";
      }
  }

    return 0;
}