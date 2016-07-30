#include "calendar.h"
#include <iostream>

using namespace std;

int main()
{
    int year;
    int month;
    cout<<"Please input the year and month !\n";
    cout<<"year: ";
    cin>>year;
    cout<<"month: ";
    cin>>month;
    cout<<endl;
    //input();
    print_Title(year,month);
    print_Calendar(year,month);
    print_Tail();
}
