#include "ofApp.h"
#include <iostream>
#include <stdio.h>

float w;
float h;

int pageTurn = 0;

int vidX = 450;
int vidY = 375;

int pointerX = 0;
int pointerY = 0;



page1 myPage1;
page2 myPage2;
page3 myPage3;
page4 myPage4;
page5 myPage5;
page6 myPage6;
page7 myPage7;
page8 myPage8;
page9 myPage9;

ofImage myChar;

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    w = ofGetWidth();
    h = ofGetHeight();
    
    myChar.load("char.png");
    
    myFont.load("OCRAStd", 15);
    cloud.load("cloud.jpg");
    
    vidGrabber.setVerbose(true);
    vidGrabber.setup(vidX,vidY);
    grayDiff.allocate(vidX,vidY);
    
    bLearnBakground = true;
    threshold = 13;
    
    myPage1.setup();
    myPage2.setup();
    myPage3.setup();
    myPage4.setup();
    myPage5.setup();
    myPage6.setup();
    myPage7.setup();
    myPage8.setup();
    myPage9.setup();
    

}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100,100,100);
    bool bNewFrame = false;
    
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    if (bNewFrame){
        colorImg.setFromPixels(vidGrabber.getPixels());
        grayImage = colorImg;
        if (bLearnBakground == true){
            grayBg = grayImage;
            bLearnBakground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(threshold);
        
        contourFinder.findContours(grayDiff, 20, (vidX*vidY)/3, 5, false);
    }
    
    myPage1.update();
    myPage2.update();
    myPage3.update();
    myPage4.update();
    myPage5.update();
    myPage6.update();
    myPage7.update();
    myPage8.update();
    myPage9.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (contourFinder.nBlobs > 0) {  // if any detected  TODO: go w largest
        pointerX = ofMap(contourFinder.blobs[0].boundingRect.x, vidX, 0, 0, ofGetWidth(), true);
        pointerY = ofMap(contourFinder.blobs[0].boundingRect.y, 0, vidY, 0, ofGetHeight(), true);
    }
    
    if (pageTurn == 0) {
        cloud.draw(0, 0, w, h);
        
        grayDiff.draw(w/2-500, 200);
        ofFill();
        ofSetHexColor(0xffffff);
        ofDrawRectangle(w/2+50, 200,vidX,vidY);
        ofSetHexColor(0xffffff);
        contourFinder.draw(w/2+50, 200);
        
        ofSetColor(0, 0, 0);
        myFont.drawString("Set up your contour !", w/2-150, 100);
        myFont.load("OCRAStd", 8);
        myFont.drawString("use SPACE to capture", w/2- 100, 130);
        myFont.drawString("use -/+ for threshold", w/2-105, 150);
        myFont.drawString("press 'z' to continue", w/2-105, 170);
        myFont.load("OCRAStd", 15);
    } else if (pageTurn == 1) {
        myPage1.draw();
    } else if (pageTurn == 2) {
        myPage2.draw();
    } else if (pageTurn == 3) {
        myPage3.draw();
    } else if (pageTurn == 4) {
        myPage4.draw();
    } else if (pageTurn == 5){
        myPage5.draw();
    } else if (pageTurn == 6){
        myPage6.draw();
    } else if (pageTurn == 7){
        myPage7.draw();
    } else if (pageTurn == 8){
        myPage8.draw();
    } else if (pageTurn == 9){
        myPage9.draw();
    }
    

    ofSetColor(255, 255, 255);
    myChar.draw(pointerX, pointerY, 150, 112.5);
    
    if (pageTurn > 9) {
        pageTurn == 0;
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
        case ' ':
            bLearnBakground = true;
            break;
        case '+':
            threshold ++;
            if (threshold > 255) threshold = 255;
            break;
        case '-':
            threshold --;
            if (threshold < 0) threshold = 0;
            break;
        case 'z':
            pageTurn++;
            printf("\n KEY PRESSED %d \n", pageTurn);
            break;
    }
    
    if (pageTurn == 1){
        myPage1.keyPressed(key);
    } else if (pageTurn == 2) {
        myPage2.keyPressed(key);
    } else if (pageTurn == 5){
        myPage5.keyPressed(key);
    } else if (pageTurn == 8){
        myPage8.keyPressed(key);
    } else if (pageTurn == 9){
        myPage9.keyPressed(key);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
