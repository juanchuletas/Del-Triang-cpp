#ifndef _VERTEX_H_
#define _VERTEX_H_
template<class T> class Vertex{
    T coords;
    int index;
    int nSharingCells;


    public:
        Vertex();
        Vertex(T&); 
        Vertex(Vertex<T> &);
        //Destructor
        ~Vertex();
        int getSharingCells() const;
        void increaseSharingCells();
        int decreaseSharingCells();
        int noSharingCell() const;
        //SETTER AND GETTERS
        int getIndex()const;
         void setIndex(int);
        //OPERATORS
        const T& operator()()const;
        bool operator==(const Vertex<T>&);
        const Vertex<T>& operator=(const Vertex<T>&);

};
#endif