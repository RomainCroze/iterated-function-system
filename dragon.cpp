#include "dragon.h"




int main(int argc,char *argv[])
{

    /* Initialization */

    cout << "Number of transformations applied"<<endl;
    int iterations;
    cin>>iterations;

    cout<<"Number of points to start with"<<endl;
    int nb_points;
    cin >> nb_points;

    CImg<unsigned char> output(sizex,sizey,1,3);

    Transformations transformations = new ptr_transformation [2];
    transformations[0]= Transformation1;
    transformations[1]= Transformation2;


    IFS* ifs = new IFS(1,transformations, 2);

    Point* points = new Point [nb_points];

    for (int i = 0; i<nb_points; i++)
    {
        points[i][0]=rand() % sizex;
        points[i][1]=rand() % sizey;
    }

    points = ifs->getIFS(points, nb_points);

    output= imageOfPoints(points,sizex,sizey,nb_points);

    /* Display initialization image */

    CImgDisplay init_disp(output,"Initialization");
    while (!init_disp.is_closed())
    {
        init_disp.wait();
    }

    transformations[0]= Transformation3;
    transformations[1]= Transformation4;

    IFS* ifs2 = new IFS(iterations,transformations,2);

    points = ifs2->getIFS(points, nb_points);


    output = imageOfPoints(points,sizex,sizey,nb_points);

    CImgDisplay fractal_disp(output,"Fractal");
    while (!fractal_disp.is_closed())
    {
        fractal_disp.wait();
    }

    return 0;

}
