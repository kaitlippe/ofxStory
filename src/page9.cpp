#include "page9.hpp"
#include "ofApp.h"

extern int pointerX;
extern int pointerY;
extern int pageTurn;


ofSerial serial;


int bubbleAlpha = 255;
int bubble2Alpha = 255;
int bubble3Alpha = 255;

void page9::setup(){
    serial.setup("/dev/cu.uasbmodem14421", 9600);
    

    w = ofGetWidth();
    h = ofGetHeight();
    
    cloud.load("cloud.jpg");
    dungeon.load("dungeon.png");
    star.load("star.png");
    cup.load("cup.png");
    bubble.load("bubble.png");
    bubble2.load("bubble2.png");
    myFont.load("OCRAStd", 15);
    
}

void page9::update() {
    serial.writeByte('a');

    
}


void page9::draw() {
    

    
    x = ofGetMouseX();
    y = ofGetMouseY();
    
    ofSetColor(255, 255, 255);
    dungeon.draw(0, -300, w + 300, h + 300);
    star.draw(620, 500, 232, 220);
    cup.draw(600, 680, 50, 50);
    

    if (bubbleAlpha == 255) {
        ofSetColor(255, 255, 255, bubbleAlpha);
        bubble.draw(300, 400);
        ofSetColor(0, 0, 0, bubbleAlpha);
        myFont.drawString("Oh, hello. What are you doing here???", 175, 450);
        myFont.drawString("v", 830, 460);
        if (x >= 820 && x <= 855 && x >= 450 && y <= 465) {
            bubbleAlpha = 0;
        }
    }
    
    if ( bubbleAlpha == 0) {
        ofSetColor(255, 255, 255, bubble2Alpha);
        bubble.draw(200, 400, 700, 150);
        ofSetColor(0, 0, 0, bubble2Alpha);
        myFont.drawString("You were searching for me? What for?", 250, 450);
        myFont.drawString("I've just been here on holiday.", 250, 480);
        myFont.drawString("v", 870, 490);
        if (x >= 865 && x <= 890 && x >= 485 && y <= 505) {
            bubble2Alpha = 0;
        }

    }
    if ( bubble2Alpha == 0) {
        ofSetColor(255, 255, 255, bubble3Alpha);
        bubble.draw(200, 400, 700, 150);
        ofSetColor(0, 0, 0, bubble3Alpha);
        myFont.drawString("Why was a screaming you ask???", 250, 450);
        myFont.drawString("I dropped my coffee of course!!!!!!", 250, 480);
        myFont.drawString("v", 870, 490);
        if (x >= 865 && x <= 890 && x >= 485 && y <= 505) {
            bubble3Alpha = 0;
        }
    }
    if ( bubble3Alpha == 0) {
        ofSetColor(255, 255, 255);
        bubble.draw(200, 400, 700, 150);
        ofSetColor(0, 0, 0);
        myFont.drawString("You thought I was kidnapped?!!", 250, 450);
        myFont.drawString("Well I am very much safe, so you can go home!", 250, 480);
        ofSetColor(255, 255, 255);
        myFont.load("OCRAStd", 30);
        myFont.drawString("Go home?", w/2-100, 100);
        myFont.drawString("Y/N", w/2-30, 150);
        myFont.load("OCRAStd", 15);
    }
    
}

void page9::keyPressed(int key) {
    switch (key){
        case 'y':
            pageTurn++;
            break;
    }
}