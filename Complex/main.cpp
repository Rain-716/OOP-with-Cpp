#include <iostream>
#include "Complex.h"
using namespace std;
int main()
{
    Complex c1(3,5.6); //初始化对象c1(该对象表示复数3+5.6i)
    Complex c2=4.5;    //用实数4.5初始化c2 (该对象表示复数4.5)
    c1.add(c2);        //将c1与c2相加，结果保存在c1中
    c1.show();         //将c1输出(这时的结果应该是7.5+5.6i)
    return 0;
}
