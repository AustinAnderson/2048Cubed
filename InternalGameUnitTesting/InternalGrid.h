#ifndef INTERNALGRID
#define INTERNALGRID
#include "InternalCell.h"
#include <vector>
#include <ctime>
#include <iostream>
//InternalGrid.h: 
//Created: Fri May 20 15:57:32 CDT 2016
using std::vector;
using std::cout;
using std::endl;
using std::string;
class InternalGrid {
    public:
        InternalGrid();

        void shiftPlusX();//store each movement for external grid to animate with
        void shiftNegativeX();
        void shiftPlusY();
        void shiftNegativeY();
        void shiftPlusZ();
        void shiftNegativeZ();
        bool canAddItem();
        void debugDisplay();
    private:
        void updateEmptyList();
        void addRandomCell();
        vector<vector<vector<InternalCell> > > grid;
        vector<InternalCell*> gridEmptySpaces;
};
#endif//INTERNALGRID
