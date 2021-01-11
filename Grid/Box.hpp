#if !defined(_BOX_H_)
#define _BOX_H_
#include<iostream>
#include <vector>

template<class T> class Box{

    std::vector<T *> edgeVector;
    int index;
    public:
        Box(); //Default constructor
        Box(Box<T>&);
        ~Box(); //Destructor
        //Methods
        void insertElement(T&);
        int getBoxIndex() const;
        void setBoxIndex(int);
        int getVectorSizeInBox()const;
        //auto getInsideVectorSize();
        T* searchElement(Vector<double,2>&);

};


#endif // _BOX_H_
