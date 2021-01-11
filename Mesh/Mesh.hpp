#ifndef _MESH_H_
#define _MESH_H_
#include "../SingleLinkedList/LinkedList.hpp"
//#include "../Edge/Edge.hpp"
template<class T> class Mesh : public LinkedList<T>{

    //typedef Vector<double,2> point2d;
    public:

        Mesh(){
            std::cout<<"Mesh default constructor\n";
        }
        /* Mesh(T& object){
            std::cout<<"Mesh constructor\n";
            this->item = object;
            //Why do we need to use the "this" object with a
            //template class?
        } */
        ~Mesh(){
            std::cout<<"Mesh destructor\n";
        }
    //methods

    int indexing();
    void printMesh();
    T *findContainingCell(Vector<double,2>&);
    T *findTriangleNeighborTo(T&, Edge<Vector<double,2>> &);
    T *findTriangleSharing( Edge<Vector<double,2>> &);
    void removeTrianglesWith(Vertex<Vector<double,2>> &);



};

#endif