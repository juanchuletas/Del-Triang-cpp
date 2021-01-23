#include<iostream>
#include <cmath>
#include "../Vector/vector.cpp"
#include "Vertex.hpp"

//*********************  CONSTRUCTORS*****************************************************
template<class T>
Vertex<T>::Vertex(){
    //std::cout<<"Vertex Default Constructor\n";
    coords = 0;
    index = -1;
    nSharingCells = 0;
}
template<class T>
Vertex<T>::Vertex(T& input_coords)
    :coords{input_coords},index{-1},nSharingCells{0}{
        //Just setting the coordinates of the new vertex
}
template<class T>
Vertex<T>::Vertex(Vertex<T> & vertex_input)
    :coords{vertex_input.coords},index{vertex_input.index},nSharingCells{vertex_input.nSharingCells}{

}
//*********************  END CONSTRUCTORS*****************************************************

// ******************** MEMBER FUNCTIONS *****************************************************

template<class T>
int Vertex<T>::getSharingCells () const{
    return nSharingCells;
}
template<class T>
void Vertex<T>::increaseSharingCells(){
    nSharingCells++;
}
template<class T>
int Vertex<T>::decreaseSharingCells(){
    return nSharingCells ? !(--nSharingCells) : 1;
}
template<class T>
int Vertex<T>::noSharingCell()const{
    return !nSharingCells;
    //This function decreases the "sharing Cells" field by one.
    // It also returns a 0 so long as the node still serves as a
    // vertex in at least one cell, and 1 once it becomes an isolated node
    //shared by no cel.
}
template<class T>
int Vertex<T>::getIndex() const{
    return index;
}
template<class T>
void Vertex<T>::setIndex(int _index)
{
    index = _index;
}
// ******************** END MEMBER FUNCTIONS *************************************************


// *********** NON MEMBER FUNCTIONS *********************************************************
template<class T>
void print(const Vertex<T> & n1)
{
    std::cout<<"Node index: "<<n1.getIndex()<<"  Sharing Cells: "<<n1.getSharingCells()<<std::endl;
    std::cout<<"Location: ";
    print(n1());
}
// *********** END NON MEMBER FUNCTIONS *********************************************************
// ******************* OPERATORS ****************************************************************
template<class T>
const T& Vertex<T>::operator()() const{
    return coords;
}
template<class T>
const Vertex<T>& Vertex<T>::operator=(const Vertex<T>& _node){
    if(this!=&_node){
        coords = _node.coords;
        index = _node.index;
        nSharingCells = _node.nSharingCells;
        
    }
    return *this;
}
template<class T>
bool Vertex<T>::operator==(const Vertex<T>& inputVertex){
    return (coords==inputVertex.coords);
}
//************** END OPERATORS *******************************************************************

//**************************** DESTRUCTOR*****************************************************
template<class T>
Vertex<T>::~Vertex(){
    //std::cout<<"Vertex Destructor Called\n";
}