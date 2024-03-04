#include "stdafx.h"
#include "Triangulations.h"

Triangulations::Triangulations()
{
}

Triangulations& Triangulations::getInstance()
{
    static Triangulations instance;
    return instance;
}

QVector<Point3D>& Triangulations::uniquePoints()
{
    return mUniquePoints;
}

QVector<Triangle>& Triangulations::triangles()
{
    return mTriangles;
}