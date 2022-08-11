#ifndef ERROR_H
#define ERROR_H

void errorDisplay(sf::RenderWindow& window){
    sf::Font font;
    if (!font.loadFromFile("../arial.ttf")){
        std::cout<<"ERROR LOADING FONT...";
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(128);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setString("ERROR WITH \nCHOICE OF \nVISUALISATION");
    window.draw(text);
}

#endif