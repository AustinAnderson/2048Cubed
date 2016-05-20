/* CubeCell.cpp
   Created: Wed May 18 17:25:05 CDT 2016
*/

#include "CubeCell.h"

/*******************************************************************************
  CubeCell 
  ...
*********************************************************************/
CubeCell::CubeCell(double x, double y, double z){
    Init(Point(x,y,z));
}

/*******************************************************************************
  CubeCell 
  ...
*********************************************************************/
CubeCell::CubeCell(const Point& OriginalPosition){
    Init(OriginalPosition);
}
/*******************************************************************************
  Init
  ...
*********************************************************************/
void CubeCell::Init(const Point& OriginalPosition){
    base=OriginalPosition;
    reset();
}

/*******************************************************************************
  updatePosition 
  ...
*********************************************************************/
void CubeCell::updatePosition(const Vector& movement){
    translation=translation+movement;
}

/*******************************************************************************
  draw 
  ...
*********************************************************************/
void CubeCell::draw(){
    Point newPosition=getPosition();
    glPushMatrix();
    glTranslatef(newPosition[0],newPosition[1],newPosition[2]);
    glScalef(.125,.125,.125);
    glutSolidCube(1);//replace with call to draw textured cube
    glPopMatrix();
}

/*******************************************************************************
  getStage 
  ...
*********************************************************************/
int CubeCell::getStage(){
    return stage;
}

/*******************************************************************************
  getPosition 
  ...
*********************************************************************/
Point CubeCell::getPosition(){
    return base+translation;
}

/*******************************************************************************
  reset 
  ...
*********************************************************************/
void CubeCell::reset(){
    translation=Vector();
    stage=1;
}

/*******************************************************************************
  collide 
  ...
*********************************************************************/
bool CubeCell::collide(CubeCell& other){
    //if positions are close enough, collide
}

