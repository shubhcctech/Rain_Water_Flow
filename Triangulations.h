#pragma once


#include <vector>
#include "Triangles.h"

// To increase the efficiency .

class Triangulations
{
public:

    static Triangulations& getInstance();
    QVector<Point3D>& uniquePoints();
    QVector<Triangle>& triangles();

private:

    Triangulations();
    QVector<Point3D> mUniquePoints;
    QVector<Triangle> mTriangles;
    Triangulations(const Triangulations& obj) = delete;
};
