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
    cv::GaussianBlur(matLena, matFilterLena, cv::Size(3, 3), 4,4);
    drawMat(matFilterLena, 0, 0);

    cv::GaussianBlur(matLena, matFilterLena, cv::Size(3, 3), 5,5);
    drawMat(matFilterLena, LenaWidth, 0);

    cv::GaussianBlur(matLena, matFilterLena, cv::Size(3, 3), 6,6);
    drawMat(matFilterLena, LenaWidth * 2, 0);

    cv::GaussianBlur(matLena, matFilterLena, cv::Size(3, 3), 7,7);
    drawMat(matFilterLena, 0, LenaHeight);

    cv::GaussianBlur(matLena, matFilterLena, cv::Size(3, 3), 8,8);
    drawMat(matFilterLena, LenaWidth, LenaHeight);

    cv::GaussianBlur(matLena, matFilterLena, cv::Size(3, 3), 9,9);
    drawMat(matFilterLena, LenaWidth * 2, LenaHeight);

    cv::GaussianBlur(matLena, matFilterLena, cv::Size(3, 3), 10,10);
    drawMat(matFilterLena, 0, LenaHeight * 2);
    

    
//    cv::GaussianBlur(matCircuit, matFilterCircuit, cv::Size(3, 3), 4,4);
//    drawMat(matFilterCircuit, 0, 0);
//
//    cv::GaussianBlur(matCircuit, matFilterCircuit, cv::Size(3, 3), 5,5);
//    drawMat(matFilterCircuit, CircuitWidth, 0);
//
//    cv::GaussianBlur(matCircuit, matFilterCircuit, cv::Size(3, 3), 6,6);
//    drawMat(matFilterCircuit, CircuitWidth * 2, 0);
//
//    cv::GaussianBlur(matCircuit, matFilterCircuit, cv::Size(3, 3), 7,7);
//    drawMat(matFilterCircuit, 0, CircuitHeight);
//
//    cv::GaussianBlur(matCircuit, matFilterCircuit, cv::Size(3, 3), 8,8);
//    drawMat(matFilterCircuit, CircuitWidth, CircuitHeight);
//
//    cv::GaussianBlur(matCircuit, matFilterCircuit, cv::Size(3, 3), 9,9);
//    drawMat(matFilterCircuit, CircuitWidth * 2, CircuitHeight);
//
//    cv::GaussianBlur(matCircuit, matFilterCircuit, cv::Size(3, 3), 10,10);
//    drawMat(matFilterCircuit, 0, CircuitHeight * 2);
    
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
