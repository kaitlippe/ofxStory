#include "page3.hpp"
#include "ofApp.h"

extern int pointerX;
extern int pointerY;
extern int pageTurn;


void page3::setup() {
    w = ofGetWidth();
    h = ofGetHeight();
    
    cloud.load("cloud.jpg");
    treasure.load("treasure1.tiff");
    myFont.load("OCRAStd", 15);
    
}


void page3::update() {
    
    
}


void page3::draw() {
    x = ofGetMouseX();
    y = ofGetMouseY();
    
    ofSetColor(255, 255, 255);
    cloud.draw(0, 0, w, h-300);
    
    
    ofSetColor(206, 236, 154);
    ofDrawRectangle(0, 450, w, 600);
    ofSetColor(200, 220, 151);
    ofDrawRectangle(0, 700, w, 200);
    
    ofSetColor(255, 255, 255);
    treasure.draw(w/2, h/2);
    
    ofSetColor(0, 51, 102, 70);
    ofDrawRectangle(0, 0, w, h);
    
    ofSetColor(0, 0, 0);
    myFont.drawString("Oh, look at that!", 100, 100);
    myFont.drawString("Maybe our lost star is hidden in the treasure chest...", 100, 150);
    myFont.drawString("Try hovering over to unlock it.", 100, 200);
    
    if (pointerX >= 570 && pointerX <= 750 && pointerY >= 430 && pointerY <= 600) {
        pageTurn++;
    }
    if (x >= 570 && x <= 750 && y >= 430 && y <= 600) {
        pageTurn++;
    }
    
    
}

