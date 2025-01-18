#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Enabling depth
    glEnable(GL_DEPTH_TEST);
    // Loading the background and stamp
    imgBg.load("flower.jpg");
    imgStamp.load("flower.jpg");
    
    // Create fbo and allows stamp to only work within background
    fbo.allocate(imgBg.getWidth(), imgBg.getHeight());
    
    // Enabling alpha for the erasure/making the background transparent
    imgStamp.setImageType(OF_IMAGE_COLOR_ALPHA);
    ofPixelsRef pixels = imgStamp.getPixels();
    
    // Erasing background which is green
    for (uint y = 0; y < imgStamp.getHeight(); y ++) {
        for (uint x = 0; x < imgStamp.getWidth(); x ++) {
            ofColor color = imgStamp.getColor(x, y);
            if (color.r <= 180 &&
                color.g >= 0 &&
                color.b <= 140) {
                pixels.setColor(x, y, ofColor(255, 0, 0, 0));
            }
        }
    }
    // Setting stamp (keyed) to be the image without background
    keyed.setFromPixels(pixels);
    
    // Clear graphics card
    fbo.begin();
        ofClear(255);
    fbo.end();

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    imgBg.draw(0, 0);
    // Show stamp ontop of background
    glDepthFunc(GL_ALWAYS);
    // Draw the stampped image at the center of the image where the mouse is
    keyed.draw(mouseX - 280, mouseY - 225);
    fbo.draw(0, 0);
    // Changing the depth test to the default (which is GL_LESS)
    glDepthFunc(GL_LESS);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    // If the mouse is clicked, the draw function will be called
    glDepthFunc(GL_LEQUAL);
    // Uses fbo in order to allow stamping while background being refreshed
    fbo.begin();
        // Stamp the image
        keyed.draw(x - 280, y - 225);
    fbo.end();
    glDepthFunc(GL_LESS);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
