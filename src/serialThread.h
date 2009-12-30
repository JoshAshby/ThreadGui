#ifndef _SERIAL_OBJECT
#define _SERIAL_OBJECT

#include "ofMain.h"
#include "ofxThread.h"
#include <cstring>

/*
Threadgui
2009 - Joshua Ashby
joshuaashby@joshashby.com
http://joshashby.com
*/
extern int sRead;
class serialObject : public ofxThread{

	public:
        ofSerial	serial;

        serialObject(){
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
		void setup(char str[20], int speed){
            serial.setup(str[20], speed);
		}
        //--------------------------
        void read(){
            unsigned char bytesReturned[3];
            sRead = serial.readBytes( bytesReturned, 3);
        }
        //--------------------------
        void write(float data){
            serial.writeByte(data);
        }
        //--------------------------
};

#endif
