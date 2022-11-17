#include<iostream>
using namespace std;


namespace userDefined{
    int insideNamespace = 700;
    int cout(){
        return insideNamespace;
    }
}
int myGlobal=120;
int cout(){
    int SquareValue;
    SquareValue = myGlobal * myGlobal;
    return SquareValue;
}
int main()
{
    int cout = 400;
    std::cout<<"The local variable  in main is: "<<cout<<endl;
    std::cout<<"The variable in userDefined namespace is: "<<userDefined::insideNamespace<<endl;
    std::cout<<"The output of cout() in userDefined is: "<<userDefined::cout()<<endl;
    std::cout<<"The value of myGlobal is: "<<::myGlobal<<endl;
    std::cout<<"The output of global cout() is :"<<::cout()<<endl;
    return 0;
}
