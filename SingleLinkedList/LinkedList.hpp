#if !defined(_LINKED_LIST_H)
#define _LINKED_LIST_H
#include<iostream>
//#include<Node.hpp>
template<class N> class Node;

// ************** Linked List class *****************************
template<class T> class LinkedList{

    protected:
        Node<T> *head;
        Node<T> *tail;
        int size;
    public:
        LinkedList();
        LinkedList(T&);
        ~LinkedList();
    //METHODS
    void append(T&);
    void display();
    T& getItem();
    void removeFirst();
    void removeLast();
    void removeThisItem(T&);
    int getSize();
    
};
template<class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template<class T>
LinkedList<T>::LinkedList(T& input){
    Node<T> *node = new Node<T>{input};
    head = node;
    tail = node;

}
// ********** LL METHODS *****************
template<class T>
void LinkedList<T>::append(T& data){
    Node<T> *node = new Node<T>(data);
    if(head==nullptr){
        head = node;
        tail  = node;
    }
    else{
        tail->nextNode = node;
        tail = node;
    }
    size++;
}
template<class T>
void LinkedList<T>::display(){
    Node<T> *temp = head;
    while(temp!=nullptr){
        print(temp->getNodeItem());
        temp = temp->nextNode;
    }
}
template<class T>
void LinkedList<T>::removeFirst(){
    printf("Removing First item\n");
    if(head!=nullptr){
        Node<T> *temp = head;
        head = head->nextNode;
        //temp->item.~T();
        delete temp;
        size--;
    }
}
template<class T>
void LinkedList<T>::removeLast(){
    printf("Removing Last item\n");
    if(head->nextNode==nullptr){
        removeFirst();
    }
    else if(head!=nullptr){
        Node<T> *current = head;
        Node<T> *prev;
        while(current->nextNode!=nullptr){
            prev = current;
            current = current->nextNode;
        }
        tail = prev;
        prev->nextNode = nullptr;
        //current->item.~T();
        delete current;
        size--;
    }
}
template<class T>
void LinkedList<T>::removeThisItem(T& target){
    if(head->getNodeItem()==target){
        removeFirst();
    }
    else if(tail->getNodeItem()==target){
        removeLast();
    }
    else if(head!=nullptr){
        Node<T> *prev;
        Node<T>* current = head;
        while(current->nextNode!=nullptr){
            prev = current;
            current = current->nextNode;
            if(current->getNodeItem()==target){
                break;
            }    
        }
        prev->nextNode = current->nextNode;
        delete current;
        size--;

    }
}
template<class T>
T& LinkedList<T>::getItem(){
    return this->getNodeItem();
}
template<class T>
int LinkedList<T>::getSize(){
    return size;
}
// ********** END LL METHODS *****************

template<class T>
LinkedList<T>::~LinkedList(){
    Node<T> *node;
    while(head!=nullptr){
        node = head->nextNode;
        delete head;
        head = node;
    }
    size = 0;
    std::cout<<"SLL destructor called\n";
}


//**************************NODE CLASS ******************************
template<class N> class Node{

    template<class T> friend class LinkedList;
    private:
        N item;
        Node<N> *nextNode;

    public:
        Node();
        Node(N&);
        ~Node();
    
        //Methods;
        N& getNodeItem();
        Node<N>* getNext();

};
template<class N>
Node<N>::Node(){
    nextNode = nullptr;
}
template<class N>
Node<N>::Node(N& data){
    this->item = data;
    nextNode = nullptr;
}
template<class N>
Node<N>::~Node(){}

// ***** NODE **** METHODS
template<class N>
N& Node<N>::getNodeItem(){
    return item;
}

template<class N>
Node<N>* Node<N>::getNext(){
    return nextNode;
}
#endif // _LINKED_LIST_H
