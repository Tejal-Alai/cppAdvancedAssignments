#include "../headers/Point3D.h"
#include "../headers/Reader.h"
#include <iostream>
#include <sstream>
#include <fstream>

Reader::Reader(std::string filePath)
{
    mFilePath = filePath;
}

Reader::~Reader()
{
}

// use lambada function

auto isFileExist = []()
{
    return "File does not exist";
};

void Reader::getTriangles(std::deque<Triangle> &triangles)
{
    std::ifstream dataFile;
    dataFile.open(mFilePath);
    if (!dataFile.is_open())
    {
        std::cout << isFileExist();
        return;
    }

    std::string line;

    while (std::getline(dataFile, line))
    {
        std::cout << line << std::endl;
        if (line.find("vertex") != std::string::npos)
        {
            std::istringstream iss(line);
            std::string token;
            double x, y, z;

            iss >> token >> x >> y >> z;

            Point3D point1(x, y, z);

            std::getline(dataFile, line);
            std::cout << line << std::endl;
            std::istringstream iss1(line);
            iss1 >> token >> x >> y >> z;
            Point3D point2(x, y, z);

            std::getline(dataFile, line);
            std::cout << line << std::endl;
            std::istringstream iss2(line);
            iss2 >> token >> x >> y >> z;
            Point3D point3(x, y, z);

            Triangle triangle(point1, point2, point3);
            triangles.push_back(triangle);
        }
    }
    dataFile.close();
}