#include "page7.hpp"
#include "ofApp.h"

extern int pointerX;
extern int pointerY;
extern int pageTurn;

int string1Alpha = 255;
int drawString1;

int arrow2;

void page7::setup(){
    w = ofGetWidth();
    h = ofGetHeight();
    sunflower.load("sunflower.gif");
    cloud.load("cloud.jpg");
    sparkle.load("sparkle.gif");
    myFont.load("OCRAStd", 15);
    
}

void page7::update() {
    
    
}


void page7::draw() {
    x = ofGetMouseX();
    y = ofGetMouseY();
    
    ofSetColor(255, 255, 255);
    cloud.draw(0, 0, w, h-300);
    
    ofSetColor(206, 236, 154);
    ofDrawRectangle(0, 450, w, 600);
    ofSetColor(200, 220, 151);
    ofDrawRectangle(0, 700, w, 200);
    
    ofSetColor(255, 255, 255);
    sunflower.draw(100, 400, 104, 174);
    sunflower.draw(150, 520, 104, 174);
    sunflower.draw(200, 450, 104, 174);
    sunflower.draw(320, 430, 104, 174);
    sunflower.draw(440, 550, 104, 174);
    sunflower.draw(500, 420, 104, 174);
    sunflower.draw(630, 500, 104, 174);
    sunflower.draw(700, 450, 104, 174);
    sunflower.draw(750, 520, 104, 174);
    sunflower.draw(800, 460, 104, 174);
    
    ofSetColor(0, 0, 0, string1Alpha);
    myFont.drawString("Welcome to sunflower country", 100, 50);
    myFont.drawString("Try searching the flowers for a hint", 100, 100);
    
    if(pointerX >= 630 && pointerX <= 730 && pointerY >= 500 && pointerX <= 670) {
        string1Alpha = 0;
        drawString1 = true;
    }
    if(x >= 630 && x <= 730 && y >= 500 && y <= 670) {
        string1Alpha = 0;
        drawString1 = true;
    }

    
    if(drawString1 == true) {
        ofSetColor(0, 0, 0);
        myFont.drawString("You found something!!", w/2 - 200, 50);
        myFont.drawString("Its star dust! Must mean you're close", w/2-250, 100);
        ofSetColor(255, 255, 255);
        sparkle.draw(300, 200, 250, 203);
        sparkle.draw(400, 175, 250, 203);
        
        ofSetColor(0, 0, 0);
        if (arrow2 <= 0) {
            arrow2 += 10;
            myFont.drawString("-->", w-(90-arrow2), h-27);
        } else if (arrow2 >= 10 ){
            arrow2 -= 10;
            myFont.drawString("-->", w-(100-arrow2), h-27);
        }
        if (pointerX >= (w-150) && pointerX <= w && pointerY >= (h-50) && pointerY <= h) {
            pageTurn++;
        }
        if (x >= (w-150) && x <= w && y >= (h-50) && y <= h) {
            pageTurn++;
        }
    }
    
    
    ofSetColor(0, 51, 102, 30);
    ofDrawRectangle(0, 0, w, h);

    
}