//
//  main.cpp
//  2048Cubed
//
//

#include <stdio.h>
#include <stdlib.h>


#include "Camera.h"
#include "GridCube.h"
#include "prototyes.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const float CAMERA_MOVE_INC = 0.02;
const float CAMERA_ZOOM_FACTOR = 1.5;
const float CAMERA_ROTATE_FACTOR = 2;

GridCube gridCube;

Camera* camera = new Camera();

bool firstFrame=true;

bool showGrid = true;
bool debugMode = true;
bool wireframe = false;

bool lastRotateOnX = true;

int	 camRotU = 0;
int	 camRotV = 0;
int	 camRotW = 0;
int  viewAngle = 45;
float eyeX = .45;
float eyeY = 0;
float eyeZ = 2.1;
float lookX = 0;
float lookY = 0;
float lookZ = -1;
Vector rotation(0,0,0);
Vector lookV(lookX, lookY, lookZ);
Vector upV(0, 1, 0);
Point eyeP(eyeX, eyeY, eyeZ);
float clipNear = 0.001;
float clipFar = 30;
std::ostream& operator<<(std::ostream& os,const Point& p){
    os<<"{"<<p[0]<<","<<p[1]<<","<<p[2]<<"}";
    return os;
}
std::ostream& operator<<(std::ostream& os,const Vector& v){
    os<<"{"<<v[0]<<","<<v[1]<<","<<v[2]<<"}";
    return os;
}

int main_window;

void myGlutIdle(void);
void myGlutDisplay(void);
void onExit(void);
void draw_grid();
void myGlutReshape(int x, int y);
void myKeyboardFunc(unsigned char key, int x, int y);
void myKeyboardSpecFunc(int key, int x, int y);
void displayText( float x, float y, int r, int g, int b, const char *string );

Vector getFace(const Vector& lookV,const Vector& x=Vector(1,0,0),const Vector& y=Vector(0,1,0),const Vector& z=Vector(0,0,1)){
    double dotx=dot(lookV,x);
    double doty=dot(lookV,y);
    double dotz=dot(lookV,z);
    int maxNdx=0;
    Vector toReturn(dotx,doty,dotz);
    Vector abs(dotx,doty,dotz);
    for(int i=0;i<3;i++){
        if(abs[i]<0) abs[i]=-abs[i];
        if(abs[maxNdx]<abs[i])maxNdx=i;
    }
    for(int i=0;i<3;i++){
        if(i!=maxNdx) toReturn[i]=0;
        else toReturn[i]/=abs[i];
    }
    return toReturn;
}


void displayText( float x, float y, int r, int g, int b, const char *string ) {
    int j = strlen( string );
    
    glColor3f( r, g, b );
    glRasterPos2f( x, y );
    for( int i = 0; i < j; i++ ) {
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
    }
}

