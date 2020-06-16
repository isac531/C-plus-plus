#include <iostream>
#include <string>

int main(){
    std::string nome;
    std::string nome2;
    std::string end;
    std::string end2;
    std::string num;
    std::string num2;
    
    std::cout<<"Informe o nome: \n";
    std::getline(std::cin,nome);
    std::cout<<nome <<"\n";
    std::cout<<"Informe o endereço: \n";
    std::getline(std::cin,end);
    std::cout<<end <<"\n";
    std::cout<<"Agora o número de telefone: \n";
    std::getline(std::cin,num);
    std::cout<<num <<"\n";
    std::cout<<"Informe o segundo nome: \n";
    std::getline(std::cin,nome2);
    std::cout<<nome2 <<"\n";
    std::cout<<"Informe o endereço: \n";
    std::getline(std::cin,end2);
    std::cout<<end2 <<"\n";
    std::cout<<"Informe o número: \n";
    std::getline(std::cin,num2);
    std::cout<<num2 <<"\n";
    std::cout<<"Os resultados são: \n";
    std::cout<<nome <<"\n";
    std::cout<<end <<"\n";
    std::cout<<num <<"\n";
    std::cout<<nome2 <<"\n";
    std::cout<<end2 <<"\n";
    std::cout<<num2 <<"\n";
    
}
