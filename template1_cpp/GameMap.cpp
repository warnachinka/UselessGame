#include <GameMap.h>
#include <fstream>

using namespace std;

Map::Map(const string &level): lattice_size(LATTICE_SIZE), BlockSize(BLOCK_SIZE)
{
    lattice = new char[lattice_size*lattice_size];

    char smb;
    int t = 0;
    fstream fin(level, fstream::in);
    while(fin >> noskipws >> smb)
    {
        if (smb = '\n') continue;
        lattice[t++];
    }
    fin.close();

    builtMap();

}

void Map::render(Image &screen)
{
    for(int i = 0; i < screen.Height(); i ++)
    {
        for (int j = 0; j < screen.Width(); j++)
        {
            screen.PutPixel(i, j, backgr.GetPixel(i, j));
        }
    }
}
void Map::rerenderBlock()
