#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

#define _USE_LIVE_VIDEO

class page1 {
public:
    float w;
    float h;
    float x;
    float y;
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    ofImage star;
    ofTrueTypeFont myFont;

};

class page2 {
public:
    float w;
    float h;
    float x;
    float y;
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    ofSpherePrimitive sphere;
    ofImage star;
    ofTrueTypeFont myFont;

};

class page3 {
public:
    float w;
    float h;
    float x;
    float y;
    void setup();
    void update();
    void draw();
    ofTrueTypeFont myFont;
    ofImage cloud;
    ofImage treasure;

};

class page4 {
public:
    float w;
    float h;
    float x;
    float y;
    void setup();
    void update();
    void draw();
    ofTrueTypeFont myFont;
    ofImage cloud;
    ofImage treasure2;
    ofImage gold1;
    ofImage gold2;
};

class page5 {
public:
    float w;
    float h;
    float x;
    float y;
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    ofTrueTypeFont myFont;
    ofImage pizzaKing;
    ofImage cloud;
    ofImage bubble;

    
};

class page6 {
public:
    float w;
    float h;
    float x;
    float y;
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    ofTrueTypeFont myFont;
    ofImage cloud;
    ofImage gem1;
    ofImage gem2;
    ofImage gem3;
    ofImage gem4;
    
};

class page7 {
public:
    float w;
    float h;
    float x;
    float y;
    void setup();
    void update();
    void draw();
    ofTrueTypeFont myFont;
    ofImage cloud;
    ofImage sunflower;
    ofImage sparkle;
    
};

class page8 {
public:
    float w;
    float h;
    float x;
    float y;
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    ofTrueTypeFont myFont;
    ofImage cloud;
    ofImage castle;
    ofImage bubble;
    
};

class page9 {
public:
    float w;
    float h;
    float x;
    float y;
    void setup();
    void update();
    void draw();
    ofTrueTypeFont myFont;
    ofImage cloud;
    ofImage dungeon;
    ofImage star;
    ofImage cup;
    ofImage bubble;
    ofImage bubble2;
    void keyPressed(int key);
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    
    ofTrueTypeFont myFont;
    ofImage cloud;
    
#ifdef _USE_LIVE_VIDEO
    ofVideoGrabber vidGrabber;
#else
    ofVideoPlayer vidPlayer;
#endif
    
    ofxCvColorImage	colorImg;
    
    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;
    
    ofxCvContourFinder contourFinder;
    
    int threshold;
    bool bLearnBakground;
    
        
};


