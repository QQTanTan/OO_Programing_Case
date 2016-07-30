#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int Student_Number = 30;
const int Student_grade = 5;

struct StudentInformation{
    string Name;
    string Number;
    double Scroe[5];
    double Total;
    int Srank;
}student[Student_Number];

int cmp(StudentInformation a,StudentInformation b){
    return a.Total > b.Total;
}

int cmp2(StudentInformation a,StudentInformation b){
    return a.Number < b.Number;
}

int main(){
    int i;
    int j;
    string str;
    freopen("data.txt","r",stdin);
    for(i = 0; i < Student_Number; i++){
       cin>>student[i].Name;
       cin>>student[i].Number;
       for(j = 0; j < Student_grade;j++){
            cin>>student[i].Scroe[j];
            student[i].Total += student[i].Scroe[j];
       }
    }
    sort(student,student + Student_Number,cmp);
    for(i = 0; i < Student_Number; i++){
        student[i].Srank = i + 1;
    }
    sort(student,student + Student_Number,cmp2);
    for(i = 0; i < Student_Number; i++){
        cout<<student[i].Name<<" "<<student[i].Number<<" "<<student[i].Srank<<" "<<student[i].Total<<endl;
    }

    return 0;
}
