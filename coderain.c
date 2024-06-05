#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int CHAR_SIZE = 20;
const int RAIN_SPEED = 10;
const int MAX_RAIN_DROPS = 100;

struct RainDrop {
    float x, y;
    sf::Color color;
};

void initRainDrop(RainDrop& drop) {
    drop.x = std::rand() % WINDOW_WIDTH;
    drop.y = -(std::rand() % WINDOW_HEIGHT);
    drop.color = sf::Color::Green; // You can change the color here
}

void updateRainDrop(RainDrop& drop) {
    drop.y += RAIN_SPEED;
    if (drop.y > WINDOW_HEIGHT) {
        drop.y = -(std::rand() % WINDOW_HEIGHT);
        drop.x = std::rand() % WINDOW_WIDTH;
    }
}

int main() {
    std::srand(std::time(nullptr));
    
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Matrix Code Rain");
    window.setFramerateLimit(60);
    
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) { // Load a font for displaying characters
        return EXIT_FAILURE;
    }
    
    sf::Text text("", font, CHAR_SIZE);
    
    RainDrop rainDrops[MAX_RAIN_DROPS];
    
    for (int i = 0; i < MAX_RAIN_DROPS; ++i) {
        initRainDrop(rainDrops[i]);
    }
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        window.clear();
        
        for (int i = 0; i < MAX_RAIN_DROPS; ++i) {
            updateRainDrop(rainDrops[i]);
            text.setPosition(rainDrops[i].x, rainDrops[i].y);
            text.setFillColor(rainDrops[i].color);
            text.setString(char(std::rand() % 256)); // Display a random character
            window.draw(text);
        }
        
        window.display();
    }
    
    return EXIT_SUCCESS;
}
