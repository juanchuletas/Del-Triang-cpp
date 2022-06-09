#include <iostream>
#include "Triangle.cpp"


int main(){
 
    typedef Vector<double, 2> POINT2D;
    typedef Vertex<POINT2D> VERTEX;
    typedef Edge<POINT2D> EDGE;

    POINT2D c{1.0,1.0}, a{0.0,0.0},b{3.0,0.0},d{1.0,3.0};

    VERTEX v1{a},v2{b}, v3{c},v4{d};
    v1.setIndex(1);
    v2.setIndex(2);
    v3.setIndex(3);
    EDGE e1{v1,v2};
    EDGE e2{v2,v3};
    EDGE e3;
    e3 = e1;
    POINT2D p1{v1()};

    if(e1==e2){
        printf("MATCH\n");
    }
    else{
        printf("NO MATCH\n");
    }
    print(e1(0));


    Triangle<POINT2D> t1{v1,v2,v3},t3{v3,v2,v1};
    Triangle<POINT2D> t2{t1(1),v4,t1(2)};

    printf("Triangle t1 vertex 1 index = %d\n",t1(0).getIndex());
    printf("Triangle t1 edge 1 node 1 index = %d\n", t1.getEdge(0).getEdgeNode(0).getIndex());
    printf("Triangle t2 vertex 1 index = %d\n",t2(0).getIndex());



   /* //t1.sharingEdge(t2);
    if(t1.contains(d)==true){
        printf("SIIII\n");
    }
    //t1.contains(e1);
    if(t1.isOrintedCCW()){
        printf("CCW\n");
    }
    else{
        printf("NOT CCW\n");
    }
    

    std::cout<<"Number of sharing cells for node1 in triangle 1 = "<<t2(0).getSharingCells()<<std::endl;
    std::cout<<"Triangle Area: "<<t1.computeArea()<<std::endl; */
    //Triangle<POINT2D>{}
    //std::cout<<"Number of sharing cells for edge1 = "<<e1.getSharedEdge()<<std::endl;    

    //delete edge;
    return 0;
}