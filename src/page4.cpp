#include "ofApp.h"

extern int pointerX;
extern int pointerY;
extern int pageTurn;

bool coin = false;

int arrow;

void page4::setup() {
    w = ofGetWidth();
    h = ofGetHeight();
    
    cloud.load("cloud.jpg");
    treasure2.load("treasure2.tiff");
    gold1.load("gold1.tiff");
    gold2.load("gold2.tiff");
    myFont.load("OCRAStd", 15);
}

void page4::update() {
    
}

void page4::draw() {
    x = ofGetMouseX();
    y = ofGetMouseY();
    
    ofSetColor(255, 255, 255);
    cloud.draw(0, 0, w, h-300);
    
    ofSetColor(206, 236, 154);
    ofDrawRectangle(0, 450, w, 600);
    ofSetColor(200, 220, 151);
    ofDrawRectangle(0, 700, w, 200);
    
    ofSetColor(255, 255, 255);
    treasure2.draw(w/2, h/2);
    
    
    ofSetColor(255, 255, 255);
    if (coin == false) {
        gold1.draw(w/2-80, h/2+134, 250, 95.5);
        coin = true;
    } else if (coin == true){
        gold2.draw(w/2-80, h/2+134, 250, 95.5);
        coin = false;
    }
    
    ofSetColor(0, 51, 102, 70);
    ofDrawRectangle(0, 0, w, h);
    
    ofSetColor(0, 0, 0);
    myFont.drawString("You opened the treasure chest...", 100, 100);
    myFont.drawString("But only a pile of gold coins were in there.", 100, 150);
    myFont.drawString("To bad, we'll just have to keep searching!", 100, 200);
    
    myFont.load("OCRAStd", 25);
    if (arrow <= 0) {
        arrow += 10;
        myFont.drawString("-->", w-(90-arrow), h-27);
    } else if (arrow >= 10 ){
        arrow -= 10;
        myFont.drawString("-->", w-(100-arrow), h-27);
    }
    myFont.load("OCRAStd", 15);

    
    if (pointerX >= (w-150) && pointerX <= w && pointerY >= (h-50) && pointerY <= h) {
        pageTurn++;
    }
    if (x >= (w-150) && x <= w && y >= (h-50) && y <= h) {
        pageTurn++;
    }
    
    
}