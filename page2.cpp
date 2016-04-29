#include "ofApp.h"

bool moveOn = false;
bool sphereGrowBool = false;
int sphereGrow = 0;

extern int pointerX;
extern int pointerY;
extern int pageTurn;

void page2::setup() {
    w = ofGetWidth();
    h = ofGetHeight();
    
    star.load("star.jpg");
    myFont.load("OCRAStd", 15);
    
    sphere.setRadius(200);
    ofSetSphereResolution(30);
}

void page2::update() {
//    if (sphereGrowBool == true && sphereGrow <= 10) {
//        sphereGrow += 10;
//    } else if (sphereGrowBool == true && sphereGrow > 0) {
//        sphereGrow -= 10;
//    }
//    sphere.setRadius(200 + sphereGrow);

    
}

void page2::draw() {
    x = ofGetMouseX();
    y = ofGetMouseY();
    
    ofSetColor(255, 255, 255);
    star.draw(0, 0, w, h);

    ofSetColor(255, 255, 204, 150);
    float spinX = sin(ofGetElapsedTimef()*.5f);
    float spinY = cos(ofGetElapsedTimef()*.5f);
    
    sphere.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);
    sphere.draw();


    if (pointerX >= 340 && pointerX <= 675 && pointerY >= 210 && pointerY <= 540 ) {
            pageTurn++;
    }
    if (x >= 340 && x <= 675 && y >= 210 && y <= 540 ) {
        pageTurn++;
    }
    
    ofSetColor(255, 255, 255);
    myFont.drawString("Hover over world to enter your adventure...", w/2 - 300, 100);
}


void page2::keyPressed(int key) {
    switch (key){
        case 'a':
            moveOn = true;
            break;
    }
}