#ifndef _VECTOR_H_
#define _VECTOR_H_
template<class T, int N> class Vector{

    private:
        T component[N];
    public:
    //Constructors--------
        Vector();
        Vector(const T&,const T&);
        Vector(const T&,const T&,const T&);
        Vector(const T&, int);
        //Copy Constructor:
        Vector(const Vector&);
        //An asignment operator:
        const Vector& operator=(const Vector&);
        const Vector& operator=(const T&);
        //Adding two Vectors
        const Vector& operator+=(const Vector&);
        //Substracting Two vectors
        const Vector& operator-=(const Vector&);
        //Multiplying the current vector by a scalar
        const Vector& operator*=(const T&);
        //Dividing the current vector by a scalar
        const Vector& operator/=(const T&);
        const T perdot(const Vector<T,N>&);
        int operator==(const Vector<T,N>&);
        //const Vector& operator+(const Vector&);
        //Dot product;
    //Setters and getters-----
        const T& operator[](int i) const;
        void set(int i, const T& a);
    //Destructor
        ~Vector();
    

}; 
//#include "vector.cpp"
#endif