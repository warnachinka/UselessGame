#ifndef MAIN_SITE_H
#define MAIN_SITE_H

#include <Image.h>
#include <config.h>

struct Point
{
    int x;
    int y;
};

enum class MovDir
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Site
{
    protected:
        static Point DirToVec(MovDir dir);

        void Move(MovDir dir);

        void SetDir(MovDir dir);

        Point pos;
        Point prev_pos;
        MovDir direction = MovDir::LEFT;
        MovDir turnDir = MovDir::LEFT;

        void RefreshPrevPos() 
        {
            prev_pos.x = pos.x; 
            prev_pos.y = pos.y;
        }

        public:
            Site(Point position): pos(position), prev_pos(position) {}

            ~Site() {}

            Point GetPos()
            {
                return pos;
            }

            Point GetPrevPos()
            {
                return prev_pos;
            }

            void render(Image &window);
};

#endif