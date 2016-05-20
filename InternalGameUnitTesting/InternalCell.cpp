/* InternalCell.cpp
   Created: Fri May 20 16:25:58 CDT 2016
*/

#include "InternalCell.h"

/*******************************************************************************
  InternalCell 
  ...
*********************************************************************/
InternalCell::InternalCell(const Point& p){
    indexs=p;
    reset();
}

/*******************************************************************************
  isEmpty 
  ...
*********************************************************************/
bool InternalCell::isEmpty(){
    return combinations==0;
}

/*******************************************************************************
  getIndexes 
  ...
*********************************************************************/
Point InternalCell::getIndexes(){
    return indexs;
}

/*******************************************************************************
  getValue 
  ...
*********************************************************************/
int InternalCell::getValue(){
    int toReturn=1<<combinations;
    if(combinations==0) toReturn=combinations;
    return toReturn;
}

/*******************************************************************************
  doubleValue 
  ...
*********************************************************************/
void InternalCell::doubleValue(){
    combinations++;
}

/*******************************************************************************
  reset
  resets cell to empty
*********************************************************************/
void InternalCell::reset(){
    combinations=0;
}

/*******************************************************************************
  operator[]
  allows easy access to location data, fourth value is the number
  of combinations the cell has gone through

  all returned values are immutable
*********************************************************************/
int InternalCell::operator[] (int i) const{
    int toReturn=combinations;
    if(i>=0||i<3) toReturn=(int)indexs[i];
	return toReturn;
};
