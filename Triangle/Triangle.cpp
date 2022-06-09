#include "Triangle.hpp"

// ******************* CONSTRUCTORS ****************************************************************

template<class T>
Triangle<T>::Triangle(){
    //std::cout<<"TRIANGLE DEFAULT CONSTRUCTOR CALLED\n";
    index = -1;
    for(int i=0; i<nVertex; i++){
        vertex[i] = new Vertex<T>();
        edge[i] = new Edge<T>();
    } 
}
template<class T>
Triangle<T>::Triangle(Vertex<T>&a,Vertex<T>&b,Vertex<T>&c)
    :index{-1}
{ 
     //std::cout<<"Triangle Copy Constructor Called"<<std::endl;
    /*if(a.noSharingCell())
    {
        std::cout<<"Sharing value for Vertex 1:  "<<a.noSharingCell()<<std::endl;
        Vertex<T> *p[2];
        p[0] = new Vertex<T> {a};
        vertex[0] = p[0];
        std::cout<<"p adress at Cell constructor: "<<p[0]<<std::endl;
        std::cout<<"vertex adress at Cell constructor: "<<vertex[0]<<std::endl;

    }
    else{
        vertex[0] = &a;
    }*/
    vertex[0] = a.noSharingCell() ? new Vertex<T>(a) : &a;
    vertex[1] = b.noSharingCell() ? new Vertex<T>(b) : &b;
    vertex[2] = c.noSharingCell() ? new Vertex<T>(c) : &c;
    //CREATING EDGES
    //T a1 = a();
    //print(a1);
    edge[0] = new Edge<T>{a,b};
    edge[1] = new Edge<T>{b,c};
    edge[2] = new Edge<T>{c,a};

    //std::cout<<"Target Vertex adress at constructor: "<<(vertex+1)<<std::endl;
    for(int i = 0; i<nVertex; i++)
    {
        //std::cout<<"Increasing the number of sharing Cells\n";
        vertex[i]->increaseSharingCells();
    }
}
template<class T>
Triangle<T>::Triangle(Triangle<T>&t_in){
    std::cout<<"DEEP COPY CONSTRUCTOR\n";
    index = t_in.index;
    vertex[0] = new Vertex<T>(t_in(0));
    vertex[1] = new Vertex<T>(t_in(1));
    vertex[2] = new Vertex<T>(t_in(2));

    edge[0] = new Edge<T>(t_in.getEdge(0));
    edge[1] = new Edge<T>(t_in.getEdge(1));
    edge[2] = new Edge<T>(t_in.getEdge(2));


    /* for(int i=0; i<nVertex; i++){
        vertex[i] = t_in.vertex[i];
        edge[i] = t_in.edge[i];
    } */
}
template<class T>
Triangle<T>::~Triangle(){
   // std::cout<<"Triangle Destructor called\n";
    for(int i=0; i<nVertex; i++)
    {
        if(vertex[i]->decreaseSharingCells())
        {
            delete vertex[i];
        }
    }
    for(int i = 0; i<nEdges; i++){
        delete edge[i];
    }    
}
// ******************* END CONSTRUCTORS ********************************************************

