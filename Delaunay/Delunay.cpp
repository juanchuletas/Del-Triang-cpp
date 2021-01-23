#include <iostream>
#include "../Triangle/Triangle.cpp"
#include "../Mesh/Mesh.cpp"
#include "../Grid/Grid.cpp"

/* Box<Edge<Vector<double,2>>>& getBox(int i){  
Box<Edge<Vector<double,2>>> *box; 
box = new Box<Edge<Vector<double,2>>>[2];
//box[i].setBoxIndex(i);
return box[i];

} */


int main (){

    typedef Vector<double, 2> POINT2D;
    typedef Vertex<POINT2D> VERTEX; 
    typedef Triangle<POINT2D> TRIANGLE;

    double maxAnyCoord = 3.0;
    maxAnyCoord*=16.0;
    POINT2D big_a{0.0,maxAnyCoord};
    POINT2D big_b{maxAnyCoord,0.0};
    POINT2D big_c{-maxAnyCoord,-maxAnyCoord};
    VERTEX p0{big_a},p1{big_b},p2{big_c};


    TRIANGLE bigT{p0,p1,p2};
    POINT2D p{1.0,1.0},q0{0.0,0.0},q1{2.0,0.0},q2{1.0,1.0};
    VERTEX v0{q0},v1{q1},v2{q2};
    TRIANGLE target{v0,v1,v2};
    Mesh<TRIANGLE> triangleList;

    triangleList.append(bigT);

    TRIANGLE *triangle = new TRIANGLE;
    triangle = triangleList.findContainingCell(p);
    VERTEX newVertex{p};
    TRIANGLE t1{triangle->operator()(0),triangle->operator()(1),newVertex};
    TRIANGLE t2{triangle->operator()(1),triangle->operator()(2),newVertex};
    TRIANGLE t3{triangle->operator()(2),triangle->operator()(0),newVertex};
    
    triangleList.removeThisItem(bigT);


    triangleList.append(t1);
    triangleList.append(t2);
    triangleList.append(t3);

    TRIANGLE *veci = new TRIANGLE;
    veci = nullptr;
    veci = triangleList.findTriangleNeighborTo(t1,t1.getEdge(0));
    print(t1.getEdge(0));
    //print(veci->getEdge(0));
    if(veci!=nullptr){
      printf("legalizing  ******************\n");
    }
    else{
      printf("FALSE **************************\n");
    }











    /* POINT2D p0{0.0,0.0},p1{2.0,0.0},p2{1.0,1.0}, p3{3.0,1.0}, p4{4.0,0.0},p5{2.0,2.0},pEx{2.0,1.5},pC{0.5,0.5};
    VERTEX v0{p0},v1{p1},v2{p2},v3{p3},v4{p4},v5{v5};
    TRIANGLE t1{v0,v1,v2};
    TRIANGLE t2{t1(2),t1(1),v3};
    TRIANGLE t3{t2(1),v4,t2(2)};
    TRIANGLE t4{t2(0),t2(2),v5}; */
    /* VERTEX v6;
    Edge<POINT2D> edge{p0,p1};

    v6 = t1.getVertexNotinEdge(edge);
    print(v6); */


    /* //**** GRID DATA ********
    int xmin = 0, ymin = 0, xmax = 4, ymax = 4;
    int ndivx=4,ndivy=4;
    const int SIZE = ndivx*ndivy;
    //***********************
    POINT2D a{0.0,0.0},b{1.5,1.5},c{1.0,1.0};
    Edge<POINT2D> edge{a,b};
    Grid<Edge<POINT2D>> edgeGrid(xmin,xmax,ymin,ymax,ndivx,SIZE);

    edgeGrid.insertItem(edge); */

     /* Box<Edge<POINT2D>> *box;
    box = new Box<Edge<POINT2D>>[SIZE]; */
    //Edge<POINT2D> *edgeTarget = new Edge<POINT2D>; 
    
    //delete [] box;
    /* Box<Edge<POINT2D>> boxTar;
    boxTar = getBox(1);
    std::cout<<"Box index: "<<boxTar.getBoxIndex()<<std::endl; */




    //delete [] box;
   /*  Edge<POINT2D> *edgeTarget;
    edgeTarget = edgeGrid.searchContainingEdge(c);
    if(edgeTarget!=nullptr){
      printf("The Edge that contains the point has been found\n");
    }
    else{
      printf("LOSER\n");
    } */
    //std::cout<<"t1 vertex 0 shares: "<<t1(2).getSharingCells()<<std::endl;

    /* Mesh<TRIANGLE> delaunayMesh;
    delaunayMesh.append(t1);
    delaunayMesh.append(t2);
    delaunayMesh.append(t3);
    delaunayMesh.append(t4);

    std::cout<<"The length of the triangle Soup is: "<<delaunayMesh.getSize()<<"\n"; 

    TRIANGLE *triangle = new TRIANGLE;
    Edge<POINT2D> edge{p0,p1}; 
    triangle = delaunayMesh.findContainingCell(pEx);
    triangle = delaunayMesh.findTriangleNeighborTo(t1,t1.getEdge(1)); */
    /*if(t1.pointInCircumcircle(pC)==true){
      printf("The point is inside the Circumcircle\n");
    }
    else{
      printf("The point is accpted\n");
      //Edge<POINT2D> edge = edgeMesh.findContainingEdge(PEx);
    }*/
    //delaunayMesh.removeThisItem(t3);
   
    //delaunayMesh.removeTrianglesWith(t1(2));  
    //std::cout<<"The length of the triangle Soup NOW is: "<<delaunayMesh.getSize()<<"\n";
    return 0;
}