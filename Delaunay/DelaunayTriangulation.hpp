#if !defined(_DELAUNAY_H_)
#define _DELAUNAY_H_
#include<iostream>
#include "../Triangle/Triangle.cpp"
#include "../Mesh/Mesh.cpp"
#include "../Grid/Grid.cpp"


typedef Vector<double, 2> POINT2D;
typedef Vertex<POINT2D> VERTEX; 
typedef Triangle<POINT2D> TRIANGLE;
typedef Edge<POINT2D> EDGE;

class DelaunayTriangulation2D {

    private:
        Mesh<TRIANGLE> triangleList; // List of triangles to store the triangulation
        Grid<EDGE> edgeGrid; // Grid of edges: location of the edges
    
    public:
        DelaunayTriangulation2D(){
            std::cout<<"********* Default delaunay constructor ***** \n";
        }
        void buildEdgeGrid(int x_i, int x_f,int y_i, int y_f,int ndiv,int size);
        void startTriangulation(std::vector<POINT2D>&);
        void legalizeEdge(TRIANGLE &, EDGE &, VERTEX &);



};


#endif // _DELAUNAY_H_
