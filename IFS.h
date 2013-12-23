#ifndef IFS_H_INCLUDED
#define IFS_H_INCLUDED

#include <array>
#include <random>
#include <iostream>


using namespace std;

/* Define IFS specific types */
typedef array<int,2> Point;
typedef Point (*ptr_transformation)(Point);
typedef ptr_transformation* Transformations;

class IFS
{

private:

    int iterations;
    Transformations transformations;
    int sizeTransformations;

public:
    IFS(){};
    ~IFS(){};
    IFS(int _iterations,Transformations _transformations, int sizeTransformations);
    /* Function returning the points after the IFS application */
    Point* getIFS(Point* points, int sizePoints);

};



#endif // IFS_H_INCLUDED
