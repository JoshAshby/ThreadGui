#ifndef _THREADED_OBJECT
#define _THREADED_OBJECT

#include "ofMain.h"
#include "ofxThread.h"
#include <cstring>
#include <string>
#include <vector>
#include "buttons.h"
/*
Threadgui
2009 - Joshua Ashby
joshuaashby@joshashby.com
http://joshashby.com
*/

class threadedObject : public ofxThread{

	public:

                    //yucky thread stuff:
                    // threaded fucntions that share data need to use lock (mutex)
	                // and unlock in order to write to that data
	                // otherwise it's possible to get crashes.

		//--------variables---------
		//--------------------------
		void buttonAction(int button){
		    //thread stuff
            if( lock() ){
                unlock();
            }else{
                printf("can't lock!\neither an error\nor the thread has stopped");
            }
            switch(button) {
                //example
                //button 0 with print " < " to the terminal
                case 0:
                    printf("<\n");
                    break;
            }
		}
		vector<button> vec;
		button *cl;
		string temp;
		//----------------------
		threadedObject(){
		}
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
			while( isThreadRunning() != 0 ){
				if( lock() ){
					unlock();
					ofSleepMillis(1 * 1000);
				}
			}
		}
        //--------------------------
        void draw(int x, int y, char str[15], int color, int shape){
            //thread stuff
            if( lock() ){
                unlock();
            }else{
                printf("can't lock!\neither an error\nor the thread has stopped");
            }
            cl = new button;
            switch(shape){
                case 0:
                    cl->roundButton(x,y,str,color);
                    vec.push_back(*cl);
                    break;
                case 1:
                    cl->rectButton(x,y,str,color);
                    vec.push_back(*cl);
                    break;
            }
        }
        //--------------------------
        void click(int x, int y){
            int centerx;
            int centery;
            int h;
            int shape;
            //thread stuff
            int other;
            if( lock() ){
                unlock();
            }else{
                printf("can't lock!\neither an error\nor the thread has stopped");
            }

            vector<button>::iterator it;

            for ( it = vec.begin(); it != vec.end(); ++it ) {
                centerx = it->xc;
                centery = cl->yc;
                h = cl->hc;
                shape = cl->shape;
                switch(shape){
                    case 0:
                        //circle area stuff
                        break;
                    case 1:
                        //square area stuff
                        break;
                }
//debug                printf("%i\n", other);
            }
        }
        //--------------------------
        void click(int x){
            int centerx;
            int centery;
            int h;
            if( lock() ){
                unlock();
            }else{
                printf("can't lock!\neither an error\nor the thread has stopped");
            }

            vector<button>::iterator it;

            for ( it = vec.begin(); it != vec.end(); ++it ) {
                centerx = it->xc;
                centery = cl->yc;
                h = cl->hc;
//debug                printf("%i\n", other);
            }
        }
};
#endif
