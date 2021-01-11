#include<iostream>
#include "Grid.hpp"


//***************** CONSTRUCTORS & DESTRUCTOR **********************************************
template<class T>
Grid<T>::Grid()
    :xmin{0},xmax{0},ymin{0},ymax{0},ndivisions{0},SIZE{0},hx{0},hy{0}{
        grid = nullptr;

}
template<class T>
Grid<T>::Grid(int x_i, int x_f,int y_i, int y_f,int ndiv,int size)
    :xmin{x_i},xmax{x_f},ymin{y_i},ymax{y_f},ndivisions{ndiv},SIZE{size}{    
        hx = (xmax-xmin)/(double)ndivisions;
        hy = (ymax-ymin)/(double)ndivisions;
        box_size = hx;

        grid = new Box<T>[SIZE];
        /* for(int i=0; i<SIZE; i++)
        {
            grid[i] = Box<T>();
        } */  

 }
template<class T>
Grid<T>::~Grid(){
delete [] grid;
}
//*****************END  CONSTRUCTORS & DESTRUCTOR **********************************************
// ***************** CLASS METHODS  ************************************************************
template<class T>
void Grid<T>::setGrid(int x_i, int x_f,int y_i, int y_f,int ndiv,int size){
    xmin = x_i;
    xmax = x_f;
    ymin = y_i;
    ymax = y_f;
    ndivisions = ndiv;
    SIZE = size;
    hx = (xmax-xmin)/(double)ndivisions;
    hy = (ymax-ymin)/(double)ndivisions;
    box_size = hx;

    grid = new Box<T>[SIZE];
}
template<class T>
int Grid<T>::getBox(Vector<double,2> &target){

    double x = target[0]; //Target is the point to locate in the Grid
    double y = target[1];
    double hx = (xmax-xmin)/(double)ndivisions;
    double hy = (ymax-ymin)/(double)ndivisions;

    int i = ((int)(x/hx))%ndivisions;
    int j = ((int)(y/hy))%ndivisions;
    int index = i + j*ndivisions;
    std::cout<<"YOUR POINT IS INSIDE BOX[ "<<index<<" ]\n";
    
    return index;

}
template<class T>
Box<T>& Grid<T>::getBox(int i,int j){
    
    int index = i + j*ndivisions;
    //std::cout<<"YOUR POINT IS INSIDE BOX["<<index<<"]\n";
    //Box<T> box = grid[index];

    return grid[index];

}
template<class T>
void Grid<T>::insertItem(T& edge){
    double x1 = edge(0)[0];
    //double x1 = edge->operator()(0)()[0]; //Access to de x coordinate of the first node of the edge; for pointers
    double y1 = edge(0)[1];
    //double y1 = edge->operator()(0)()[1];
    double x2 = edge(1)[0];
    //double x2 = edge->operator()(1)()[0];
    double y2 = edge(1)[1];
    //double y2 = edge->operator()(1)()[1];

    //****  Define the vector u = edge.b - edge.b;*****
    double u[2];
    u[0] = x2-x1; u[1] = y2-y1;
    double xstep = (u[0]>=0) ? 1 : -1;
    double ystep = (u[1]>=0) ? 1 : -1;
    //Passing to integer values
    int xint1 = ((int)(x1/hx))%ndivisions;
    int yint1 = ((int)(y1/hy))%ndivisions;
    int xint2 = ((int)(x2/hx))%ndivisions;
    int yint2 = ((int)(y2/hy))%ndivisions;

    //Coordinates of the grid as integer values;
    int currentBox_x = xint1; int currentBox_y = yint1;


    double nextBoxBound_x = (currentBox_x + xstep)*box_size;
    double nextBoxBound_y = (currentBox_y + ystep)*box_size;


    //The value of t
    double tMAxVal_x = (u[0]!=0) ? (nextBoxBound_x-x1)/u[0] : __DBL_MAX__;
    double tMAxVal_y = (u[1]!=0) ? (nextBoxBound_y-y1)/u[1] : __DBL_MAX__;


    double tDeltaX = (u[0]!=0) ? box_size/(u[0]*xstep) : __DBL_MAX__;
    double tDeltay = (u[1]!=0) ? box_size/(u[1]*ystep) : __DBL_MAX__;
    
    //Start and the end of the grid in 1D form
    int start = (xint1 + yint1*ndivisions);
    int end = (xint2 + yint2*ndivisions);
    int xfoo = xint1;
    int yfoo = yint1;
    printf("******\n");
    //Box<T> box  = getBox(xfoo,yfoo);
    grid[start].insertElement(edge);
    grid[start].setBoxIndex(start);
    printf("Box index =  %d\n",grid[start].getBoxIndex());
    printf("Statring at %d\n",start);
    printf("Vector size inside the box = %d\n",grid[start].getVectorSizeInBox());
    std::cout<<"BOX("<<xfoo<<", "<<yfoo<<" )"<<std::endl;
    printf("******\n");
    //getBox(xfoo,yfoo);
    while(start!=end){

        if(tMAxVal_x<tMAxVal_y){
            tMAxVal_x = tMAxVal_x + tDeltaX;
            xfoo+=xstep;
            start = (xfoo + yfoo*ndivisions);
            grid[start].insertElement(edge);
            grid[start].setBoxIndex(start);
            printf("Box index =  %d\n",grid[start].getBoxIndex());
            printf("Statring at %d\n",start);
            printf("Vector size inside the box = %d\n",grid[start].getVectorSizeInBox());
            //printf("%d\n",start);
        }
        else if(tMAxVal_x==tMAxVal_y){
            tMAxVal_x = tMAxVal_x + tDeltaX;
            xfoo+=xstep;
            tMAxVal_y = tMAxVal_y + tDeltay;
            yfoo+=ystep;
            start = (xfoo + yfoo*ndivisions);
            grid[start].insertElement(edge);
            grid[start].setBoxIndex(start);
            printf("Box index =  %d\n",grid[start].getBoxIndex());
            printf("Statring at %d\n",start);
            printf("Vector size inside the box = %d\n",grid[start].getVectorSizeInBox());
            //printf("%d\n",start);


        }
        else{
            tMAxVal_y = tMAxVal_y + tDeltay;
            yfoo+=ystep;
            //box = getBox(xfoo,yfoo);
            //box.insertElement(edge);
            //getBox(xfoo,yfoo);
            start = (xfoo + yfoo*ndivisions);
            printf("%d\n",start);
            
        }
        std::cout<<"BOX("<<xfoo<<", "<<yfoo<<" )"<<std::endl;
        printf("******\n");
    }
}
template<class T>
T* Grid<T>::searchContainingEdge(Vector<double,2> & target){
    printf("Searching point module\n");
    int indx = getBox(target);

    /* printf("Box index =  %d\n",box.getBoxIndex());
    printf("Vector size inside the box = %d\n",box.getVectorSizeInBox()); */
    //Edge<Vector<double,2>> edge = box.searchElement(target);
     return grid[indx].searchElement(target);
}

// ***************** END CLASS METHODS  *********************************************
