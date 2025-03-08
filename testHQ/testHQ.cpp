/* 
  Specify 5 types: Base, Hqueue, INT, CHAR and PhoneNumber in heteroQueue.h
  Implement these types in heteroQueue.cpp
*/
#include <iostream>
#include <cstdlib>
#include "heteroQueue.h"
using namespace std;
int main()
try
{   
  char c{0};
  Hqueue hq;
  while (cin&&c!='Q'&&c!='q'){   
    cout << "INT, CHAR, PhoneNumber or Quit (I/C/P | Q): ";
    cin >> c;
    if (c=='I'||c=='i'){ 
      int i;
      cout << "Enter an integer: ";
      cin >> i;
      hq.enqueue(new INT(i));
    }
    else if (c=='C'||c=='c'){
      char c;
      cout << "Enter a character: ";
      cin >> c;
      hq.enqueue(new CHAR(c));
    }
    else if (c=='P'||c=='p'){ 
      PhoneNumber* ii{new PhoneNumber};
      cout << "Enter a PhoneNumber(Format: a string and a number): ";
      cin >> *ii;
      hq.enqueue(ii);
    }
    else if (c!='Q'&&c!='q')
      cout << "Wrong Selection, Retry. " << endl;
  }
  if(cin){
    cout << endl << "Dequeue:" << endl;
    while (!hq.isEmpty())
    hq.dequeue();
    cout << endl;
  }
  return 0;
}
catch(Hqueue::bad_op bi)
{  
  cerr << bi.type << ", exit " << endl;
  exit(0);
}