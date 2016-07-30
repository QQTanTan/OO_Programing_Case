#include <stdio.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "calendar.h"

using namespace std;



void input()
{
    int year;
    int month;
    cout<<"Please input the year and month !\n";
    cout<<"year: ";
    cin>>year;
    cout<<"\nmonth: ";
    cin>>month;
    cout<<endl;

}

void print_Title(int year,int month){
    cout<<year<<"/"<<month<<endl;
    cout<<"= = = = = = = = = = = = = = = \n";
    cout<<"SUN MON TUE WED THU FRI SAT\n";
    cout<<"----------------------------\n";
}

void print_Calendar(int y,int m){
    int i,j;
    int firstday;
    int totalday;
    firstday = weekday(y,m,1);
    totalday = dayMonth(y,m);
    for(i = 0; i < firstday; i++) cout<<"    ";
    for(j = 1; j <= totalday; j++){
        if((j + firstday - 1) % 7 == 0) cout<<endl;
        cout<<setw(4)<<j;
    }
    cout<<endl;
}

int weekday(int y,int m,int d){
    struct tm t = {0,0,0,d,m - 1,y - 1900};
    mktime(&t);
    return t.tm_wday;
}
int dayMonth(int y,int m){
    const int mt[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m == 2 && ((y % 400 == 0) || (y % 4 == 0 && y % 100 == 0))) return 29;
    else return mt[m];
}

void print_Tail(){
    cout<<"---------------------------\n";
}
