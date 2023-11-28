#include<iostream>
#include "../headers/Triangulation.h"
#include "../headers/Triangle.h"

Triangulation::Triangulation(std::vector<Triangle> triangles)
:mBBox(triangles)
{
    mTriangles=triangles;
}

Triangulation::~Triangulation()
{
}

std::vector<Triangle> Triangulation::getTriangles(){
    return mTriangles;
}

void Triangulation::print()
{
    std::cout<<"Inside Triangle"<<std::endl;
}