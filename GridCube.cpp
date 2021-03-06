/* GridCube.cpp
   Created: Wed May 18 17:25:52 CDT 2016
*/

#include "GridCube.h"

/*******************************************************************************
  GridCube 
  ...
*********************************************************************/
GridCube::GridCube(){
    vector<CubeCell*>cubesL1(4,NULL);
    vector<vector<CubeCell*> > cubesL2(4,cubesL1);
    cubes=vector<vector<vector<CubeCell*> > >(4,cubesL2);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                cubes[i][j][k]=new CubeCell(i*.25-.375,j*.25-.375,k*.25-.375);
            }
        }
    }
}

/*******************************************************************************
  ~GridCube 
  ...
*********************************************************************/
GridCube::~GridCube(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                delete cubes[i][j][k];
            }
        }
    }
}

/*******************************************************************************
  draw 
  ...
*********************************************************************/
void GridCube::draw(){
    int ndxs[3];
    for(ndxs[0]=0;ndxs[0]<4;ndxs[0]++){
        for(ndxs[1]=0;ndxs[1]<4;ndxs[1]++){
            for(ndxs[2]=0;ndxs[2]<4;ndxs[2]++){
                for(int i=0;i<3;i++){
                    if(ndxs[i]==3){
                        if(0==i&&2==ndxs[1]&&2==ndxs[2]){
                            glColor3f(1,0,0);
                        }
                        if(1==i&&2==ndxs[0]&&2==ndxs[2]){
                            glColor3f(0,1,0);
                        }
                        if(2==i&&2==ndxs[0]&&2==ndxs[1]){
                            glColor3f(0,1,1);
                        }
                    }
                    else if(ndxs[i]==0){
                        if(0==i&&2==ndxs[1]&&2==ndxs[2]){
                            glColor3f(1,0,1);
                        }
                        if(1==i&&2==ndxs[0]&&2==ndxs[2]){
                            glColor3f(1,1,0);
                        }
                        if(2==i&&2==ndxs[0]&&2==ndxs[1]){
                            glColor3f(1,1,1);
                        }
                    }
                    else{
                        glColor3f(0,0,1);
                    }
                }
                cubes[ndxs[0]][ndxs[1]][ndxs[2]]->draw();
            }
        }
    }
}

/*******************************************************************************
  shiftPlusX 
  ...
*********************************************************************/
void GridCube::shiftPlusX(){

}

/*******************************************************************************
  shiftNegativeX 
  ...
*********************************************************************/
void GridCube::shiftNegativeX(){

}

/*******************************************************************************
  shiftPlusY 
  ...
*********************************************************************/
void GridCube::shiftPlusY(){

}

/*******************************************************************************
  shiftNegativeY 
  ...
*********************************************************************/
void GridCube::shiftNegativeY(){

}

/*******************************************************************************
  shiftPlusZ 
  ...
*********************************************************************/
void GridCube::shiftPlusZ(){

}

/*******************************************************************************
  shiftNegativeZ 
  ...
*********************************************************************/
void GridCube::shiftNegativeZ(){

}

