#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxGui.h"
#include "ofFbo.h"



using namespace cv;
using namespace ofxCv;

class ofApp : public ofBaseApp{

    public:
    
    ofxPanel gui;

    ofxFloatSlider brushSize;
    
    void paint(int posX, int posY);
    void togglePainting();
    bool isPainting = false;
    void Background();
    void toggleisBackground();
    bool isBackground = false;
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
    

        //ofxFloatSlider radius;
    
    
        ofImage imgBg;
        ofImage imgMan;
        Mat matBg;
        Mat matMan;
    
        ofFbo maskFbo;
        ofFbo fbo;
    ofShader shader;
};
