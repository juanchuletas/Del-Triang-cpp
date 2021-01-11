#include "vector.hpp"
#include<iostream>
#include <cmath>


//Constructors--------
template<class T, int N>
Vector<T,N>::Vector()
{
    for(int i=0; i<N; i++)
        component[i] = 0;
}//Constructor
template<class T, int N>
Vector<T,N>::Vector(const T& a, const T& b)
{
        component[0] = a;
        component[1] = b;
}
template<class T, int N>
Vector<T,N>::Vector(const T& a, const T& b,const T& c)
{
        component[0] = a;
        component[1] = b;
        component[2] = c;
}
template<class T,int N>
Vector<T,N>::Vector(const T& a, int n)
{
    //Set a unit Vector
    for(int i=0; i<N; i++)
        component[i] = 0;
    component[n] = a;
}
//Copy Constructor:
template<class T, int N>
Vector<T,N>::Vector(const Vector<T,N>& v)
{
    for(int i=0; i<N; i++)
    component[i] = v.component[i];
}
//Setters and Getters---------
template<class T,int N>
const T& Vector<T,N>::operator[](int i) const{
    return component[i];
}//Read ith component
template<class T, int N>
void Vector<T,N>::set(int i,const T& a){
    component[i] = a;
}
template<class T,int N>
Vector<T,N>::~Vector(){
}//Destructor

//Arithmetic Operators
//Adding a vector to the current vector
template<class T, int N>
const Vector<T,N>&
Vector<T,N>::operator+=(const Vector<T,N>& vec){
    
    for(int i=0; i<N; i++)
    {
        component[i]+=vec[i];
    }
    return *this;
}
//Assignment operator
template<class T, int N>
const Vector<T,N>&
Vector<T,N>::operator=(const Vector<T,N>&v)
{
    if(this!=&v)
    {
        for(int i=0; i<N; i ++)
            component[i] = v.component[i];
    }
    return *this;
}
// COMPARATION OPERATOR
template<class T, int N>
int Vector<T,N>::operator==( const Vector<T,N> &vec)
{
    if(N==2){
        return (component[0]==vec[0] && component[1]==vec[1]);
    }
    else if(N==3){
        return (component[0]==vec[0] && component[1]==vec[1] && component[2]==vec[3]);
    }


}
//Assignment operator vec = a; being "a" a constant
template<class T, int N>
const Vector<T,N>& 
Vector<T,N>::operator=(const T& a)
{
    for(int i=0; i<N; i++)
    {
        component[i] = a;
    }
    return *this;
}
//substracting a vector
template<class T, int N>
const Vector<T,N>& 
Vector<T,N>::operator-=(const Vector<T,N>&vec)
{
    for(int i=0; i<N; i++)
    {
        component[i] = component[i]-vec[i];
    }
    return *this;
}
//Multiplying a vector by a scalar
template<class T, int N>
const Vector<T,N>&
Vector<T,N>::operator*=(const T& a)
{
    for(int i=0; i<N; i++)
        component[i] *= a;
    return *this;
}
//Dividing the current vector by a scalar
template<class T, int N>
const Vector<T,N>&
Vector<T,N>::operator/=(const T& a)
{
    for(int i=0; i<N; i++)
        component[i] /= a;
    return *this;
}
//Functions Not belonging to the Vectror class
//Sum of vectors
template<class T, int N>
const Vector<T,N>
operator+(const Vector<T,N>&vec1, const Vector<T,N>&vec2)
{
    return Vector<T,N>(vec1) += vec2;
}
template<class T, int N>
const T 
Vector<T,N>::perdot(const Vector<T,N>& vec1){


    return this->operator[](0)*vec1[1] - this->operator[](1)*vec1[0];
}
//Dot product
template<class T, int N>
const T operator*(const Vector<T,N> &v1, const Vector<T,N> &v2)
{
    T sum = 0;
    for(int i=0; i<N; i++)
    {
        sum = sum + v1[i]*v2[i];
    }
    return sum;
}
template<class T, int N>
const Vector<T,N> operator/(const Vector<T,N>&vec1, const T&a)
{
    return Vector<T,N>(vec1) /=a;
}
//Multiplication by an escalar
template<class T, int N>
const Vector<T,N> operator*(const Vector<T,N>&vec1, const T&a)
{
    return Vector<T,N> (vec1) *= a;
}
//Negative of a vector
template<class T, int N>
const Vector<T,N> operator-(const Vector<T,N> &vec)
{
    return Vector<T,N>(vec) *=-1;
}
//Squared l2-norm
template<class T, int N>
T squaredNorm(const Vector<T,N>&vec)
{
    return vec*vec;
}
//l2-norm of a vector
template<class T, int N>
const  T l2norm(const Vector<T,N>&vec)
{
    return sqrt(vec*vec);
}
//Print your vectors
template<class T, int N>
void print(const Vector<T,N>&vec)
{
    if(N==2)
    {
        std::cout<<"("<<vec[0]<<", "<<vec[1]<<")"<<std::endl;
    }
    else if(N==3)
    {
        std::cout<<"("<<vec[0]<<", "<<vec[1]<<", "<<vec[2]<<")"<<std::endl;
    }
}