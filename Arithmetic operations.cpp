#include<iostream>
#include<cmath>
int main()
{
    //Dimension of the cube
    float cubeSide = 5.4;
    //Dimension of sphere
    float sphereRadius = 2.33;
    //Dimensions of cone
    float coneRadius = 7.65;
    float coneHeight = 14;
    
    float volCube, volSphere, volCone = 0;
    
    volCube = std::pow(cubeSide, 3);
    volSphere = (4.0/3.0) * M_PI * std::pow(sphereRadius, 3);
    volCone = M_PI * std::pow(coneRadius, 2) * (coneHeight/3);
    
    std::cout<< volCube << " " << volSphere << " " << volCone;
    return 0;
}
