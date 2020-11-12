#include <iostream>
#include <vector>  //borrar
#include <cstring>//borrar
#include <fstream>//borrar
#include "server_petitionsolver.h"//borrar
#include "server_server.h"
#include <algorithm> //borrar

bool IsOdd (int i) { return ((i%2)==1); }

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Error: argumentos invalidos." << std::endl;
        return 1;
    }
    /*try {
        // Ejecutar
        Server server(std::string(argv[2], strlen(argv[2])));
        server.run(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Error" << std::endl;
        return 1;
    }*/

    std::ofstream filee;
    filee.open("prueba.txt");

    filee << "hola br";

    //char str[] = "POST / holadfssssfdsdfdfsdfsddddddddd";
    //char str1[1024];
    //char str2[1024];
    //strncpy(str1, str, 20);

    /*char c;
    std::fstream root;
    root.open("index.html");
    while (root.get(c)){
        std::cout << c;
    }*/

    std::vector<int> arr;
    arr.push_back(2);


    arr.erase(std::remove_if(arr.begin(), arr.end(), IsOdd), arr.end());
    std::cout << arr.back() << std::endl;
    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << arr[2] << std::endl;
    /*
PetitionSolver solver(str1, str2, "index.html", 3);
int n = solver.solve();

std::cout << n << std::endl;
std::cout << str2 << std::endl;*/

/*
if (std::ifstream("inde")) {
    std::cout << "existee" << std::endl;
} else {
    std::cout << "no existee" << std::endl;
};

*/





/*

    try {

    } catch (...) {

    }
*/
  /*  std::cout << "Hello World!" << std::endl;

    std::vector<std::string> v;
    std::string str = "example";
    v.push_back(std::move(str));

    std::cout << v[0] << std::endl;
*/
    return 0;
}
