#include <iostream>
using namespace std;
int main()
{
    int marks;
    cout<<"Enter your marks (Out of 20): - ";
    cin>>marks;
    string markResult =(marks > (20/2)) ? "Pass" : "Failure";
    cout<<markResult<<endl;
    string grade = (marks >= 16) ? "A" : (marks >= 14) ? "B" : (marks >= 10) ? " C" :" D";
    cout<<"Grade: "<<grade<<endl;
}