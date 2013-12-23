#include "CImg.h"
#include "IFS.h"


using namespace cimg_library;

/* Definition of the size of the window */
int sizex=500;
int sizey=500;

/* Definition of the transformations */
Point Transformation1(Point point)
{
    point[0]=point[0]/2;
    point[1]=point[1]/2;
    return point;
};

Point Transformation2(Point point)
{
    point[0]=point[0]/2;
    point[1]=point[1]+(sizey-1-point[1])/2;
    return point;
};

Point Transformation3(Point point)
{
    point[0]=point[0]+(sizex-1-point[0])/2;
    point[1]=point[1]+(sizey-1-point[1])/2;
    return point;
};

/* Image representing the fractal */
CImg<unsigned char> imageOfPoints(Point* points,int sizex,int sizey,int nb_points)
{

    CImg<unsigned char> output(sizex,sizey,1,3);

    for(int i =0; i<nb_points; i++)
    {
        output.atXY(points[i][0],points[i][1],0)=0;
        output.atXY(points[i][0],points[i][1],1)=points[i][0]/2%256;
        output.atXY(points[i][0],points[i][1],2)=points[i][0]/2%256;




    }

    return output;

}
