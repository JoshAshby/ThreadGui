#include "testApp.h"
#include "stdio.h"

/*
BOB-GUI
2009 - Joshua Ashby
joshuaashby@joshashby.com
http://joshashby.com
*/

bool locked = false;
int serialdata;
int ludata;
int rudata;

//--------------------------------------------------------------
void testApp::setup(){
	TO.start();
	ST.start();
	ofSetWindowTitle("BOB-GUI");
}
//--------------------------------------------------------------
void testApp::update(){
	ofBackground(0,0,0);
	/*
	serialdata = bytesReturned[0];
	ludata = bytesReturned[1];
	rudata = bytesReturned[2];
	printf("got: %s\n", bytesReturned);
	*/
}
//--------------------------------------------------------------
void testApp::draw(){
    TO.rectButton(350,80,"Connect",5);
    TO.roundButtonGreen(0,0,40,"",4);
    //draw a label
	TO.label(20,45,"Movement");
	//draw a few buttons
	TO.roundButton(75,100,20,"<",0);
	TO.roundButtonGrey(125,100,20,"V",1);
	TO.roundButton(175,100,20,">",2);
	TO.roundButtonGrey(125,50,20,"^",3);

	TO.label(500,45,"Data");
	TO.lineGrey(520,70,520,350,5);

	TO.bulletBlue(400,90,"Serial");
	TO.dataFloat(550,90,serialdata);
	TO.lineBlue(420,105,620,105,2);

	TO.mlBulletBlue(400,120,"Left\nUltrasound");
	TO.dataFloat(550,120,ludata);
	TO.lineBlue(420,135,620,135,2);

	TO.mlBulletBlue(400,150,"Right\nUnltrasound");
	TO.dataFloat(550,150,rudata);
	TO.lineBlue(420,165,620,165,2);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'a'){
        TO.click(0);
    }
    if  (key == 's'){
        TO.click(1);
    }
    if (key == 'd'){
        TO.click(2);
    }
    if  (key == 'w'){
        TO.click(3);
    }
}
//---------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == 'a'){
        TO.click(0);
    }
    if  (key == 's'){
        TO.click(1);
    }
    if (key == 'd'){
        TO.click(2);
    }
    if  (key == 'w'){
        TO.click(3);
    }
}
//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //send the (x,y) to the gui thread to see if you clicked on a button
    TO.click(x,y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    TO.click(x,y);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

