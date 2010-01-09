#include "buttons.h"
#include <iostream>
#include <vector>
#include <string>

/*
Threadgui
2009 - Joshua Ashby
joshuaashby@joshashby.com
http://joshashby.com
*/

button::button()
{
        test = 0;
}
//------------------------
void button::roundButton(int x, int y, char srt[15], int color){
    int h;
    //thread stuff
    if( lock() ){
        unlock();
    }else{
		printf("can't lock!\neither an error\nor the thread has stopped");
	}
            h = strlen(srt)*8+20;
            ofSetColor(0x094353);
          ofFill();
          ofCircle(x,y,h);
          ofNoFill();
          ofSetColor(0xffffff);
          ofCircle(x,y,h);
}
//--------------------------
void button::rectButton(int x, int y, char srt[15], int color){

}
//--------------------------
void button::click(int x, int y){
    //thread stuff
    if( lock() ){
        unlock();
    }else{
		printf("can't lock!\neither an error\nor the thread has stopped");
	}
}
//---------------------------
void button::click(int color){
    //thread stuff
    if( lock() ){
        unlock();
    }else{
		printf("can't lock!\neither an error\nor the thread has stopped");
	}
}
