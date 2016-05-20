#ifndef GRIDCUBE
#define GRIDCUBE
#include <vector>
#include "CubeCell.h"
#include "prototyes.h"
//GridCube.h: the grid
//Created: Wed May 18 16:46:33 CDT 2016

using std::vector;
class GridCube {
public:
    GridCube();
    ~GridCube();
    void draw();
    
    //these call MyGlutDisplay, which calls draw, dont call draw here
    void shiftPlusX();
    void shiftNegativeX();
    void shiftPlusY();
    void shiftNegativeY();
    void shiftPlusZ();
    void shiftNegativeZ();
    /////////////////
private:
    vector<vector<vector<CubeCell*> > > cubes;
};
#endif//GRIDCUBE
