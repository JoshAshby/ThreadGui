 #ifndef _THREADED_OBJECT
#define _THREADED_OBJECT

#include "ofMain.h"
#include "ofxThread.h"
#include "serialThread.h"
#include <cstring>

/*
Threadgui
2009 - Joshua Ashby
joshuaashby@joshashby.com
http://joshashby.com
*/
class threadedObject : public ofxThread{

	public:
        serialObject    ST;

                    //yucky thread stuff:
                    // threaded fucntions that share data need to use lock (mutex)
	                // and unlock in order to write to that data
	                // otherwise it's possible to get crashes.
	                //
	                //This file sets up the thread in charge of all of the buttons,
	                //and the click functions for them.
	                //The roundButtons function is called to draw a circular button,
	                //simply give it the (x,y) of the center of the circle, the radius
	                //the text, and the number (soon to be removed).
	                //the function will then draw the button, set up the color change for
	                //click, and place the text in the center of the button.

        /*
        This GUI has the following:

        label - blue
        labelGreen
        labelGrey

        rectButton - blue
        rectButtonGrey
        rectButtonGreen

        roundButton - blue
        roundButtonGrey
        roundButtonGreen

        line - white
        lineGreen
        lineGrey
        lineBlue

        bullet - grey
        bulletGreen
        bulletBlue

        mlBullet - grey
        mlBulletGreen
        mlBulletBlue

        */

