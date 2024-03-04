#pragma once
#include "OpenGLWindow.h"

class Point3D {
public:

    Point3D();
    Point3D(GLdouble xCoordinate, GLdouble yCoordinate, GLdouble zCoordinate);
    ~Point3D();
    GLdouble X() const;
    GLdouble Y() const;
    GLdouble Z() const;
    bool operator<(const Point3D& pointOther) const;

private:
    GLdouble mX;
    GLdouble mY;
    GLdouble mZ;
};
