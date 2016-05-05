#include "page6.hpp"
#include "ofApp.h"

extern int pointerX;
extern int pointerY;
extern int pageTurn;

int gemMove;
bool highGem;

int gemCount = 0;

float a1 = 255;
float a2 = 255;
float a3 = 255;
float a4 = 255;
float a5 = 255;

int cont = 255;

void page6::setup(){
    w = ofGetWidth();
    h = ofGetHeight();
    
    cloud.load("cloud.jpg");
    myFont.load("OCRAStd", 15);
    
    gem1.load("gem1.gif");
    gem2.load("gem2.gif");
    gem3.load("gem3.gif");
    gem4.load("gem4.gif");

}

void page6::update() {
    if (cont <= 0) {
        cont += 255;
    } else if (cont >= 255){
        cont -= 255;
    }
}


void page6::draw() {
    x = ofGetMouseX();
    y = ofGetMouseY();
    
    ofSetColor(255, 255, 255);
    cloud.draw(0, 0, w, h-300);
    ofSetColor(206, 236, 154);
    ofDrawRectangle(0, 450, w, 600);
    ofSetColor(200, 220, 151);
    ofDrawRectangle(0, 700, w, 200);
    
    
    ofSetColor(255, 255, 255, a1);
    gem1.draw(100, 255);
    ofSetColor(255, 255, 255, a2);
    gem2.draw(300, 305);
    ofSetColor(255, 255, 255, a3);
    gem3.draw(500, 175);
    ofSetColor(255, 255, 255, a4);
    gem4.draw(700, 205);
    ofSetColor(255, 255, 255, a5);
    gem2.draw(900, 325);
    
    //ghost covers
    if (100 >= pointerX && pointerX <= 160 && 260 >= pointerY && pointerY <= 320) {
        a1 = 0;
    }
    if (300 >= pointerX && pointerX <= 360 && 310 >= pointerY && pointerY <= 370) {
        a2 = 0;
    }
    if (500 >= pointerX && pointerX <= 560 && 180 >= pointerY && pointerY <= 240) {
        a3 = 0;
    }
    if (700 >= pointerX && pointerX <= 760 && 215 >= pointerY && pointerY <= 270) {
        a4 = 0;
    }
    if (900 >= pointerX && pointerX <= 960 && 330 >= pointerY && pointerY <= 390) {
        a5 = 0;
    }
    
    //mouse hovers
//    if (100 >= x && x <= 160 && 260 >= y && y <= 320) {
//        if (a1 > 0) {
//            gemCount++;
//        }
//        a1 = 0;
//    }
//    if (300 >= x && x <= 360 && 310 >= y && y <= 370) {
//        if (a2 > 0) {
//            gemCount++;
//        }
//        a2 = 0;
//    }
//    if (500 >= x && x <= 560 && 180 >= y && y <= 240) {
//        if (a3 > 0) {
//            gemCount++;
//        }
//        a3 = 0;
//    }
//    if (700 >= x && x <= 760 && 215 >= y && y <= 270) {
//        if (a4 > 0) {
//            gemCount++;
//        }
//        a4 = 0;
//    }
//    if (900 >= x && x <= 960 && 330 >= y && y <= 390) {
//        if (a5 > 0) {
//            gemCount++;
//        }
//        a5 = 0;
//    }
    
    ofSetColor(0, 51, 102, 45);
    ofDrawRectangle(0, 0, w, h);
    
    ofSetColor(0, 0, 0);
    myFont.drawString("Collect the gems to help your searching abilities.", w/2-350, 100);
    myFont.load("OCRAStd", 15);
    
    if (a1==0 && a2==0 && a3==0 && a4==0 && a5==0){
        myFont.drawString("Congrats!! You collected all the gems.", w/2 -250, 300);
        
        myFont.load("OCRAStd", 30);
        ofSetColor(0, 0, 0, cont);
        myFont.drawString("Move On", w/2-100, h/2);
        myFont.load("OCRAStd", 15);
        myFont.drawString("press 'z'", w/2-50, h/2 + 60);

    }
    
}


void page6::keyPressed(int key) {
    switch (key){
        case 'z':
            pageTurn ++;
            break;
    }
}