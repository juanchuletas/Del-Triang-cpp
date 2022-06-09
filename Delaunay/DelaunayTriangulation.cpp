#include<iostream>
#include "DelaunayTriangulation.hpp"




void DelaunayTriangulation2D::buildEdgeGrid(int x_i, int x_f,int y_i, int y_f,int ndiv,int size){
    
    edgeGrid.setGrid(x_i,x_f,y_i, y_f,ndiv,size);
    
}
 void DelaunayTriangulation2D::startTriangulation(std::vector<POINT2D>&pointSoup){
     //double points;
     for(auto iter: pointSoup){
         print(iter);
     }
    double maxX, minX;
    double maxY, minY;
    minX = pointSoup[0][0];
    minY = pointSoup[0][1];
    maxX = minX; maxY = minY;
    double maxAnyCoord = 0.0;
    for(auto iter: pointSoup){
        maxAnyCoord = std::max(std::max(iter[0],iter[1]),maxAnyCoord);
        if(iter[0]<minX){minX = iter[0];}
        if(iter[1]<minY){minY = iter[1];}
        if(iter[0]>maxX){maxX = iter[0];}
        if(iter[1]>maxY){maxY = iter[1];}
    }
    maxAnyCoord = maxAnyCoord*16.0;
    POINT2D big_a{0.0,3.0*maxAnyCoord};
    POINT2D big_b{3.0*maxAnyCoord,0.0};
    POINT2D big_c{-3.0*maxAnyCoord,-3.0*maxAnyCoord};
    VERTEX p0{big_c},p1{big_b},p2{big_a};
    std::cout<<"MaxX = "<<maxX<<" MaxY = "<<maxY<<std::endl;
    std::cout<<"MinX = "<<minX<<" MinY = "<<minY<<std::endl;
    std::cout<<"MaxAnyCoord = "<<maxAnyCoord<<std::endl;
    printf("Creating the fucking supertriangle\n");
    TRIANGLE bigT{p0,p1,p2};
    triangleList.append(bigT);
    TRIANGLE *triangle = new TRIANGLE;
    printf("Size of the Triangle List: %d\n",triangleList.getSize());
    for(int i=0; i<pointSoup.size(); i++){
        printf("******** ADDING POINT %d **************\n",i+1);
        triangle = triangleList.findContainingCell(pointSoup[i]);
        if(triangle==nullptr){
           /*MORE SHITTY CODE HERE*/
           std::cout<<"POINT NOT INSIDE THE TRIANGLE\n";
        }
        else{
            print(*triangle);
            print(pointSoup[i]);
            VERTEX newVertex{pointSoup[i]};
            newVertex.setIndex(i);
            TRIANGLE t1{triangle->operator()(0),triangle->operator()(1),newVertex};
            TRIANGLE t2{triangle->operator()(1),triangle->operator()(2),newVertex};
            TRIANGLE t3{triangle->operator()(2),triangle->operator()(0),newVertex};
            printf("Triangle 1: \n");
            print(t1);
            printf("Triangle 2: \n");
            print(t1);
            printf("Triangle 3: \n");
            print(t1);
            triangleList.removeThisItem(*triangle);

            triangleList.append(t1);
            triangleList.append(t2);
            triangleList.append(t3);
           
            legalizeEdge(t1,t1.getEdge(0),newVertex);
            legalizeEdge(t2,t2.getEdge(0),newVertex);
            legalizeEdge(t3,t3.getEdge(0),newVertex);
        }   
    }
      triangleList.removeTrianglesWith(bigT(0));
     triangleList.removeTrianglesWith(bigT(1));
     triangleList.removeTrianglesWith(bigT(2));
     printf("************************************************************\n");
     printf("           FINAL SIZE OF THE TRIANGLE LIST: %d\n",triangleList.getSize());
     printf("**** HERE IS YOUR FUCKING DELAUNAY TRIANGULATION ****\n");
     triangleList.indexing();
     triangleList.printList();
     printf("************************************************************\n");
     printf("END OF DELAUNAY TRIANGULATION\n");

     //FIRST OF WE DEFINE ALL THE SHIT

    //Triangle<POINT2D> big_triangle;


 }

void DelaunayTriangulation2D::legalizeEdge(TRIANGLE &triangle, EDGE &edge, VERTEX &point){
     printf("LEGALIZING EDGES\n");
     printf("EDGE TARGET:\n");
     print(edge.getEdgeNode(0));
     print(edge.getEdgeNode(1));
    //This shit runs recursively until the entire neighboring area is free of illegal edges
    Triangle<POINT2D> *neighbour = triangleList.findTriangleNeighborTo(triangle,edge);
 
    if(neighbour!=nullptr){
        printf("**I FOUND A NEIGHBOUR**\n");
        if(neighbour->pointInCircumcircle(point())){
            printf("****************** IT'S CIRCUMCIRCLE********************\n");
            print(*neighbour);
            Vertex<POINT2D> vertexTarget = neighbour->getVertexNotinEdge(edge);
            printf("Vertex not in edge\n");
            print(vertexTarget());
            triangleList.removeThisItem(triangle);
            triangleList.removeThisItem(*neighbour);
            
            //print(vertexTarget);
            VERTEX edgevertexa{edge.getEdgeNode(0)};
            VERTEX edgevertexb{edge.getEdgeNode(1)};
            VERTEX newVertex{point};

            TRIANGLE t1{edgevertexa,vertexTarget,newVertex};
            TRIANGLE t2{vertexTarget,edgevertexb,newVertex};

            triangleList.append(t1);
            triangleList.append(t2);    
            legalizeEdge(t1,t1.getEdge(0),point);
            legalizeEdge(t2,t2.getEdge(0),point);

        }
        else{printf("***BUT IT'S LEGAL***\n");}

    }
    else{
        printf("**************** NOTHING TO LEGALIZE**************\n");
    }
}

