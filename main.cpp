#include <iostream>
#include "rlutil.h"
#include "card.h"
using namespace std;

int main()
{
    //Paleta de colores RLUtil
    /*for(int i = 0; i <= 20; i++){
        rlutil::setColor(i);
        cout << i << " ";
    }*/


    drawCard(1,1,10,5, 'Z');
    drawCard(2,2,20,5,'M');
    drawCard(3,3,30,5,'O');
    drawCard(4,1,40,5,'E');
    drawCard(5,2,50,5,'M');
    rlutil::hidecursor();
    rlutil::anykey();
    return 0;
}
