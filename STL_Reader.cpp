#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "stdafx.h"
#include "STL_Reader.h"
#include "Triangles.h"

// Constructor

STL_Reader::STL_Reader() {}

// Destructor

STL_Reader::~STL_Reader() {}

// Reads stl File.
Triangulations& STL_Reader::stlReader()
{
    std::ifstream inputFile("D:\\Shubham_Workspace\\CPP\\Assignments\\FileReader\\STL_Reader\\resources\\cube.stl");
    Triangulations& triangulations = Triangulations::getInstance();
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << "inputFile" << std::endl;
    }
    // Specify Point dimension
    std::vector<Point3D> points;
    std::vector<Triangle> triangles;
    std::map<Point3D, int> pointMap;
    int count = 0;
    int index;
    int index1;
    int index2;
    int index3;
    std::string line;
    while (std::getline(inputFile, line))
    {
        if (line.find("vertex") != std::string::npos)
        {
            GLdouble xCoordinate;
            GLdouble yCoordinate;
            GLdouble zCoordinate;
            std::string token;
            std::istringstream vertexStream(line);
            vertexStream >> token >> xCoordinate >> yCoordinate >> zCoordinate;
            Point3D point3D(xCoordinate, yCoordinate, zCoordinate);
            auto iterator = pointMap.find(point3D);
            if (iterator == pointMap.end())
            {
                pointMap[point3D] = triangulations.uniquePoints().size();
                triangulations.uniquePoints().push_back(point3D);
            }
            if (count == 0)
            {   
                
                index1 = pointMap[point3D];
                count++;
            }
            else if (count == 1)
            {
                
                index2 = pointMap[point3D];
                count++;
            }
            else if (count == 2)
            {
               
                index3 = pointMap[point3D];
                count++;
               
                triangulations.triangles().push_back(Triangle(index1, index2, index3));
                count = 0;
            }
        }
    }
    std::cout << "Points Reading Completed" << std::endl;
    inputFile.close();
    return triangulations;
}
