#include <Site.h>
#include <config.h>

void Site::render(Image &window)
{
    int shear_x = 0;
    int shear_y = 0;
    int shear_prev_x = 0;
    int shear_prev_y = 0;
    
    Image *ToRender;
    Image *ToRender_;

    if (shear_prev_x != 0 || shear_prev_y != 0)
    {
        window.PutBlock(prev_pos.x, prev_pos.y, *ToRender, 0, 0, shear_prev_x, shear_prev_y);
        window.PutBlock(prev_pos.x, prev_pos.y, *ToRender_, 0, 0, shear_prev_x, shear_prev_y);
    }

    window.PutBlock(pos.x, pos.y, *ToRender, 0, 0, shear_x, shear_y);
    window.PutBlock(pos.x, pos.y-1, *ToRender_, 0, 0, shear_x, shear_y);
}

void Site::Move(MovDir dir)
{
    RefreshPrevPos();
    Point dirVec = DirToVec(dir);

    pos.x += dirVec.x;
    pos.y += dirVec.y;
}

void Site::SetDir(MovDir dir)
{
    direction = dir;
    if (dir == MovDir::LEFT || dir == MovDir::RIGHT)
        turnDir = dir;
}