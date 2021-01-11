#include<iostream>
//#include "vector.hpp"
#include "vector.cpp"

int main()
{
    Vector<double,2> p1;
    p1.set(0,10.2);
    p1.set(1,23.3);
    Vector<double,2> p2;
    Vector<double,2> p3(1.0,0);
    Vector<double, 2> p4{3.3,4.5};
    Vector<double, 2>p5{p1};
    Vector<double, 2> p6 = p5 + p4;
    Vector<double,2> node1;
    Vector<double,2> node3;
    node1.set(0,2.0);
    node1.set(1,2.0);
    Vector<double,2> node2{node1};
    node3 = node2;
    node3  *= 100;
    double dotprod  = node3*p2;

    std::cout<<"The vector created is "<< p1[0]<<", "<<p1[1]<<std::endl;
    std::cout<<"The vector created is "<< p2[0]<<", "<<p2[1]<<std::endl;
    std::cout<<"The vector created is "<< p3[0]<<", "<<p3[1]<<std::endl;
    std::cout<<"The vector created is "<< p4[0]<<", "<<p4[1]<<std::endl;
    std::cout<<"The vector created is "<< p5[0]<<", "<<p5[1]<<std::endl;
    std::cout<<"The vector created is "<< p5[0]<<", "<<p5[1]<<std::endl;    
    std::cout<<"The node created is "<< node3[0]<<", "<<node3[1]<<std::endl;
    std::cout<<"The dot product is : "<<dotprod<<std::endl;
    print(node3);
    Vector<double, 3> vec3;
    print(vec3);

    Vector<double , 2> point1{2.2,3.0};
    print(point1);

    std::cout<<"Here comes the per Dot operator\n";

    if(p5==p1){
        printf("COOL\n");
    }
    else{
        printf("NOT COOL\n");

    }

    Vector<double, 2> a{3.0,0},b{1.0,1.0};
    std::cout<<"Res"<<a.perdot(b)<<"\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         


    return 0;
}