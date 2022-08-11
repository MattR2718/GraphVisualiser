#ifndef TREE_H
#define TREE_H

#include <stack>

std::string getStart(const std::map<std::string, std::vector<std::string>>& adjacencyList){
    std::string start;
    std::vector<std::string> notStart;
    std::vector<std::string> nodes;
    for(const auto& elem : adjacencyList){
        nodes.push_back(elem.first);
        if (adjacencyList.count(elem.first)){
            for (const auto& w : elem.second){
                notStart.push_back(w);
            }
        }
    }
    for (auto& e : nodes){
        if (!(std::find(notStart.begin(), notStart.end(), e) != notStart.end())){
            start = e;
        }
    }
    //std::cout<<"START NODE: "<<start<<'\n';
    return start;
}

/*
int getDepth(std::map<std::string, std::vector<std::string>> adjacencyList, const std::string& start){
    std::vector<int> depths;
    int depth = 1;
    std::string current = start;
    std::stack<std::string> stack;
    stack.push(current);
    std::map<std::string, bool> visited;
    visited[current] = true;

    while (!stack.empty()){
        if (adjacencyList.count(stack.top())){
            std::vector<std::string> list = adjacencyList[stack.top()];
            for(auto& n : list){
                if (!visited[n]){
                    current = n;
                    stack.push(n);
                    break;
                }
            }
            depth++;
            depths.push_back(depth);
        } else{
            stack.pop();
        }
        std::cout<<"IN WHILE LOOP\n";
    }

    int max = *max_element(depths.begin(), depths.end());
    return max;
}
*/

void treeDraw(sf::RenderWindow& window, const std::map<std::string, std::vector<std::string>>& adjacencyList, int treeDepth = 5){
    std::string start = getStart(adjacencyList);
    //int depth = getDepth(adjacencyList, start);
    int depth = treeDepth;
    sf::Vector2u res = window.getSize();
    int width = res.x;
    int height = res.y;
    int cSize = 10;
    sf::CircleShape circle(cSize);
    circle.setFillColor(sf::Color::White);
    int top = 0.1 * height;
    int mid = 0.5 * width;
    int addDepth = height * 0.8 / depth;
    
}

#endif