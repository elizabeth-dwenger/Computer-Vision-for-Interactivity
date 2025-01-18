#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    imgBg.load("bg.jpg");
    imgMan.load("running.jpg");
    matBg = toCv(imgBg);
    matMan = toCv(imgMan);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int rows = 0; rows < matMan.rows; rows++){
        for (int columns = 0; columns < matMan.cols; columns++){
            bool Background =
                matMan.at<Vec3b>(rows, columns)[0] <= 125 &&
                matMan.at<Vec3b>(rows, columns)[1] >= 105 &&
                matMan.at<Vec3b>(rows, columns)[2] <= 125;
            if (!Background) {
                matBg.at<Vec3b>(rows, columns) = matMan.at<Vec3b>(rows, columns);
            }
        }
    }
    drawMat(matBg, 0, 0);
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
