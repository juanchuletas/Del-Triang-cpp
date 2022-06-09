#include <iostream>
#include "Edge.hpp"
#include<vector>

int main (){
    typedef Vector<double,2> POINT2D;
    POINT2D a{0.0,0.0},b{3.0,3.0},c{1.0,1.0};
    Vertex<POINT2D> v1{a}, v2{b},  v3{c};
    v1.setIndex(1);
    v2.setIndex(2);
    v3.setIndex(3);
    Edge<POINT2D> edge[3];

    edge[0] = Edge<POINT2D>{v1,v2};
    edge[1] = Edge<POINT2D>{v2, v3};
    edge[2] = Edge<POINT2D>{v3, v1};

    printf("Vetex 1 index = %d\n", v1.getIndex());
    printf("Edge(1) node(1) index = %d\n", edge[0].getEdgeNode(0).getIndex());

    //edges = new Edge<POINT2D>[3];
    /* for(int i=0; i<3; i++){
        edges[i] = new Edge<POINT2D>(a,b);
    }

    Edge<POINT2D> e5{*edges[0]};
    int ub = e5.getUbication(a);
    printf("%d\n",ub);

    std::vector<Edge<POINT2D> *> edgesVec;
    edgesVec.push_back(&e5);
    edgesVec.push_back(edges[0]);
    edgesVec.push_back(edges[1]);

   

    std::cout<<"Length of edge vector: "<<edgesVec.size()<<std::endl;

    Edge<POINT2D> *edy;

    edy = new Edge<POINT2D>[3];

    edgesVec.push_back(&edy[3]);
     std::cout<<"Length of edge vector: "<<edgesVec.size()<<std::endl;


    for(const auto &iter: edgesVec){
        if(iter->getUbication(c)==4)
        {
            printf("GOT IT\n");
        }
    }




    //edy[0].getSharedEdge();
     //for(int i=0; i<3; i++){
       // edy[i] = Edge<POINT2D>{a,b};
    //}
    delete [] edy;
    for(int i = 0; i<3; i++){
        delete edges[i];
    }  */
    //delete [] edges;





    return 0;
}