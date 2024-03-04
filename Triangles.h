#pragma once
#pragma once

#include <vector>
#include "Points.h"

// Class to construct triangles according to points.

class Triangle
{

public:

    Triangle();
    Triangle(const int index);
    Triangle(const int index1, const int index2, const int index3);
    ~Triangle();
    int index() const;
    int index1() const;
    int index2() const;
    int index3() const;
    void setIndex(int index);
    void setIndex1(int index1);
    void setIndex2(int index2);
    void setIndex3(int index3);

private:

    int mIndex;
    int mIndex1;
    int mIndex2;
    int mIndex3;
};

