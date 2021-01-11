#include<iostream>
#include "Box.hpp"



//***************** CONSTRUCTORS **********************************************
template<class T>
Box<T>::Box()
    :index{-1}{
    std::cout<<"Defatult BOX constructor\n";
}
template<class T>
Box<T>::Box(Box<T>& box){
    index = box.index;
    std::cout<<"COPY CONSTRUCTOR\n";

}
template<class T>
Box<T>::~Box(){
    std::cout<<"Box Destructor\n";
}
//***************** END CONSTRUCTORS ********************************************

// ***************** CLASS METHODS  *********************************************
template<class T>
void Box<T>::insertElement(T& edgeItem){


    std::cout<<"Inserting Element\n";
    edgeVector.push_back(&edgeItem);
}
template<class T>
T* Box<T>::searchElement(Vector<double,2> &target){
    int flag;
    std::cout<<"searchElementFunction: \n";
    std::cout<<"Length of the vector to search:\n";
    std::cout<<edgeVector.size()<<std::endl;
    for(auto &iter: edgeVector){
        std::cout<<"Ubication: "<<iter->getUbication(target)<<std::endl;
        if(iter->getUbication(target)==4)
        {
            printf("Match\n");
            return iter;
        }
    }
    return nullptr;
}
template<class T>
int Box<T>::getBoxIndex()const{
    return index;
}
template<class T>
void Box<T>::setBoxIndex(int input){
    
    this->index = input;
}
template<class T>
int Box<T>::getVectorSizeInBox()const {
     int mySize = static_cast<int>(edgeVector.size()); 

}
// ***************** END CLASS METHODS ********************************************