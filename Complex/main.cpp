#include <iostream>
#include "Complex.h"
using namespace std;
int main()
{
    Complex c1(3,5.6); //��ʼ������c1(�ö����ʾ����3+5.6i)
    Complex c2=4.5;    //��ʵ��4.5��ʼ��c2 (�ö����ʾ����4.5)
    c1.add(c2);        //��c1��c2��ӣ����������c1��
    c1.show();         //��c1���(��ʱ�Ľ��Ӧ����7.5+5.6i)
    return 0;
}
