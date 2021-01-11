#include<iostream>
//#include "../LinkedList/LinkedList.hpp"
#include"Mesh.hpp"

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


/* template<class T>
    T *Mesh<T>::findContainingCell(Vector<double, 2> &target){
    bool flag;
    std::cout<<"Search method\n";
    for(Mesh<T>* iter = this; iter; iter = (Mesh<T>*)iter->tail)
        {
            //target_triangle = iter->getItem();
            flag = iter->getItem().contains(target);
            if(flag==true)
            {
                std::cout<<"Got it\n";
                return &iter->getItem();
            }
         //print(iter->operator()());
        }
    return nullptr;
    //return this->operator()();
} */

template<class T>
T *Mesh<T>::findTriangleNeighborTo(T& triangle,Edge<Vector<double,2>> &edge){
    for(Node<T> *iter = this->head; iter; iter = iter->getNext()){
        if(iter->getNodeItem().contains(edge)){
            printf("GOT THE TRIANGLE\n");
            return &iter->getNodeItem();
        }
    }
    return nullptr;
}
/* template<class T>
T* Mesh<T>::findTriangleNeighborTo(T& triangle, Edge<Vector<double,2>> &edge){

    for(Mesh<T>* iter = this; iter; iter = (Mesh<T>*)iter->nextNode){
        if(iter->getItem().contains(edge) && !(iter->getItem()==triangle)){
            printf("GOT THE TRIANGLE\n");
            return &iter->getItem();
        }
    }
    return nullptr;
}
template<class T>
T* Mesh<T>::findTriangleSharing( Edge<Vector<double,2>> & edge){
    for(Mesh<T>* iter = this; iter; iter = (Mesh<T>*)iter->nextNode){
        if(iter->getItem().contains(edge)){
            return &iter->getItem();
        }
    }
    return nullptr;
} */
template<class T>
T* Mesh<T>::findTriangleSharing(Edge<Vector<double,2>> &edge){
    for(Node<T> *iter = this->head; iter; iter = iter->getNext()){
        if(iter->getNodeItem().contains(edge)){
            return &iter->getNodeItem();
        }
    }
    return nullptr;
}
template<class T>
void Mesh<T>::removeTrianglesWith(Vertex<Vector<double,2>> &vertex){
    printf("REMOVE TRIANGLES WITH\n");
    for(Node<T> *iter =this->head; iter; iter = iter->getNext()){
        if(iter->getNodeItem().hasVertex(vertex)){
            printf("SHOOOTING\n");
            this->removeThisItem(iter->getNodeItem());
        }
    }

}