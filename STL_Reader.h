#pragma once

#include <string>
#include <vector>
#include "Triangles.h"
#include"Triangulations.h"

// Class to read Files .stl and .obj.

class STL_Reader {
public:
    STL_Reader();
    ~STL_Reader();
    Triangulations& stlReader();


};