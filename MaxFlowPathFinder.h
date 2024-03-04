#pragma once

#include "Triangulations.h"
#include <vector>

class MaxFlowPathFinder {
public:
    MaxFlowPathFinder();
    ~MaxFlowPathFinder();
    QVector<Point3D> findMaxFlowPath( Triangulations& triangulations);
};