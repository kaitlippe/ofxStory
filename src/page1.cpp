#include "page1.hpp"
#include "ofApp.h"

int nextString = 0;


extern int pointerX;
extern int pointerY;
extern int pageTurn;

void page1::setup() {
    w = ofGetWidth();
    h = ofGetHeight();
    
    star.load("star.jpg");
    myFont.load("OCRAStd", 20);

}


void page1::update() {

}


void page1::draw() {
    x = ofGetMouseX();
    y = ofGetMouseY();
    
    ofSetColor(255, 255, 255);
    star.draw(0, 0, w, h);
    
    
    ofSetColor(255, 255, 255);
    myFont.drawString("Your world's brightest star has gone missing...", 50, 100);
    myFont.drawString("hover HERE to continue", 550, 700);
    
    ofSetColor(255, 255, 255);
    myFont.drawString("You must help find where the star has gone...", 50, 200);
    myFont.drawString("Your world is depending on you so don't mess up.", 50, 300);

    myFont.load("OCRAStd", 40);
    myFont.drawString("Good luck!", w/2 - 200, 400);
    
    myFont.load("OCRAStd", 10);
    myFont.drawString("*DISCLAIMER: if icon too glitchy, use mouse instead", 20, h - 25);
    myFont.load("OCRAStd", 20);
    
    if (pointerX >= 560 && pointerY >= 700){
        ofSetColor(93, 188, 210);
        myFont.drawString("hover HERE to continue", 550, 700);
        pageTurn++;
    }
    
    if (x >= 560 && y >= 700){
        ofSetColor(93, 188, 210);
        myFont.drawString("hover HERE to continue", 550, 700);
        pageTurn++;
    }
    
}


void page1::keyPressed(int key) {

}
