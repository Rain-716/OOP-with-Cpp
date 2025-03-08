#include <iostream>
#include "integerSet.h"
using namespace std;
int main()
{
    try
    {
        // ***** test for initialization *****
        integerSet s1 {100};
        integerSet s2 {110};

        // ***** test for printing *****
        cout << "Set s1 after initialization: " << endl;
        s1.print();
        cout << endl;

        // ***** test for sizing *****
        cout << "The number of elements in Set s1: " << s1.size() << endl;
        cout << "The capacity of Set s1: " << s1.capacity() <<endl;
        cout << endl;

        cout << "Set s2 after initialization: " << endl;
        s2.print();
        cout << endl;
        cout << "The number of elements in Set s2: " << s2.size() << endl;
        cout << "The capacity of Set s2: " << s2.capacity() << endl;
        cout << endl;

        // ***** test for inserting *****
        for (int i=200;i<250;i++) s1.insert(i);
        for (int i=130;i<230;i++) s2.insert(i);
        cout << "Set s1 after insertion: " << endl;
        s1.print();
        cout << endl;
        cout << "The number of elements in Set s1: " << s1.size() << endl;
        cout << "The capacity of Set s1: " << s1.capacity() << endl;
        cout << endl;

        cout << "Set s2 after insertion: " << endl;
        s2.print();
        cout << endl;
        cout << "The number of elements in Set s2: " << s2.size() << endl;
        cout << "The capacity of Set s2: " << s2.capacity() << endl;
        cout << endl;

        // ***** test for union *****
        cout << "Union of two integer sets s1 and s2: " << endl;
        s1.print();
        cout << " Union ";
        s2.print();
        cout << " = ";
        integerSet r1 {s1.setUnion(s2)};
        r1.print();
        cout << endl;
        cout << "The number of elements in union of two integer sets: " << r1.size() << endl;
        cout << "The capacity of union of two integer sets: " << r1.capacity() << endl;
        cout << endl;

        // ***** test for intersection *****
        cout << "intersection of two integer sets s1 and s2: " << endl;
        s1.print();
        cout << " intersection ";
        s2.print();
        cout << " = ";
        integerSet r2 {s1.setIntersection(s2)};
        r2.print();
        cout << endl;
        cout << "The number of elements in intersection of two integer sets: " << r2.size() << endl;
        cout << "The capacity of intersection of two integer sets: " << r2.capacity() << endl;
        cout << endl;

        // ***** test for difference *****
        cout << "difference of two integer sets s1 and s2: " << endl;
        s1.print();
        cout << " difference ";
        s2.print();
        cout << " = ";
        integerSet r3 {s1.setDifference(s2)};
        r3.print();
        cout << endl;
        cout << "The number of elements in difference of two integer sets s1 and s2: " << r3.size() << endl;
        cout << "The capacity of difference of two integer sets s1 and s2: " << r3.capacity() << endl;
        cout << endl;

        cout << "difference of two integer sets s2 and s1: " << endl;
        s2.print();
        cout << " difference ";
        s1.print();
        cout << " = ";
        integerSet r4 {s2.setDifference(s1)};
        r4.print();
        cout << endl;
        cout << "The number of elements in difference of two integer sets s2 and s1: " << r4.size() << endl;
        cout << "The capacity of difference of two integer sets s2 and s1: " << r4.capacity() << endl;
        cout << endl;

        // ***** test for symmetric difference *****
        cout << "symmetric difference of two integer sets s1 and s2: " << endl;
        s1.print();
        cout << " symmetric difference ";
        s2.print();
        cout << " = ";
        integerSet r5 {s1.setSymmetricdifference(s2)};
        r5.print();
        cout << endl;
        cout << "The number of elements in symmetric difference of two integer sets s1 and s2: " << r5.size() << endl;
        cout << "The capacity of symmetric difference of two integer sets s1 and s2: " << r5.capacity() << endl;
        cout << endl;

        // ***** test for assignment *****
        cout << "Set s1 after assignment s1=s2: " << endl;
        s1=s2;
        s1.print();
        cout << endl;
        cout << "The number of elements in Set s1: " << s1.size() << endl;
        cout << "The capacity of Set s1: " << s1.capacity() << endl;
        cout<<endl;

        // ***** test for clear *****
        cout << "Set s2 after erasing all elements: " << endl;
        s2.clear();
        s2.print();
        cout << endl;
        cout << "The number of elements in Set s2: " << s2.size() << endl;
        cout << "The capacity of Set s2: " << s2.capacity() << endl;
        cout << endl;

        // ***** test for isEmpty *****
        if (s1.isEmpty()){
            cout << "Set s1 is empty" << endl;
        }
        else {
            cout << "Set s1 is NOT empty" << endl;
        }
        if (s2.isEmpty()){
            cout << "Set s2 is empty" << endl;
        }
        else {
            cout << "Set s2 is NOT empty" << endl;
        }
        cout << endl;

        // ***** test for erase *****
        cout << "Set s1 after erasing an element 211: " << endl;
        s1.erase(211);
        s1.print();
        cout << endl;
        cout << "The number of elements in Set s1: " << s1.size() << endl;
        cout << "The capacity of Set s1: " << s1.capacity() << endl;
        cout << endl;

        cout << "Set s1 after erasing an element 288: " << endl;
        s1.erase(288);
        s1.print();
        cout << endl;
        cout << "The number of elements in Set s1: " << s1.size() << endl;
        cout << "The capacity of Set s1: " << s1.capacity() << endl;
        cout << endl;

        // ***** test for isMember *****
        int e=222;
        if (s1.isMember(e)){
            cout << e << " is a member of s1" << endl;
        }
        else {
            cout << e << " is NOT a member of s1" << endl;
        }
        e+=888;
        if (s1.isMember(e)){
            cout << e << " is a member of s1" << endl;
        }
        else {
            cout << e << " is NOT a member of s1" << endl;
        }
        cout << endl;

        // ***** test for isSubset *****
        if (s1.isSubset(s2)){
            cout << "Set s2 is a subset of s1" << endl;
        }
        else {
            cout << "Set s2 is NOT a subset of s1" << endl;
        }
        cout << endl;

        cout << "Insert an element 888 into set s2: " << endl;
        s2.insert(888);
        cout << "Set s2: " << endl;
        s2.print();
        cout << endl;
        cout << "The number of elements in Set s2:" << s2.size() << endl;
        cout << "The capacity of Set s2: " << s2.capacity() << endl;

        if (s1.isSubset(s2)){
            cout << "Set s2 is a subset of s1" << endl;
        }
        else {
            cout << "Set s2 is NOT a subset of s1" << endl;
        }
        cout<<endl;

        // ***** test for exception throwing *****
        cout << "insert 1000 elements from 0 to 999 into set s1:" << endl;
        for (int i=0;i<1000;i++){
            s1.insert(i);
        }
    }

    // ***** exception handling *****
    catch (integerSet::bad_integerSet bad_integerSet)
    {
        cout << "bad integerSet: maximum elements reached, exit" << endl;
    }
    return 0;
}
