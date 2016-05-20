/* InternalGrid.cpp
   Created: Fri May 20 16:25:58 CDT 2016
*/

#include "InternalGrid.h"

/*******************************************************************************
  InternalGrid 
  ...
*********************************************************************/
InternalGrid::InternalGrid(){
    grid.clear();
    vector<vector<InternalCell> > l2;
    vector<InternalCell> l1;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                l1.push_back(InternalCell(Point(i,j,k)));
            }
            l2.push_back(l1);
            l1.clear();
        }
        grid.push_back(l2);
        l2.clear();
    }

}

/*******************************************************************************
  shiftPlusX 
  ...
*********************************************************************/
void InternalGrid::shiftPlusX(){

}

/*******************************************************************************
  shiftNegativeX 
  ...
*********************************************************************/
void InternalGrid::shiftNegativeX(){

}

/*******************************************************************************
  shiftPlusY 
  ...
*********************************************************************/
void InternalGrid::shiftPlusY(){

}

/*******************************************************************************
  shiftNegativeY 
  ...
*********************************************************************/
void InternalGrid::shiftNegativeY(){

}

/*******************************************************************************
  shiftPlusZ 
  ...
*********************************************************************/
void InternalGrid::shiftPlusZ(){

}

/*******************************************************************************
  shiftNegativeZ 
  ...
*********************************************************************/
void InternalGrid::shiftNegativeZ(){

}
/*******************************************************************************
  canAddItem
  updates the list of empty cells and returns whether or not the grid is full
  ie player lost
*********************************************************************/
bool InternalGrid::canAddItem(){
    updateEmptyList();
    return gridEmptySpaces.size()>0;
}

/*******************************************************************************
  updateEmptyList 
  updates the list of empty grid cells
*********************************************************************/
void InternalGrid::updateEmptyList(){
    gridEmptySpaces.clear();
    for(unsigned int i=0;i<grid.size();i++){
        for(unsigned int j=0;j<grid[i].size();j++){
            for(unsigned int k=0;k<grid[i][j].size();k++){
                if(grid[i][j][k].isEmpty()){
                    gridEmptySpaces.push_back(&grid[i][j][k]);
                }
            }
        }
    }
}

/*******************************************************************************
  addRandomCell
  changes a random empty cell to 2, the starting value
  by incrementing it's combinations from 0 to 1
*********************************************************************/
void InternalGrid::addRandomCell(){
    if(canAddItem()){
        gridEmptySpaces[rand()%gridEmptySpaces.size()]->doubleValue();
    }
}

