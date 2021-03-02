#ifndef MAIN_SPRITE_H
#define MAIN_SPRITE_H

#include <Image.h>
#include <config.h>

class Sprite
{
    protected:
        Sprite(){}

        static Sprite* singleton_;

    public:
        Sprite (Sprite &other) = delete;

        void operator = (const Sprite &) = delete;

        static Sprite *Get();

        void load(Image &blocks);

        Image wall = Image(BLOCK_SIZE, BLOCK_SIZE, 4);
        Image side_wall = Image(BLOCK_SIZE, BLOCK_SIZE, 4);

        Image floor = Image(BLOCK_SIZE, BLOCK_SIZE, 4);

        Image door = Image(BLOCK_SIZE, BLOCK_SIZE, 4);

};

#endif