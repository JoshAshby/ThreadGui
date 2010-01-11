#include "testApp.h"
#include "stdio.h"

bool locked = false;

//--------------------------------------------------------------
void testApp::setup(){
	TO.start();
	ofSetWindowTitle("Threadgui Circle");
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(0,0,0);
}

//--------------------------------------------------------------
void testApp::draw(){
	TO.draw(75,100,"hello",0x456456,0);
	TO.draw(75,200,"bye",0x456456,0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'a'){
        //TO.click(0);
    }
}
//---------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == 'a'){
        //TO.click(0);
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
