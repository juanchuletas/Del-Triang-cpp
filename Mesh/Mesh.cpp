#include<iostream>
//#include "../LinkedList/LinkedList.hpp"
#include"Mesh.hpp"

template<class T>
int Mesh<T>::indexing(){
    Node<T>*iter = this->head;
    while(iter!=nullptr){
        iter->getNodeItem().resetIndices();
        iter = iter->getNext();
    }
    iter=nullptr;
    iter = this->head;
    int count = 0;
     while(iter!=nullptr){
        iter->getNodeItem().indexing(count);
        iter = iter->getNext();
    }
    return count;
}
/* template<class T>
int Mesh<T>::indexing(){
    for(Mesh<T> *iter = this; 
        iter; iter=(Mesh<T>*)iter->nextNode){
            iter->item.resetIndices();
        }
    int count = 0;
    for(Mesh<T>* iter = this; iter; iter = (Mesh<T>*)iter->nextNode)
    {
        iter->item.indexing(count );
    }
    return count;
} */   
template<class T>
void Mesh<T>::printMesh(){
    //printL(*this);
}

template<class T>
T* Mesh<T>::findContainingCell(Vector<double, 2> &target){
    Node<T> *iter = this->head;
    bool flag;
    while(iter!=nullptr){
        flag = iter->getNodeItem().contains(target);
        if(flag==true){
            printf("GOT IT BITCH\n");
            return &iter->getNodeItem();
        }
        iter = iter->getNext();
    }
    return nullptr;
}

template<class T>
T *Mesh<T>::findTriangleNeighborTo(T& triangle,Edge<Vector<double,2>> &edge){
    Node<T> *iter = this->head;
    while(iter!=nullptr){
        if(iter->getNodeItem().contains(edge) && iter->getNodeItem().isNotEqualTo(triangle)){
            printf("Este triangulo de la lista tiene el eje objetivo y es el mismo triangulo\n");
            return &iter->getNodeItem();   
        }
        iter = iter->getNext();
    }
    return nullptr;
}
template<class T>
T* Mesh<T>::findTriangleSharing(Edge<Vector<double,2>> &edge){
    Node<T> *iter = this->head;
    while(iter!=nullptr){
        if(iter->getNodeItem().contains(edge)){
            return &iter->getNodeItem();
        }
        iter =  iter->getNext();
    }
    return nullptr;
}
template<class T>
void Mesh<T>::removeTrianglesWith(Vertex<Vector<double,2>> &vertex){
    printf("REMOVE TRIANGLES WITH\n");
    Node<T>*iter = this->head;
    while(iter!=nullptr){
        if(iter->getNodeItem().hasVertex(vertex)){
            this->removeThisItem(iter->getNodeItem());
        }
        iter = iter->getNext();
    }
}