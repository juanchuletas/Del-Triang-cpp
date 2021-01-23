#if !defined(_EDGE_H_)
#define _EDGE_H_
#include<iostream>
#include <cmath>
template<class T> class Edge {

    T edgeNode[2]; //T must be a vector class Vector<double, 2> edgeNode[];
    const int nNodes = 2;
    int sharedEdge;
    enum ubication {LEFT,RIGHT,FRONT,BEHIND,MIDDLE,ORIGIN,DEST};
    
    public:
        Edge();
        Edge(const T&,const T&);
        Edge(Edge<T>&);
        ~Edge();
        //OPERATORS
        T& operator()(int);
        //Setters and Getters
        void setSharedEdge();
        int getSharedEdge();
        void setEdgeNodes(T&,T&);
        T& getEdgeNode(int);
        int operator==(Edge<T> &);
        const Edge<T>& operator=(const Edge<T>&);
        ubication getUbication(T&);

};
template<class T>
Edge<T>::Edge()
    :sharedEdge{0}{
    //std::cout<<"EDGE DEFAULT CONSTRUCTOR"<<std::endl;
    for(int i=0; i<nNodes; i++)
    {
        edgeNode[i] = 0; 
    }
}
template<class T>
Edge<T>::Edge(const T& a, const T& b)
        :sharedEdge{0}{
    //std::cout<<"EDGE COPY CONSTRUCTOR"<<std::endl;
    edgeNode[0] = a;
    edgeNode[1] = b;
}
template<class T>
Edge<T>::Edge(Edge<T>& edgein){
    //std::cout<<"EDGE COPY CONSTRUCTOR BY EDGE"<<std::endl;
    sharedEdge = edgein.sharedEdge;
    edgeNode[0] = edgein.edgeNode[0];
    edgeNode[1] = edgein.edgeNode[1];
}
template<class T>
Edge<T>::~Edge(){
    //std::cout<<"EDGE DESTRUCTOR"<<std::endl;
}

// ******************* OPERATORS ****************************************************************

template<class T>
T& Edge<T>::operator()(int i){


    return edgeNode[i];

}
template<class T>
int Edge<T>::operator==(Edge<T>& edge_in){
    return(this->edgeNode[0]==edge_in.edgeNode[0] && this->edgeNode[1]==edge_in.edgeNode[1] || this->edgeNode[0]==edge_in.edgeNode[1] && this->edgeNode[1]==edge_in.edgeNode[0]);
}
template<class T>
const Edge<T>&
Edge<T>::operator=(const Edge<T>& in){
    //printf("Asginment operator\n");
    if(this != &in){
    sharedEdge = in.sharedEdge;
    for(int i=0; i<nNodes; i++){
        edgeNode[i] = in.edgeNode[i];
    }
    }
    return *this;
}
// ******************* END OPERATORS ************************************************************


// ******************* SETTER/GETTERS ****************************************************************
template<class T>
void Edge<T>::setEdgeNodes(T& point_a,T& point_b){

    edgeNode[0] = point_a;
    edgeNode[1] = point_b; 

}
template <class T>
T& Edge<T>::getEdgeNode(int i){
    return edgeNode[i];
}
template<class T>
void Edge<T>::setSharedEdge(){

    sharedEdge = 1;
}
template<class T>
int Edge<T>::getSharedEdge(){

    return sharedEdge;
}
// ******************* END SETTER/GETTERS ************************************************************
// ******************* METHODS ***********************************************************************
template<class T>
enum Edge<T>::ubication Edge<T>::getUbication( T& point){
    std::cout<<"get ubication\n";
    double x1 = this->operator()(0)[0]; //Access to the x coordinate of the first node of the edge
    double y1 = this->operator()(0)[1];
    double x2 = this->operator()(1)[0];
    double y2 = this->operator()(1)[1];
    double a[]={x2-x1,y2-y1};
    double px = point[0];
    double py = point[1];
    double b[] = {px-x1,py-y1};
    double amod = sqrt(a[0]*a[0] + a[1]*a[1]);
    double bmod = sqrt(b[0]*b[0] + b[1]*b[1]);

    double sa = a[0]*b[1] - b[0]*a[1];
    if(sa>0.f) return ubication::LEFT;
    else if(sa<0.f) return ubication::RIGHT;
    else if((a[0]*b[0]<0.f) || (a[1]*b[1]<0.f)) return ubication::BEHIND;
    else if(amod<bmod) return ubication::FRONT;
    else if(this->operator()(0)==point) return ubication::ORIGIN;
    else if(point == this->operator()(1)) return ubication::DEST;

    return ubication::MIDDLE;
    //print(this->operator()(0));

}
// ******************* END METHODS ***********************************************************************

template<class T>
void print(Edge<T> & edge){
    print(edge.getEdgeNode(0));
    print(edge.getEdgeNode(1));

}
#endif // _EDGE_H_
