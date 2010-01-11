#ifndef BUTTONS
#define BUTTONS

#include "ofMain.h"
#include "ofxThread.h"
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
class button : public ofxThread
{
    public:
        int xc;
        int yc;
        int hc;
        int shape;
        int clicked;
        //--------------------------
		void start(){
            startThread(true, false);   // blocking, verbose
        }
        //------------------------
        void stop(){
            stopThread();
        }
		//--------------------------
		void threadedFunction(){
			/*while( isThreadRunning() != 0 ){
				if( lock() ){
					unlock();
					ofSleepMillis(1 * 1000);
				}
			}*/
		}
        //--------------------------
        button()
        {
        }
        //------------------------
        void roundButton(int x, int y, char srt[15], int color){
            //thread stuff
            if( lock() ){
                unlock();
            }else{
                printf("can't lock!\neither an error\nor the thread has stopped");
            }
            shape = 0;
            int h;
            h = strlen(srt)*8+20;
            if (clicked){
                ofSetColor(0x094353);
            } else {
                ofSetColor(0x291831);
            }
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
            //thread stuff
            if( lock() ){
                unlock();
            }else{
                printf("can't lock!\neither an error\nor the thread has stopped");
            }
        }
        //---------------------------
        //---------------------------
        void click(){
            //thread stuff
            if( lock() ){
                unlock();
            }else{
                printf("can't lock!\neither an error\nor the thread has stopped");
            }
            clicked = !clicked;
            printf("%i\n", clicked);

        }
        //---------------------------
    private:
        int test;
};
#endif
