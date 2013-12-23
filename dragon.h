#include "CImg.h"
#include "IFS.h"


using namespace cimg_library;

/* Definition of the size of the window */

int sizex=500;
int sizey=500;

/* Definition of the initialization transformations */

Point Transformation1(Point point)
{
    int copy_point0=point[0];
    point[0]=(point[0]/2-point[1]/2+sizex/2)*2/3;
    point[1]=(copy_point0/2+point[1]/2)*2/3+sizey/6;
    return point;
};

Point Transformation2(Point point)
{
    int copy_point0=point[0];
    point[0]=(point[0]/2-point[1]/2+sizex/2)*2/3+sizex/3;
    point[1]=(copy_point0/2+point[1]/2)*2/3+sizey/6;
    return point;
};

/* Definition of the transformations */

Point Transformation3(Point point)
{
    int copy_point0=point[0];
    point[0]=(point[0]/2-point[1]/2+sizex/4+sizex/12+1);
    point[1]=(copy_point0/2+point[1]/2)+sizey/6+2;
    return point;
};

Point Transformation4(Point point)
{
    int copy_point0=point[0];
    point[0]=500-(point[0]/2+point[1]/2)+sizey/4-sizex/12;
    point[1]=(copy_point0/2-point[1]/2+sizex/2);
    return point;
};

/* Image representing the fractal */

CImg<unsigned char> imageOfPoints(Point* points,int sizex,int sizey,int nb_points)
{

    CImg<unsigned char> output(sizex,sizey,1,3);

    for(int i =0; i<nb_points; i++)
    {

        output.atXY(points[i][0],points[i][1],0)=points[i][0]/2%256;
        output.atXY(points[i][0],points[i][1],1)=0;
        output.atXY(points[i][0],points[i][1],2)=points[i][0]/2%256;




    }

    return output;

}
