#if !defined(_GRID_H_)
#define _GRID_H_
#include <iostream>
#include "Box.cpp"

template<class T> class Grid{

    Box<T> *grid;
    int SIZE;
    int xmin,xmax,ymin,ymax;
    int ndivisions;
    double hx, hy;
    double box_size;
    
    public:
        Grid();
        Grid(int x_i, int x_f,int y_i, int y_f,int ndiv,int size);
        void setGrid(int x_i, int x_f,int y_i, int y_f,int ndiv,int size);
        Box<T>& getBox(int, int);
        int getBox(Vector<double,2>&);
        //void getBox(int,int);
        void insertItem(T&);
        //void assignEdgeToGrid();
        T* searchContainingEdge(Vector<double,2> &);
        ~Grid();



};

#endif // _GRID_H_
