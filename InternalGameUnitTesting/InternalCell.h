#ifndef INTERNALCELL
#define INTERNALCELL
#include "Algebra.h"
class InternalCell{
    public:
        InternalCell(const Point& p);
        bool isEmpty();
        Point getIndexes();
        int getValue();
        void doubleValue();
        void reset();
	    int operator[] (int i) const;
    private:
        Point indexs;
        int combinations;
};
#endif//INTERNALCELL
