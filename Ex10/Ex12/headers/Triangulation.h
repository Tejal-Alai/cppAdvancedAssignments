#pragma once
#include <vector>
#include "Triangle.h"
#include "BBox.h"

class Triangulation
{

public:
    Triangulation(std::vector<Triangle> triangles);
    Triangulation();
    ~Triangulation();

     void print();

    std::vector<Triangle> getTriangles();

private:
    std::vector<Triangle> mTriangles;
    BBox mBBox;
};
