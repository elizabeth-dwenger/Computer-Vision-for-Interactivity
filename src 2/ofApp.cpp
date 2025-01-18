#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    imgLena.load("lena.png");
    imgLena.setImageType(OF_IMAGE_GRAYSCALE);
    
    matLena = toCv(imgLena);
    
    
    ////calculating the histogram for drawing////////
    int histSize = 256;
    float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange = { range };
    
    calcHist(&matLena, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    
    normalize(hist, hist, 0, 400, NORM_MINMAX);
    
    for(int i = 0; i < histSize; i++){
        histCols[i].clear();
        histCols[i].addVertex(i+10, 768);
        histCols[i].addVertex(i+10, 768-cvRound(hist.at<float>(i)));
    }
    //////////////////////////////////////////////////
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255);
    ofSetColor(255);
    drawMat(matLena, 0, 0);
    ofSetColor(0, 0, 0);
    for(int i = 0; i < 256; i++){
        histCols[i].draw();
    }
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
