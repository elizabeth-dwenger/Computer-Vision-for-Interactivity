#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(noiseLevel.setup("Noise Level", 0.25, 0, 0.5));
    
    imgWhite.load("lena.png");
    imgWhite.setImageType(OF_IMAGE_GRAYSCALE);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    matWhite = toCv(imgWhite);
    
    matWhite.convertTo(matWhite, CV_64F);
    
    matWhite /= 255.0f;//convert the image matrix to the range of 0 to 1
    
    noise = Mat(matWhite.size(), CV_64F);
    //
    randn(noise, 0, (double)noiseLevel);
    //
    matWhite = matWhite + noise;
    
    matWhite.convertTo(matWhite, CV_8UC1, 255, 0); //conver the image matrix back to 8-bit (0 to 255)
}

//--------------------------------------------------------------
void ofApp::draw(){
    imgWhite.draw(0,0);
    drawMat(matWhite, imgWhite.getWidth(), 0);
    gui.draw();
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
