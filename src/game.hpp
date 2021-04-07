#ifndef GAME
#define GAME value

class SDL_Surface;

class Game {
 public:
    Game();
    ~Game();

 private:
    void eventLoop();
    void update();
    void draw();

    SDL_Surface * screen_;
};

#endif /* ifndef GAME */
