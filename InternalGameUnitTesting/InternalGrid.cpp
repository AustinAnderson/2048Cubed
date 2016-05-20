/* InternalGrid.cpp
   Created: Fri May 20 16:25:58 CDT 2016
*/

#include "InternalGrid.h"

/*******************************************************************************
  InternalGrid 
  ...
*********************************************************************/
InternalGrid::InternalGrid(){
    srand(time(0));
    int InitCellNumber=8;
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
    for(int i=0;i<InitCellNumber;i++){
        addRandomCell();
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

void InternalGrid::debugDisplay(){
    //fill each display in slices along the z axis
    vector<vector<string> > displays(4,vector<string>(4,""));
    vector<string> bottoms(4,"");
    char buffer[256];
    for(int z=0;z<4;z++){
        for(int y=0;y<4;y++){
            for(int x=0;x<4;x++){
                sprintf(buffer,"|{%d,%d,%d} %3d",grid[x][y][z][0],grid[x][y][z][1],grid[x][y][z][2],grid[x][y][z].getValue());
                string add(buffer);
                displays[z][y]+=add;
                if(z<2){
                    bottoms[y]+="|";
                    bottoms[y]+=string(add.size()-1,'_');
                }
            }
            if(z<2)bottoms[y]+="|  ";
        }
    }
    //merge them to display side by side
    vector<string> finalDisplay(4,"");
    vector<string> finalDisplay2(4,"");
    cout<<bottoms[0]<<endl;
    for(int y=0;y<4;y++){
        for(int z=0;z<2;z++){
            finalDisplay[y]+=displays[z][y];
            finalDisplay[y]+="|  ";
        }
        cout<<finalDisplay[y]<<endl;
        cout<<bottoms[y]<<endl;
    }
    cout<<bottoms[0]<<endl;
    for(int y=0;y<4;y++){
        for(int z=2;z<4;z++){
            finalDisplay2[y]+=displays[z][y];
            finalDisplay2[y]+="|  ";
        }
        cout<<finalDisplay2[y]<<endl;
        cout<<bottoms[y]<<endl;
    }



}
