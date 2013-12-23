#include "IFS.h"

IFS::IFS(int _iterations,Transformations _transformations, int _sizeTransformations)
{
    iterations = _iterations;
    transformations = _transformations;
    sizeTransformations = _sizeTransformations;
};

Point* IFS::getIFS(Point* points, int sizePoints)
{

    Point point;
    int random;

    /* For all the points, apply the transformation a certain number of times */


    for (int i=0; i<sizePoints; i++)
    {
        point = points[i];

        for(int j=0; j<iterations; j++)
        {
            random = rand() % sizeTransformations;

            point=(*(transformations[random]))(point);

        }
        points[i]=point;

    }

    return points;
};
