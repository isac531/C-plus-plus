#include <iostream>
 #include <string>
 #include <sstream>
 
 int main(){
     std::string stringcomp;
     std::string stringlarg;
     float comprimento;
     float largura;
     float area;
     std::cout<<"Coloque o comprimento: \n";
     std::getline(std::cin,stringcomp);
     std::stringstream(stringcomp)>> comprimento;
     std::cout<<comprimento <<"\n";
     std::cout<<"Agora insira a largura: \n";
     std::getline(std::cin,stringlarg);
     std::stringstream(stringlarg)>> largura;
     std::cout<<largura <<"\n";
     area= comprimento * largura;
     std::cout<<"A área é: " <<area <<"\n";
     return 0;
     
 }
