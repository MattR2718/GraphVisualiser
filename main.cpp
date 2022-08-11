#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include "SFML/Graphics.hpp"

#include "graph.h"
#include "tree.h"
#include "error.h"

void printInstructions(){
    std::cout<<"-------------------------------------\n";
    std::cout<<"INSTRUCTIONS: \n";
    std::cout<<"-------------------------------------\n";
    std::ifstream file("../instructions.txt");
    std::string linetxt;
    while(std::getline(file, linetxt)){
        std::cout<<linetxt<<'\n';
    }
    std::cout<<"-------------------------------------\n";
}

void setOptions(int& type, std::string& root){
    std::cout<<"-------------------------------------\n";
    std::cout<<"CHOOSE TYPE: \n";
    std::cout<<"1) Graph\n";
    std::cout<<"2) Binary Tree\n";
    std::cin>>type;
    std::cout<<"-------------------------------------\n";
    if (type == 2){
        std::cout<<"ENTER ROOT NODE: ";
        std::cin>>root;
        std::cout<<"-------------------------------------\n";
    }
}

auto getAdjacencyList(const std::string filename){
    std::map<std::string, std::vector<std::string>> adjacencyList;
    std::ifstream file(filename);
    std::string linetxt;
    while(std::getline(file, linetxt)){
        std::stringstream splitString(linetxt);
        std::string segment;
        std::vector<std::string> elements;
        while(std::getline(splitString, segment, ' '))
        {
            elements.push_back(segment);
        }
        std::string key = elements[0];
        elements.erase(elements.begin());
        adjacencyList[key] = elements;
    }
    return adjacencyList;
}

void printAdjacencyList(const std::map<std::string, std::vector<std::string>>& adjacencyList){
    std::cout<<"ADJACENCY LIST: \n";
    std::cout<<"-------------------------------------\n";
    for(const auto& elem : adjacencyList){
        std::string second = "";
        if (adjacencyList.count(elem.first)){
            for (const auto& w : elem.second){
                second += w + ", ";
            }
            if (second.length() > 2) { second.erase(second.begin() + second.length() - 2, second.end()); }
        }
        std::cout << elem.first << ": " << second << "\n";
    }
    std::cout<<"-------------------------------------\n";
}

int main(){

    printInstructions();

    const std::string fName = "../adjList.txt";
    std::map<std::string, std::vector<std::string>> adjacencyList = getAdjacencyList(fName);
    printAdjacencyList(adjacencyList);

    int type;
    std::string root;
    setOptions(type, root);

    const int WIDTH = 800;
    const int HEIGHT = 800;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Graph Visualiser");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        switch(type){
            case(1): {
                circleDraw(window, adjacencyList);
            }
            break;
            case(2): {
                //treeDraw(window, adjacencyList);
                errorDisplay(window, "ERROR\nTREE NOT\nWORKING");
            }
            break;
            default: {
                errorDisplay(window, "ERROR WITH \nCHOICE OF \nVISUALISATION");
            }
        }

        window.display();
    }
}



/*
Test Graph

one two three
two one four five
three one five
four three two
five
six five


Test Tree

one two three
two four five
three six seven
four
five eight
six
seven
eight
*/