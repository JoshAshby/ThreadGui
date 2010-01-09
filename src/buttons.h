#ifndef BUTTONS
#define BUTTONS

#include "ofMain.h"
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
/*
Threadgui
2009 - Joshua Ashby
joshuaashby@joshashby.com
http://joshashby.com
*/
class button
{
    public:
        int xc;
        int yc;
        int hc;
        int shape;
        button()
        {
                test = 0;
        }
        //------------------------
        void roundButton(int x, int y, char srt[15], int color){
            shape = 0;
            int h;
            h = strlen(srt)*8+20;
            ofSetColor(0x094353);
            ofFill();
            ofCircle(x,y,h);
            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,h);
            hc = h;
            xc = x;
            yc = y;
        }
        //--------------------------
        void rectButton(int x, int y, char srt[15], int color){
        }
        //--------------------------
        void click(int x, int y){
        }
        //---------------------------
        void click(int color){
        }
        //--------------------------
    private:
        int test;
};
#endif
