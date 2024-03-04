#include "stdafx.h"
#include "Points.h"
Point3D::Point3D() {

}
Point3D::Point3D(GLdouble xCoordinate, GLdouble yCoordinate, GLdouble zCoordinate)
    : mX(xCoordinate), mY(yCoordinate), mZ(zCoordinate) {}

Point3D::~Point3D() {}

GLdouble Point3D::X() const {
    return mX;
}

GLdouble Point3D::Y() const {
    return mY;
}

GLdouble Point3D::Z() const {
    return mZ;
}

bool Point3D::operator<(const Point3D& pointsOther) const {
    if (mX < pointsOther.mX) {
        return true;
    }
    if (mX > pointsOther.mX) {
        return false;
    }

    if (mY < pointsOther.mY) {
        return true;

    }
    if (mY > pointsOther.mY) {
        return false;
    }

    return mZ < pointsOther.mZ;
}
