#include "page8.hpp"
#include "ofApp.h"

extern int pointerX;
extern int pointerY;
extern int pageTurn;

int stringAlpha = 255;

bool drawBubble = false;

void page8::setup(){
    w = ofGetWidth();
    h = ofGetHeight();
    
    cloud.load("cloud.jpg");
    castle.load("castle.gif");
    bubble.load("bubble.png");
    myFont.load("OCRAStd", 15);
    
}

void page8::update() {
    
    
}


void page8::draw() {
    x = ofGetMouseX();
    y = ofGetMouseY();
    
    ofSetColor(255, 255, 255);
    cloud.draw(0, 0, w, h-300);
    
    ofSetColor(206, 236, 154);
    ofDrawRectangle(0, 450, w, 600);
    ofSetColor(200, 220, 151);
    ofDrawRectangle(0, 700, w, 200);
    
    ofSetColor(0, 0, 0, stringAlpha);
    myFont.drawString("The sky seems to be getting brighter. Must mean we're gettting close.", 50, 50);
    myFont.drawString("What's this castle? Try going inside.", 50, 100);
    
    ofSetColor(255, 255, 255);
    castle.draw(w/2-248, 100);
    
    if(pointerX >= 315 && pointerX <= 700 && pointerY >= 220 && pointerY <= 480){
        stringAlpha = 0;
        drawBubble = true;
    }
    
    if(x >= 315 && x <= 700 && y >= 220 && y <= 480){
        stringAlpha = 0;
        drawBubble = true;
    }
    
    if (drawBubble == true){
        bubble.draw(100, 100);
        ofSetColor(0, 0, 0);
        myFont.drawString("hhheeeeeEEEEeelLLPPPppp MmeeEE!!!!!!!", 125, 150);
        myFont.load("OCRAStd", 30);
        myFont.drawString("IS THAT OUR STAR???", w/2 - 250, 600);
        myFont.load("OCRAStd", 15);
        myFont.drawString("Y/N", w/2, 630);
        myFont.load("OCRAStd", 8);
        myFont.drawString("press 'y' to go into castle", w/2 - 90, 650);
        myFont.load("OCRAStd", 15);
    }

    ofSetColor(0, 51, 102, 15);
    ofDrawRectangle(0, 0, w, h);
}

void page8::keyPressed(int key) {
    switch (key){
        case 'y':
            pageTurn ++;
            break;
    }
}