#include<iostream>
#include<vector>
#include <algorithm>
#include "DelaunayTriangulation.cpp"
//#include "../Vector/vector.cpp"


int main(){
    typedef Vector<double,2> POINT2D;
    double array[]= {0.0,0.0};
    std::cout<<"Delaunay Triangulation Module.... \n";
    std::vector<POINT2D> pointSoup;

    //POINT2D parray[] = {{1.0,1.0},{2.0,0.0},{3.0,1.0},{2.0,2.0}};
    //POINT2D parray[] = {{1.0,1.0},{3.0,0.0},{4.0,1.0},{3.0,2.0}};
    //POINT2D parray[] = {{1.0,1.0},{3.0,0.0},{4.0,1.0},{3.0,2.0}};
    POINT2D parray[] = {{0.0,2.0},{1.0,0.0},{3.0,0.0},{4.0,2.0},{2.0,4.0},{2.0,2.0}};

    for(int i =0; i<6;i++){
        pointSoup.push_back(parray[i]);
    }
    for(auto iter: pointSoup){
        print(iter);
    }
    /* double maxX, minX;
    double maxY, minY;
    minX = pointSoup[0][0];
    minY = pointSoup[0][1];
    maxX = minX; maxY = minY;
    double maxAnyCoord = 0.0;
    for(auto iter: pointSoup){
        maxAnyCoord = std::max(std::max(iter[0],iter[1]),maxAnyCoord);
        if(iter[0]<minX){minX = iter[0];}
        if(iter[1]<minY){minY = iter[1];}
        if(iter[0]>maxX){maxX = iter[0];}
        if(iter[1]>maxY){maxY = iter[1];}
    }
    std::cout<<"MaxX = "<<maxX<<" MaxY = "<<maxY<<std::endl;
    std::cout<<"MinX = "<<minX<<" MinY = "<<minY<<std::endl;
    std::cout<<"MaxAnyCoord = "<<maxAnyCoord<<std::endl;
 */
    DelaunayTriangulation2D delTriang;
    delTriang.startTriangulation(pointSoup);

    /* delaunay.setEdgeGrid();
    delaunay.triangulate(points); */

    return 0;
}