		//--------variables---------
		bool roundbuttons[1024];
		//this is the max # of buttons, if you change this, change the 1024
		//in the click statment to the same number you change this to.
		int xcoord[1024];//and change these three
		int ycoord[1024];// <--
		int hvalue[1024];// <--
		int width;
		int button;
		int i;
		//--------------------------
		//set the functions of the
		//buttons used in tesatApp
		//here by the button numbers
		//--------------------------
		void buttonAction(int button){
            switch (button) {
                //example
                //button 0 with print " < " to the terminal
                case 0:
                    printf("^\n");
                    ST.write(102);
                    break;
                case 1:
                    printf("V\n");
                    ST.write(102);
                    break;
                case 2:
                    printf(">\n");
                    ST.write(102);
                    break;
                case 3:
                    printf("^\n");
                    ST.write(102);
                    break;
                case 4:
                    ofSetWindowShape(800,400);
                    break;
                case 5:
                    ST.setup("/dev/ttyUSB0", 9600);
                    break;
            }
		}
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
        void label(int x, int y, char str[20]){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
			int width;
			ofPushStyle();
            ofSetRectMode(OF_RECTMODE_CORNER);

			width = strlen(str)*8 + 10;

			ofSetColor(0x012345);
			ofFill();
			ofRect(x,y,width,20);

			ofSetColor(0xffffff);
            ofDrawBitmapString(str,x+5,y+15);
            ofPopStyle();
        }
        //--------------------------
        void labelGreen(int x, int y, char str[20]){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
			int width;
			ofPushStyle();
            ofSetRectMode(OF_RECTMODE_CORNER);

			width = strlen(str)*8 + 10;

			ofSetColor(0x029807);
			ofFill();
			ofRect(x,y,width,20);

			ofSetColor(0xffffff);
            ofDrawBitmapString(str,x+5,y+15);
            ofPopStyle();
        }
        //--------------------------
        void labelGrey(int x, int y, char str[20]){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
			int width;
			ofPushStyle();
            ofSetRectMode(OF_RECTMODE_CORNER);

			width = strlen(str)*8 + 10;

			ofSetColor(0x456456);
			ofFill();
			ofRect(x,y,width,20);

			ofSetColor(0xffffff);
            ofDrawBitmapString(str,x+5,y+15);
            ofPopStyle();
        }
        //--------------------------
        void rectButton(int x, int y, char srt[15], int color){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
//debug            printf("got:\n x: %i \n y: %i \n h: %i \n text: %s \n if-then: %s \n", x, y, h, srt, color);
            //draw the circle with radius h at cord. (x,y)
            int h;
            h = strlen(srt);
            h = (h*8)+20;

            //figuring these out to fit in with my click code was a major PITA
            xcoord[color] = x-(h/2);
            ycoord[color] = y-(h/2);
            hvalue[color] = h/2;

            ofPushStyle();
            ofSetRectMode(OF_RECTMODE_CENTER);
//debug            printf("%i",ofGetRectMode());
            if (roundbuttons[color]) {
                ofSetColor(0x029807);
            } else {
                ofSetColor(0x094353);
            }
            ofFill();
            ofRect(x,y,h,h);
            ofNoFill();
            ofSetColor(0xffffff);
            ofRect(x,y,h,h);

//debug            ofSetColor(0x094353);
//debug            ofRect((x-((h/2)/x)),(y-((h/2)/y)),h,h);

            //calculate how far over the text needs to be to be in the center of the circle
            width = strlen(srt);
            width = (width*8)/2;//8 is the average width of a letter for this

            //draw the text in the center of the circle
            ofSetColor(0x000000);
            x = x-width;
            ofDrawBitmapString(srt,x,y);
            ofPopStyle();
        }
		//--------------------------
        void rectButtonGrey(int x, int y, char srt[15], int color){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
//debug            printf("got:\n x: %i \n y: %i \n h: %i \n text: %s \n if-then: %s \n", x, y, h, srt, color);
            //draw the circle with radius h at cord. (x,y)
            int h;
            h = strlen(srt);
            h = (h*8)+20;

            //figuring these out to fit in with my click code was a major PITA
            xcoord[color] = x-(h/2);
            ycoord[color] = y-(h/2);
            hvalue[color] = h/2;

            ofPushStyle();
            ofSetRectMode(OF_RECTMODE_CENTER);
//debug            printf("%i",ofGetRectMode());
            if (roundbuttons[color]) {
                ofSetColor(0x029807);
            } else {
                ofSetColor(0x456456);
            }
            ofFill();
            ofRect(x,y,h,h);
            ofNoFill();
            ofSetColor(0xffffff);
            ofRect(x,y,h,h);

//debug            ofSetColor(0x094353);
//debug            ofRect((x-((h/2)/x)),(y-((h/2)/y)),h,h);

            //calculate how far over the text needs to be to be in the center of the circle
            width = strlen(srt);
            width = (width*8)/2;//8 is the average width of a letter for this

            //draw the text in the center of the circle
            ofSetColor(0x000000);
            x = x-width;
            ofDrawBitmapString(srt,x,y);
            ofPopStyle();
        }
		//--------------------------
		void rectButtonGreen(int x, int y, char srt[15], int color){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
//debug            printf("got:\n x: %i \n y: %i \n h: %i \n text: %s \n if-then: %s \n", x, y, h, srt, color);
            //draw the circle with radius h at cord. (x,y)
            int h;
            h = strlen(srt);
            h = (h*8)+20;

            //figuring these out to fit in with my click code was a major PITA
            xcoord[color] = x-(h/2);
            ycoord[color] = y-(h/2);
            hvalue[color] = h/2;

            ofPushStyle();
            ofSetRectMode(OF_RECTMODE_CENTER);
//debug            printf("%i",ofGetRectMode());
            if (roundbuttons[color]) {
                ofSetColor(0x456456);
            } else {
                ofSetColor(0x029807);
            }
            ofFill();
            ofRect(x,y,h,h);
            ofNoFill();
            ofSetColor(0xffffff);
            ofRect(x,y,h,h);

//debug            ofSetColor(0x094353);
//debug            ofRect((x-((h/2)/x)),(y-((h/2)/y)),h,h);

            //calculate how far over the text needs to be to be in the center of the circle
            width = strlen(srt);
            width = (width*8)/2;//8 is the average width of a letter for this

            //draw the text in the center of the circle
            ofSetColor(0x000000);
            x = x-width;
            ofDrawBitmapString(srt,x,y);
            ofPopStyle();
        }
		//--------------------------
        void roundButton(int x, int y, int h, char srt[15], int color){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
//debug            printf("got:\n x: %i \n y: %i \n h: %i \n text: %s \n if-then: %s \n", x, y, h, srt, color);
            //draw the circle with radius h at cord. (x,y)
            xcoord[color] = x-h;
            ycoord[color] = y-h;
            hvalue[color] = h;
//debug            printf("x:%i\ny:%i\n",xcoord[color],ycoord[color]);
            if (roundbuttons[color]) {
                ofSetColor(0x029807);
            } else {
                ofSetColor(0x094353);
            }
            ofFill();
            ofCircle(x,y,h);
            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,h);

