#pragma once
#include "Points.h"
#include"Triangulations.h"


class Vertices_Writer {


public:
	Vertices_Writer();
	~Vertices_Writer();
	QVector<GLdouble> vertices_Writer(Triangulations& triangulation);
};