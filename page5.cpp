#include "ofApp.h"

extern int pointerX;
extern int pointerY;
extern int pageTurn;

float movePizza = 0;
int high;
int low;

extern ofImage myChar;

bool string2;

int string1A = 255;
int string2A = 255;

bool drawString;


void page5::setup() {
    w = ofGetWidth();
    h = ofGetHeight();
    pizzaKing.load("pizzaKing.png");
    cloud.load("cloud.jpg");
    bubble.load("bubble.png");
    myFont.load("OCRAStd", 15);
    
}


void page5::update() {
    
    if (movePizza <= 5) {
        movePizza += 5;
        high = true;
        low = false;
        ofSleepMillis(500);
    } else{
        movePizza -=5;
        low = true;
        high = false;
        ofSleepMillis(500);
    }
    
}


void page5::draw() {
    x = ofGetMouseX();
    y = ofGetMouseY();
    
    ofSetColor(255, 255, 255);
    
    cloud.draw(0, 0, w, h-300);
    
    ofSetColor(206, 236, 154);
    ofDrawRectangle(0, 450, w, 600);
    ofSetColor(200, 220, 151);
    ofDrawRectangle(0, 700, w, 200);
    ofSetColor(255, 255, 255);
    pizzaKing.draw(w/2, 150 + movePizza, 442.5, 360);
    
    if(low == true){
        ofSetColor(160, 176, 129, 70);
        ofDrawEllipse(w/2+200, 550, 220, 100);
    } else if (high == true) {
        ofSetColor(160, 176, 129, 70);
        ofDrawEllipse(w/2+200, 550, 230, 105);
    }
    
    ofSetColor(0, 51, 102, 60);
    ofDrawRectangle(0, 0, w, h);
    
    ofSetColor(0, 0, 0, string1A);
    myFont.drawString("Maybe Pizza King knows where our star has been taken", 100, 100);
    
    if (pointerX >= 600 && pointerX <= 930 && pointerY >= 190 && pointerY <= 480) {
        drawString = true;
        string1A = 0;
    }
    
    if (x >= 600 && x <= 930 && y >= 190 && y <= 480) {
        drawString = true;
        string1A = 0;
    }
    
    if (drawString== true) {
        ofSetColor(255, 255, 255);
        bubble.draw(70, 60, 930, 210);
        ofSetColor(0, 0, 0, string2A);
        myFont.drawString("Why would I know where your star went?", 100, 100);
        myFont.drawString("Maybe you should've keep better track of your stars next time.", 100, 150);
        myFont.drawString("Now leave me alone!!!", 100, 200);
        myFont.drawString("Leave Pizza King alone and move on?", 500, 680);
    }
    
    if (drawString==true && pointerX >= 500 && pointerY >= 680) {
        myFont.drawString("Y/N", 700, 720);
        myFont.load("OCRAStd", 8);
        myFont.drawString("press 'y'", 690, 730);
        myFont.load("OCRAStd", 15);
    }
    if (drawString==true && x >= 500 && y >= 680) {
        myFont.drawString("Y/N", 700, 720);
        myFont.load("OCRAStd", 8);
        myFont.drawString("press 'y'", 690, 730);
        myFont.load("OCRAStd", 15);
    }

}


void page5::keyPressed(int key) {
    switch(key){
            case 'y':
            pageTurn++;
            break;
            case 'n':
            myFont.drawString("Wrong choice", 650, 740);
            break;
    }
}
