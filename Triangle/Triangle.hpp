#if !defined(_TRIANGLE_H_)
#define _TRIANGLE_H_
#include "../Edge/Edge.hpp"
template<class T> class Triangle {
    
    
    Vertex<T> *vertex[3]; //Just a 2D triangle
    Edge<T> *edge[3];
    int index;
    const int nVertex = 3;
    const int nEdges = 3;

    public:
        Triangle(); //DEFAULT CONSTRUCTOR
        Triangle(Vertex<T> &, Vertex<T>&b, Vertex<T>&c);
        Triangle(Triangle<T>&);
        ~Triangle();
        //METHODS
        void setIndex(int);
        void resetIndices();
        void indexing(int&);
        int getIndex()const;
        int sharingEdge(Triangle<T> &);
        bool contains(T&);
        bool contains(Edge<T>&); //Search for an edge
        bool isOrintedCCW();
        bool pointInCircumcircle(const T&);
        double computeArea();
        bool hasVertex(Vertex<T>&);
        Edge<T>& getEdge(int);
        Vertex<T>& getVertexNotinEdge(Edge<T>&);
        //OPERATOR
        Vertex<T>& operator()(int);
        Triangle<T> & operator=(Triangle<T>&);
        bool operator==(Triangle<T>&);
        bool operator!=(Triangle<T>&);
        bool isEqualTo(Triangle<T>&);
        bool isNotEqualTo(Triangle<T>&);
        const Vertex<T>& operator[](int i)const {
        return *(vertex[i]);
        }    





};


#endif // _TRIANGLE_H_
