#ifndef CUBECELL
#define CUBECELL
#include "Algebra.h"
#include "prototyes.h"
//CubeCell.h: an individual cube of the grid
//Created: Wed May 18 16:46:33 CDT 2016
//
class CubeCell {
public:
    CubeCell(double x, double y, double z);
    CubeCell(const Point& OriginalPosition);
    void updatePosition(const Vector& movement);
    void draw();
    int getStage();
    Point getPosition();
    void reset();
    bool collide(CubeCell& other);
    
private:
    void Init(const Point& OriginalPosition);
    int stage;//how many combinations this cube has, 
    //ie 2^stage is the number the cube displays
    Point base;
    Vector translation;
};
#endif//CUBECELL
