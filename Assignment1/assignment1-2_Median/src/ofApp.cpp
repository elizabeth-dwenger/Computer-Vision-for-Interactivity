#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    imgLena.load("Lena.jpg");
    matLena = toCv(imgLena);

    imgCircuit.load("circuit.tif");
    matCircuit = toCv(imgCircuit);
    
    LenaWidth = imgLena.getWidth();
    LenaHeight = imgLena.getHeight();
    
    CircuitWidth = imgCircuit.getWidth();
    CircuitHeight = imgCircuit.getHeight();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
//    imgLena.draw(0, 0);
//    cv::medianBlur(matLena, matFilterLena, 3);
//    drawMat(matFilterLena, LenaWidth, 0);
//
//    cv::medianBlur(matLena, matFilterLena, 5);
//    drawMat(matFilterLena, LenaWidth * 2, 0);
//
//    cv::medianBlur(matLena, matFilterLena, 7);
//    drawMat(matFilterLena, 0, LenaHeight);
//
//    cv::medianBlur(matLena, matFilterLena, 9);
//    drawMat(matFilterLena, LenaWidth, LenaHeight);
//
//    cv::medianBlur(matLena, matFilterLena, 11);
//    drawMat(matFilterLena, LenaWidth * 2, LenaHeight);
    

    
    imgCircuit.draw(0, 0);
    cv::medianBlur(matCircuit, matFilterCircuit, 3);
    drawMat(matFilterCircuit, CircuitWidth, 0);

    cv::medianBlur(matCircuit, matFilterCircuit, 5);
    drawMat(matFilterCircuit, CircuitWidth * 2, 0);

    cv::medianBlur(matCircuit, matFilterCircuit, 7);
    drawMat(matFilterCircuit, 0, CircuitHeight);

    cv::medianBlur(matCircuit, matFilterCircuit, 9);
    drawMat(matFilterCircuit, CircuitWidth, CircuitHeight);

    cv::medianBlur(matCircuit, matFilterCircuit, 11);
    drawMat(matFilterCircuit, CircuitWidth * 2, CircuitHeight);
    
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
