#ifndef _SERIAL_OBJECT
#define _SERIAL_OBJECT

#include "ofMain.h"
#include "ofxThread.h"
#include <cstring>
#include "testApp.h"

/*
Serial Thread
2009 - Joshua Ashby
joshuaashby@joshashby.com
http://joshashby.com
*/

class serialObject : public ofxThread{

	public:
        int sRead;
        unsigned char bytesReturned[3];
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
		    //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
            serial.setup(str, speed);
		}
        //--------------------------
        void read(){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
            sRead = serial.readBytes( bytesReturned, 3);
//debug            printf("got: %i\n", sRead);
        }
        //--------------------------
        void write(float data){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
            serial.writeByte(data);
        }
        //--------------------------
};

#endif