// ******************* METHODS ****************************************************************
template<class T>
Edge<T>& Triangle<T>::getEdge(int i){
    return *(edge[i]);
}
template<class T>
int Triangle<T>::sharingEdge(Triangle<T> &triangle){
    /* Returns true if both triangles share an edge */
    for(int i=0; i<nEdges; i++)
    {
        for(int j=0; j<nEdges; j++)
        {
            //print(this->edge[i]);
            //print(triangle.edge[j]);
            if(this->getEdge(i)==triangle.getEdge(j))
            {
                
                std::cout<<"EDGE MATCH\n";
                return 0;
            }
        }
    }

}
/* template<class T>
bool Triangle<T>::contains(T& point){
    //Returns true if the a point is inside the triangle
    T point_a = this->operator()(0)();
    T point_b = this->operator()(1)();
    T point_c = this->operator()(2)();
    T point_ba = point_b-=point_a;
    T point_ca = point_c-=point_a;
    T point_cb = point_c-=point_b;
    T point_p  = point;
    T point_pa = point_p-=point_a;
    T point_pb = point_p-=point_b;
    double c1,c2,c3;
    c1 = point_ba.perdot(point_pa);
    c2 = point_pa.perdot(point_ca);
    c3 = point_cb.perdot(point_pb);


    if(c1*c2*c3>=0)
    {
        std::cout<<"Node inside the Cell\n";

        return true;
    }
    else{
        std::cout<<"Node not inside the Cell or in the edge\n";
        return false;
    }
} */
template<class T>
bool Triangle<T>::contains(T& point){
    T point_a = this->operator()(0)();
    T point_b = this->operator()(1)();
    T point_c = this->operator()(2)();
    T point_p = point;
    T v0 = point_c-=point_a;
    T v1 = point_b-=point_a;
    T v2 = point_p-=point_a;
    double dot00 = v0*v0;
    double dot01 = v0*v1;
    double dot02 = v0*v2;
    double dot11 = v1*v1;
    double dot12 = v1*v2;

    double invDenom = 1.0/(dot00*dot11 - dot01*dot01);
    double u = (dot11*dot02 - dot01*dot12)*invDenom;
    double v = (dot00*dot12 - dot01*dot02)*invDenom;

    return( (u>=0)  && (v>=0) && (u+v<1));



}
template<class T>
bool Triangle<T>::contains(Edge<T>& edge){
    //Returns True if the triangle contains the edge
    for(int i=0; i<nEdges; i++)
    {
        if(this->getEdge(i)==edge)
        {
            std::cout<<"CONTAINS EDGE\n";
            return true;
        }
    }
    std::cout<<"DOES NOT COINTAIN EDGE\n";
    return false;
}
template<class T>
bool Triangle<T>::hasVertex(Vertex<T> &target){
    for(int i=0; i<nVertex; i++){
        if(this->operator()(i)==target)
            return true;
    }
    return false;
}
template<class T>
bool Triangle<T>::isOrintedCCW(){
    // This function tells you if a triangle es CCW or not
    double a11 = this->operator()(0)()[0] - this->operator()(2)()[0];
    double a21 = this->operator()(1)()[0] - this->operator()(2)()[0];

    double a12 = this->operator()(0)()[1] - this->operator()(2)()[1];
    double a22 = this->operator()(1)()[1] - this->operator()(2)()[1]; 

    double det  = (a11*a22) - (a12*a21);

    return (det>0.f);
}
template<class T>
double Triangle<T>::computeArea(){
    double x1y2 = this->operator()(0)()[0]*(this->operator()(1)()[1]);
    double x2y3 = this->operator()(1)()[0]*(this->operator()(2)()[1]);
    double x3y1 = this->operator()(2)()[0]*(this->operator()(0)()[1]);
    double x1y3 = this->operator()(0)()[0]*(this->operator()(2)()[1]);
    double x2y1 = this->operator()(1)()[0]*(this->operator()(0)()[1]);
    double x3y2 = this->operator()(2)()[0]*(this->operator()(1)()[1]);

    double diff = (x1y2+x2y3+x3y1-x1y3-x2y1-x3y2);
    
    return 0.5*diff;
}
template<class T>
bool Triangle<T>::pointInCircumcircle(const T& point){
    double mat11 = this->operator()(0)()[0] - point[0];
    double mat21 = this->operator()(1)()[0] - point[0];
    double mat31 = this->operator()(2)()[0] - point[0];

    double mat12 = this->operator()(0)()[1] - point[1];
    double mat22 = this->operator()(1)()[1] - point[1];
    double mat32 = this->operator()(2)()[1] - point[1];

    double mat13 = mat11*mat11 + mat12*mat12;
    double mat23 = mat21*mat21 + mat22*mat22;
    double mat33 = mat31*mat31 + mat32*mat32;

    double det = mat11*mat22*mat33 + mat12*mat23*mat31 + mat13*mat21*mat32 - mat13*mat22*mat31 - mat12*mat21*mat33 - mat11*mat23*mat32;

    if(this->isOrintedCCW()){
        return det>0.f;
    }
    return det<0.f;
}
template<class T>
Vertex<T>& Triangle<T>::getVertexNotinEdge(Edge<T>& edgeTarget){

    if(this->getEdge(0)==edgeTarget) {
        return this->operator()(2);
    }
    else if(this->getEdge(1)==edgeTarget){
        return this->operator()(0);
    }
    else if(this->getEdge(2)==edgeTarget){
        return this->operator()(1);
    }

}
template<class T>
void Triangle<T>::setIndex(int i){
    index = i;
}
template<class T>
void Triangle<T>::resetIndices(){
    for(int i=0; i<nVertex; i++)
        vertex[i]->setIndex(-1);
}
//Indexing 
template<class T>
void Triangle<T>::indexing(int& count)
{
    for(int i=0; i<nVertex; i++)
    {
        if(vertex[i]->getIndex()<0)
        {
            vertex[i]->setIndex(count++);
        }
    }
}
//Get index
template<class T>
int Triangle<T>::getIndex() const{
    return index;
}
//******************** END METHODS **************************************************************
// ******************* OPERATORS ****************************************************************
template<class T>
Vertex<T>& Triangle<T>::operator()(int i){

    return *(vertex[i]);
}
template<class T>
Triangle<T> &
Triangle<T>::operator=(Triangle <T>& input_cell)
{
    if(this!=&input_cell){

        index = input_cell.index;
        for(int i=0; i<nEdges; i++){
            delete edge[i]; 
            delete vertex[i];
        }
        for(int i=0; i<nEdges; i++){
            vertex[i] = new Vertex<T>(input_cell(i));
            edge[i] = new Edge<T>{input_cell.getEdge(i)};
        }

    }
    return *this;
}
template<class T>
bool Triangle<T>::operator==(Triangle<T>& triangle){
    if(this->getEdge(0)==triangle.getEdge(0) && this->getEdge(1)==triangle.getEdge(1) && this->getEdge(2)==triangle.getEdge(2)){
        return true;
    }

    return false;
}
template<class T>
bool Triangle<T>::operator!=(Triangle<T>& triangle){
    return !(this->operator()(0)==triangle(0) && this->operator()(1)==triangle(1) && this->operator()(2)==triangle(2));

}
template<class T>
bool Triangle<T>::isEqualTo(Triangle<T>& triangle){
    if(this->getEdge(0)==triangle.getEdge(0) && this->getEdge(1)==triangle.getEdge(1) && this->getEdge(2)==triangle.getEdge(2)){
        return true;
    }
    else{
        return false;
    }
}
template<class T>
bool Triangle<T>::isNotEqualTo(Triangle<T>& triangle){
    if(this->getEdge(0)==triangle.getEdge(0) && this->getEdge(1)==triangle.getEdge(1) && this->getEdge(2)==triangle.getEdge(2)){
        return false;
    }
    else{
        return true;
    }
}
// ******************* END OPERATORS *************************************************************
template<class T>
void print(const Triangle<T>& c1)
{
    for(int i=0; i<3; i++)
        print(c1[i]);
}