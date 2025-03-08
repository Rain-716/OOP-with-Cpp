#ifndef INTEGERSET_H_INCLUDED
#define INTEGERSET_H_INCLUDED
class integerSet
{
    private:
        int* a;
        unsigned cap,sz;
    public:
        struct bad_integerSet
        {
            int errnum;
            bad_integerSet (int n=0)
            {
                errnum=n;
            }
        };
        integerSet (unsigned c=0)
        {
            sz=0;
            cap=c;
            a=new int[cap];
        }
        integerSet (const integerSet& s)
        {
            sz=s.sz;
            cap=s.cap;
            a=new int[cap];
            for (unsigned int i=0;i<cap;i++){
                a[i]=s.a[i];
            }
        }
        ~integerSet()
        {
            delete[] a;
        }
        void clear();
        unsigned size() const;
        unsigned capacity() const;
        bool isEmpty() const;
        void print() const;
        void insert (int);
        integerSet setUnion(const integerSet&) const;
        integerSet setIntersection(const integerSet&) const;
        integerSet setDifference(const integerSet&) const;
        integerSet setSymmetricdifference(const integerSet&) const;
        void erase (int);
        bool isMember (int) const;
        bool isSubset (const integerSet&) const;
        integerSet& operator=(const integerSet&);
};
#endif // INTEGERSET_H_INCLUDED