void myGlutIdle(void){
    if(glutGetWindow() != main_window) glutSetWindow(main_window);
    glutPostRedisplay();
}
void myGlutDisplay(void){
    
    if(wireframe){
        glDisable(GL_POLYGON_OFFSET_FILL);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }else{
        glEnable(GL_POLYGON_OFFSET_FILL);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    
    glClearColor(.9f, .9f, .9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    camera->SetViewAngle(viewAngle);
    camera->SetNearPlane(clipNear);
    camera->SetFarPlane(clipFar);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    Matrix projection = camera->GetProjectionMatrix();
    glMultMatrixd(projection.unpack());


    glMatrixMode(GL_MODELVIEW);
    Matrix modelViewInv = camera->GetInverseModelViewMatrix();
    glMultMatrixd(modelViewInv.unpack());
    if(firstFrame){
        glLoadIdentity();
    }
    camera->Orient(eyeP, lookV, upV);
    camera->RotateV(camRotV);
    camera->RotateU(camRotU);
    camera->RotateW(camRotW);
    Matrix modelView = camera->GetModelViewMatrix();
    glMultMatrixd(modelView.unpack());
    glutPostRedisplay();
    if(firstFrame){
        firstFrame=false;
        glRotatef(12,0,1,0);
    }
    
    
    if(debugMode){
        //TODO: fix text display
        //displayText( 50,50, 255,0,0, "debug" );
        draw_grid();
        //drawing the axes
        glDisable(GL_LIGHTING);
        glLineWidth(2);
        glBegin(GL_LINES);
        double wag=.02;
        for(double k=.1;k<1;k+=.1){
            for(int i=-1;i<2;i++){
                for(int j=-1;j<2;j++){
                    glColor3f(1.0, 0.0, 0.0);
                    glVertex3f(0, 0, 0); glVertex3f(1, k*wag*i, k*wag*j);
                    glColor3f(0.0, 1.0, 0.0);
                    glVertex3f(0, 0, 0); glVertex3f(k*wag*i, 1, k*wag*j);
                    glColor3f(0.0, 0.0, 1.0);
                    glVertex3f(0, 0, 0); glVertex3f(k*wag*i, k*wag*j, 1);
                }
            }
        }
        glEnd();
        glLineWidth(1);
        glEnable(GL_LIGHTING);
    }
    gridCube.draw();
    /*
                glTranslatef(ndxs[0]*.25-.375,ndxs[1]*.25-.375,ndxs[2]*.25-.375);
                glutSolidCube(.125);
                glColor3f(0,0,1);
                glPopMatrix();
            }
        }
    }
    */
    ///
    
    glColor3f(0,0,0);
    glutSolidCube(20);
    glColor3f(.5,.5,.5);
    glPushMatrix();
    glLoadIdentity();
    glScalef(1,2,1);
    glTranslatef(1,0,-3);
    glRotatef(-10,0,1,0);
    glutSolidCube(1);
    glPopMatrix();
    glutSwapBuffers();
    glutPostRedisplay();

}
void increment(int axis,int value){
    int v=int(rotation[axis]+value)%360;
    if(v<0) v+=360;
    rotation[axis]=v;
}
void myKeyboardSpecFunc(int key, int x, int y){
    std::cout<<camera->getV()<<std::endl;
    if(key==GLUT_KEY_RIGHT){
        //GDB 1
    }
}

void myKeyboardFunc(unsigned char key, int x, int y){
    //std::cout << "key: " << key << "\nx: " << x << "\ny: " << y << std::endl;
    
    
    /*
     w - shift camera up
     s - shift camera down
     d - shift camera right
     a - shift camera left
     r - shift camera forward
     f - shift camera back
     + - zoom in
     - - zoom out
     */
    int steps=45;
    int inc=90/steps;
    switch(key){
        case 'i': 
            for(int i=0;i<steps;i++){
                glRotatef(inc,1,0,0);
                myGlutDisplay();
            }
            break;
            
        case 'k': 
            for(int i=0;i<steps;i++){
                glRotatef(-inc,1,0,0);
                myGlutDisplay();
            }
            break;
            
        case 'j': 
            for(int i=0;i<steps;i++){
                glRotatef(inc,0,1,0);
                myGlutDisplay();
            }
            break;
            
        case 'l': 
            for(int i=0;i<steps;i++){
                glRotatef(-inc,0,1,0);
                myGlutDisplay();
            }
            break;
            
        case 'u': 
            for(int i=0;i<steps;i++){
                glRotatef(inc,0,0,1);
                myGlutDisplay();
            }
            break;
        case 'o': 
            for(int i=0;i<steps;i++){
                glRotatef(-inc,0,0,1);
                myGlutDisplay();
            }
            break;
        case 'w': eyeP[1] += CAMERA_MOVE_INC;
            break;
            
        case 's': eyeP[1] -= CAMERA_MOVE_INC;
            break;
            
        case 'a': eyeP[0] -= CAMERA_MOVE_INC;
            break;
            
        case 'd': eyeP[0] += CAMERA_MOVE_INC;
            break;
            
        case 'r': eyeP[2] -= CAMERA_MOVE_INC;
            break;
            
        case 'f': eyeP[2] += CAMERA_MOVE_INC;
            break;
            
        case '+': eyeP[0] /= CAMERA_ZOOM_FACTOR;
                  eyeP[1] /= CAMERA_ZOOM_FACTOR;
                  eyeP[2] /= CAMERA_ZOOM_FACTOR;
            break;
            
        case '-': eyeP[0] *= CAMERA_ZOOM_FACTOR;
                  eyeP[1] *= CAMERA_ZOOM_FACTOR;
                  eyeP[2] *= CAMERA_ZOOM_FACTOR;
            break;
            
        case ' ': camRotV=0;
                  camRotU=0;
                  camRotW=0;
            break;
            
        case 'q': wireframe = (wireframe)? false:true;
            break;
    }
    
    glutPostRedisplay();
}

void onExit(void){
    if(camera){
        delete camera;
    }
    
}

void myGlutReshape(int x, int y){
    float xy_aspect;
    
    xy_aspect = (float)x / (float)y;
    glViewport(0, 0, x, y);
    
    camera->SetScreenSize(x, y);
    
    glutPostRedisplay();
}

void draw_grid(){
    /*
    int grid_size = 20;
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glTranslatef(-grid_size/2,0,-grid_size/2);
    glColor3f( .2, .2, .2 );
    for(float i = 0 ; i < grid_size; i+=.2){
        glBegin(GL_LINES);
        glVertex3f( 0.0, 0.0, i );  glVertex3f( grid_size, 0.0, i );
        glVertex3f( i, 0.0, 0.0 );  glVertex3f( i, 0.0, grid_size );
        glEnd();
    }
    
    glBegin(GL_LINES);
    glVertex3f( 0.0, 0.0, grid_size );  glVertex3f( grid_size, 0.0, grid_size );
    glVertex3f( grid_size, 0.0, 0.0 );  glVertex3f( grid_size, 0.0, grid_size );
    glEnd();
    glPopMatrix();
    glEnable( GL_LIGHTING );
    */
    
}

int main(int argc, char* argv[]){
    atexit(onExit);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    
    main_window = glutCreateWindow("Graphics Final");
    glutDisplayFunc(myGlutDisplay);
    glutReshapeFunc(myGlutReshape);
    glutKeyboardFunc(myKeyboardFunc);
    glutSpecialFunc(myKeyboardSpecFunc);

    
    glClearColor (0.48, 0.48, 0.48, 0.0);
    glShadeModel (GL_SMOOTH);
    
    GLfloat light_pos0[] = {0.0f, 0.0f, 1.0f, 0.0f};
    GLfloat diffuse[] = {0.5f, 0.5f, 0.5f, 0.0f};
    GLfloat ambient[] = {0.05f, 0.05f, 0.05f, 0.0f};
    
    glLightfv (GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv (GL_LIGHT0, GL_POSITION, light_pos0);
    
    glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);
    
    glEnable(GL_LIGHTING);
    glEnable (GL_LIGHT0);
    glEnable (GL_DEPTH_TEST);

    glPolygonOffset(1, 1);
    
    
    srand (time(NULL));
    
    
    glutMainLoop();
    
    return EXIT_SUCCESS;
    
}