            //calculate how far over the text needs to be to be in the center of the circle
            width = strlen(srt);
            width = (width*8)/2;//8 is the average width of a letter for this

            //draw the text in the center of the circle
            ofSetColor(0x000000);
            x = x-width;
            ofDrawBitmapString(srt,x,y);
		}
		//--------------------------
		void roundButtonGrey(int x, int y, int h, char srt[15], int color){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
//debug            printf("got:\n x: %i \n y: %i \n h: %i \n text: %s \n if-then: %s \n", x, y, h, srt, color);
            //draw the circle with radius h at cord. (x,y)
            xcoord[color] = x-h;
            ycoord[color] = y-h;
            hvalue[color] = h;
//debug            printf("x:%i\ny:%i\n",xcoord[color],ycoord[color]);
            if (roundbuttons[color]) {
                ofSetColor(0x029807);
            } else {
                ofSetColor(0x456456);
            }
            ofFill();
            ofCircle(x,y,h);
            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,h);

            //calculate how far over the text needs to be to be in the center of the circle
            width = strlen(srt);
            width = (width*8)/2;//8 is the average width of a letter for this

            //draw the text in the center of the circle
            ofSetColor(0x000000);
            x = x-width;
            ofDrawBitmapString(srt,x,y);
		}
        //-----------------------------
        void roundButtonGreen(int x, int y, int h, char srt[15], int color){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
//debug            printf("got:\n x: %i \n y: %i \n h: %i \n text: %s \n if-then: %s \n", x, y, h, srt, color);
            //draw the circle with radius h at cord. (x,y)
            xcoord[color] = x-h;
            ycoord[color] = y-h;
            hvalue[color] = h;
//debug            printf("x:%i\ny:%i\n",xcoord[color],ycoord[color]);
            if (roundbuttons[color]) {
                ofSetColor(0x456456);
            } else {
                ofSetColor(0x029807);
            }
            ofFill();
            ofCircle(x,y,h);
            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,h);

            //calculate how far over the text needs to be to be in the center of the circle
            width = strlen(srt);
            width = (width*8)/2;//8 is the average width of a letter for this

            //draw the text in the center of the circle
            ofSetColor(0x000000);
            x = x-width;
            ofDrawBitmapString(srt,x,y);
		}
        //-----------------------------
		void click(int x, int y){
		    //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
			//setup two variables
            int xc;
            int yc;
            //here we go (cycling through the buttons
            for (i = 0; i < 1024; i++){
                //get the lower corner coordinates
                xc = xcoord[i] + hvalue[i]*2;
                yc = ycoord[i] + hvalue[i]*2;
//debug                printf("x: %i\ny: %i\nxcoord: %i\nycoord: %i\nxc: %i\nyc: %i\nh: %i\n",x,y,xcoord[i],ycoord[i],xc,yc,hvalue[i]);
                //if the x is with in range of a button
                if (x > xcoord[i] && x < xc){
                    //then see if y is in range
                    if (y > ycoord[i] && y < yc){
//debug                        printf("y: %i\n",y);
                        //if it is, change the that buttons color
                        button = i;
                        roundbuttons[button] = !roundbuttons[button];
                        //place case statement here for button functions.
                        buttonAction(button);
                    }
                }
            }
		}
		//---------------------------
		//Second click that does it by button number so you can use this in the testApp::keyPressed for example
		//or generating a sequence to change them
		void click(int color){
		    //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
            roundbuttons[color] = !roundbuttons[color];
            //place case statement here for button functions.
            //threadedObject.buttonAction(button);
            buttonAction(button);
		}
		//-------------------------
        void line(int x,int y, int xc, int yc, int thick){
            ofSetColor(0xffffff);
            ofPushStyle();
            ofSetLineWidth(thick);
            ofLine(x,y,xc,yc);
            ofPopStyle();
        }
        //-------------------------
        void lineGreen(int x,int y, int xc, int yc, int thick){
            ofSetColor(0x029807);
            ofPushStyle();
            ofSetLineWidth(thick);
            ofLine(x,y,xc,yc);
            ofPopStyle();
        }
        //-------------------------
        void lineGrey(int x,int y, int xc, int yc, int thick){
            ofSetColor(0x456456);
            ofPushStyle();
            ofSetLineWidth(thick);
            ofLine(x,y,xc,yc);
            ofPopStyle();
        }
        //--------------------------
        void lineBlue(int x,int y, int xc, int yc, int thick){
            ofSetColor(0x094353);
            ofPushStyle();
            ofSetLineWidth(thick);
            ofLine(x,y,xc,yc);
            ofPopStyle();
        }
        //--------------------------
        void bullet(int x, int y, char str[20]){
            int xt;
            int yt;

            xt = x + 15;
            yt = y + 4;

            ofFill();
            ofSetColor(0x456456);
            ofCircle(x,y,5);

            ofPushStyle();
            ofSetLineWidth(2);
            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,5);
            ofPopStyle();

            ofSetColor(0xffffff);
            ofDrawBitmapString(str,xt,yt);
        }
        //--------------------------
        void bulletGreen(int x, int y, char str[20]){
            int xt;
            int yt;

            xt = x + 15;
            yt = y + 4;

            ofFill();
            ofSetColor(0x029807);
            ofCircle(x,y,5);

            ofPushStyle();
            ofSetLineWidth(2);
            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,5);
            ofPopStyle();

            ofSetColor(0xffffff);
            ofDrawBitmapString(str,xt,yt);
        }
        //--------------------------
        void bulletBlue(int x, int y, char str[20]){
            int xt;
            int yt;

            xt = x + 15;
            yt = y + 4;

            ofFill();
            ofSetColor(0x094353);
            ofCircle(x,y,5);

            ofPushStyle();
            ofSetLineWidth(2);
            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,5);
            ofPopStyle();

            ofSetColor(0xffffff);
            ofDrawBitmapString(str,xt,yt);
        }
        //--------------------------
        void mlBullet(int x, int y, char str[20]){
            int xt;
            int yt;

            xt = x + 15;
            yt = y - 2;

            ofFill();
            ofSetColor(0x456456);
            ofCircle(x,y,5);

            ofPushStyle();
            ofSetLineWidth(2);
            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,5);
            ofPopStyle();

            ofSetColor(0xffffff);
            ofDrawBitmapString(str,xt,yt);
        }
        //--------------------------
        void mlBulletGreen(int x, int y, char str[20]){
            int xt;
            int yt;

            xt = x + 15;
            yt = y - 2;

            ofFill();
            ofSetColor(0x029807);
            ofCircle(x,y,5);

            ofPushStyle();
            ofSetLineWidth(2);
            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,5);
            ofPopStyle();

            ofSetColor(0xffffff);
            ofDrawBitmapString(str,xt,yt);
        }
        //--------------------------
        void mlBulletBlue(int x, int y, char str[20]){
            int xt;
            int yt;

            xt = x + 15;
            yt = y - 2;

            ofFill();
            ofSetColor(0x094353);
            ofCircle(x,y,5);

            ofPushStyle();
            ofSetLineWidth(2);
            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,5);
            ofPopStyle();

            ofSetColor(0xffffff);
            ofDrawBitmapString(str,xt,yt);
        }
        //--------------------------
        void dataFloat(int x, int y, float data){
            char str[20];
            y = y+4;

            sprintf(str,"%f",data);

            ofSetColor(0xffffff);
            ofDrawBitmapString(str,x,y);
        }
        //--------------------------
};

#endif
