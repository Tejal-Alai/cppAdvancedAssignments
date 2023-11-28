#include<iostream>
#include<limits>
#include<cfloat>
#include "../headers/BBox.h"
#include "../headers/Triangle.h"
#include "../headers/Point3D.h"

BBox::BBox(std::list<Triangle> triangles)
:mMin(0,0,0),
mMax(0,0,0),
mCenter(0,0,0)
{
    calculateBBox(triangles);
}

BBox::~BBox()
{
}

void BBox::calculateBBox(std::list<Triangle> triangles)
{

   mMax = Point3D(DBL_MIN,DBL_MIN,DBL_MIN);
   mMin = Point3D(DBL_MAX,DBL_MAX,DBL_MAX);

   for(Triangle triangle:triangles)
   {
      Point3D p1=triangle.p1();
      Point3D p2=triangle.p2();
      Point3D p3=triangle.p3();

      compareAndUpdate(p1, mMin, mMax);
      compareAndUpdate(p2, mMin, mMax);
      compareAndUpdate(p3, mMin, mMax);
   }

   mCenter = Point3D((mMin.x()+mMax.x())/2, (mMin.y()+mMax.y())/2, (mMin.z()+mMax.z())/2);
   std::cout<<mMin.x()<<" "<<mMin.y()<<" "<<mMin.z()<<std::endl;
   std::cout<<mMax.x()<<" "<<mMax.y()<<" "<<mMax.z()<<std::endl;
   std::cout<<mCenter.x()<<" "<<mCenter.y()<<" "<<mCenter.z()<<std::endl;
}

void BBox::compareAndUpdate(Point3D pointToCompare, Point3D& min, Point3D& max)
{
    auto giveMaxPoint = [pointToCompare, &max] () mutable{
      
      max.setX(std::max(pointToCompare.x(),max.x()));

      max.setX(std::max(pointToCompare.y(),max.y()));

      max.setX(std::max(pointToCompare.z(),max.z()));

    };

    auto giveMinPoint = [pointToCompare, &min] () mutable{
      
      min.setX(std::min(pointToCompare.x(),min.x()));

      min.setX(std::min(pointToCompare.y(),min.y()));

      min.setX(std::min(pointToCompare.z(),min.z()));

    };

          giveMaxPoint();
          giveMinPoint();
}
