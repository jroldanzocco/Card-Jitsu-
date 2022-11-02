#include <iostream>
#include "card.h"
#include "rlutil.h"
using namespace std;



void box(int x,int y ,int width, int height){
    width--;
    height--;
    for(int posx = x; posx <= x + width; posx++){
        rlutil::locate(posx, y);
        cout << (char)205;
        rlutil::locate(posx,y+height);
        cout << (char)205;
    }
    for(int posy = y; posy <= y + height; posy++){
        rlutil::locate(x, posy);
        cout << (char)186;
        rlutil::locate(x+width, posy);
        cout << (char)186;
    }

    rlutil::locate(x,y);
    cout << (char)201;

    rlutil::locate(x+width, y);
    cout << (char)187;

    rlutil::locate(x,y+height);
    cout << (char)200;

    rlutil::locate(x+width,y+height);
    cout << (char)188;

}

void setColor(char color){
    switch(color){
    case 'Z':
        rlutil::setColor(9);
        break;
    case 'M':
        rlutil::setColor(6);
        break;
    case 'O':
        rlutil::setColor(4);
        break;
    case 'E':
        rlutil::setColor(10);
        break;
    }
}

void drawCard(char number, int type, int x, int y, char color){
    setColor(color);
    box(x,y,7,5);


    rlutil::locate(x + 1, y + 1);
    cout << number;

    rlutil::locate(x + 5, y + 3);
    cout << number;

    rlutil::locate(x + 3, y + 2);
    switch(type)    {
        case 1:
            cout << "F";
            break;
        case 2:
            cout << "N";
            break;
        case 3:
            cout << "A";
            break;
    }



}
