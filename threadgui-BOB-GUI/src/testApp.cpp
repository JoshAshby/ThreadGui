#include "testApp.h"
#include "stdio.h"

/*
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

text - white
*/

bool locked = false;
float serialdata;
float ludata;
float rudata;

//--------------------------------------------------------------
void testApp::setup(){
	TO.start();
	ofSetWindowTitle("Threadgui Example");
	serialdata = 1002;
    ludata = 45;
    rudata = 69;
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(0,0,0);
}

//--------------------------------------------------------------
void testApp::draw(){
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
