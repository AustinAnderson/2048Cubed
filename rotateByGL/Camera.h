

#ifndef CAMERA_H
#define CAMERA_H

#include "Algebra.h"

class Camera {
public:
    Camera();
    ~Camera();
    void Orient(Point& eye, Point& focus, Vector& up);
    void Orient(Point& eye, Vector& look, Vector& up);
    void SetViewAngle (double viewAngle);
    void SetNearPlane (double nearPlane);
    void SetFarPlane (double farPlane);
    void SetScreenSize (int screenWidth, int screenHeight);

    Matrix GetProjectionMatrix();
    Matrix GetModelViewMatrix();
    Matrix GetInverseModelViewMatrix();
    Matrix GetOrthographicProjection();

    void RotateV(double angle);
    void RotateU(double angle);
    void RotateUAround(double angle,const Point& center,double distance);
    void RotateW(double angle);
    void Rotate(Point p, Vector axis, double degree);
    void RotateAround(Point p, Vector axis, double angle,const Point& center,double distance);
    void Translate(const Vector &v);

    Vector getV(){
        return v;
    }

    Point GetEyePoint();
    Vector GetLookVector();
    Vector GetUpVector();
    double GetViewAngle();
    double GetNearPlane();
    double GetFarPlane();
    int GetScreenWidth();
    int GetScreenHeight();

    double GetFilmPlanDepth();
    double GetScreenWidthRatio();
    
    
private:
    Point eye;
    Vector look, up, u, v, w;
    double view, Near, Far;
    int width, height;
};
#endif

