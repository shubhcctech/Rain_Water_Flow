#include "stdafx.h"
#include "Vertices_Writer.h"


Vertices_Writer::Vertices_Writer() {

}

Vertices_Writer::~Vertices_Writer() {


}

QVector<GLdouble> Vertices_Writer::vertices_Writer(Triangulations& triangulation) {
    
    QVector<Point3D>& points = triangulation.uniquePoints();
    QVector<Triangle>& triangles = triangulation.triangles();
    QVector<GLdouble> vertices;
    int i = 0;
    for (Triangle& triangle : triangles) {

        vertices.push_back(points[triangle.index1()].X());
        vertices.push_back(points[triangle.index1()].Y());
        vertices.push_back(points[triangle.index1()].Z());

        vertices.push_back(points[triangle.index2()].X());
        vertices.push_back(points[triangle.index2()].Y());
        vertices.push_back(points[triangle.index2()].Z());

        vertices.push_back(points[triangle.index3()].X());
        vertices.push_back(points[triangle.index3()].Y());
        vertices.push_back(points[triangle.index3()].Z());


    }
	return vertices;

}