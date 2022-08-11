#ifndef GRAPH_H
#define GRAPH_H
#define PI 3.14159

void circleDraw(sf::RenderWindow& window, const std::map<std::string, std::vector<std::string>>& adjacencyList){
    sf::Vector2u res = window.getSize();
    int width = res.x;
    int height = res.y;
    int cSize = 10;
    sf::CircleShape circle(cSize);
    circle.setFillColor(sf::Color::White);
    double r = 0.8 * width/2;
    int x = 0;
    int y = r;
    int n = adjacencyList.size();
    std::map<std::string, std::pair<int, int>> pos;

    float angle = 0;
    float angleInc = 2*PI / float(n);
    for(const auto& elem : adjacencyList){
        int nx = x * cos(angle) + y * sin(angle);
        int ny = y * cos(angle) - x * sin(angle);
        circle.setPosition(nx + width/2 - cSize, ny + height/2 - cSize);
        window.draw(circle);
        pos[elem.first] = std::make_pair(nx + width/2, ny + height/2);
        angle += angleInc;
    }

    int outoffset = cSize / 2;
    for(const auto& elem : adjacencyList){
        if (adjacencyList.count(elem.first)){
            for (const auto& w : elem.second){
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(pos[elem.first].first + outoffset, pos[elem.first].second + outoffset)),
                    sf::Vertex(sf::Vector2f(pos[w].first, pos[w].second), sf::Color::Red)
                };
                window.draw(line, 2, sf::Lines);
            }
        }
    }

    sf::Font font;
    if (!font.loadFromFile("../arial.ttf")){
        std::cout<<"ERROR LOADING FONT...";
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    for(const auto& elem : adjacencyList){
        std::string str = elem.first;
        std::transform(str.begin(), str.end(),str.begin(), ::toupper);
        text.setString(str);
        text.setPosition(sf::Vector2f(pos[elem.first].first, pos[elem.first].second));
        window.draw(text);
    }

}

#endif