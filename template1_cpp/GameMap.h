#ifndef MAIN_GAMEMAP_H
#define MAIN_GAMEMAP_H

#include <Player.h>
#include <Image.h>
#include <config.h>

using namespace std;

struct Map
{
    char *lattice;
    int lattice_size;
    int BlockSize;

    Image backgr = Image(WINDOW_HEIGHT, WINDOW_WIDTH, 4);
    Point begin_pos{.x = LATTICE_SIZE - 2, .y =  LATTICE_SIZE - 2};
    Player pl = Player(begin_pos);

    public:
    
        Map(const string &level);

        ~Map()
        {
            delete lattice;
        }
        
        Player takePlayer()
        {
            return pl;
        }

        void render(Image &screen);

        void rerender(Image &screen);

    private:
        void builtMap();

        void buildDoor(int x, int y);

        void buildWall(int x, int y);

        void buildFloor(int x, int y);

        void buildTerrain(int x, int y);

        void renderBlock(Image &screen, int x, int y);



};

#endif 