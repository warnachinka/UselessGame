#include <GameSprites.h>

Sprite* Sprite::singleton_= nullptr;

Sprite *Sprite::Get()
{
    if (singleton_ == nullptr)
        singleton_ = new Sprite();
    return singleton_;
}

void Sprite::load(Image &blocks)
{
    wall.IntBlock(blocks, 16, 480);

    floor.IntBlock(blocks, 16, 432);
}
