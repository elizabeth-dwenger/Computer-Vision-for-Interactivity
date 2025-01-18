#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    im.load("football.jpg");
    im.setImageType(OF_IMAGE_COLOR);
    mat = toCv(im);
    split(mat, rgb);
    
    for(int i = 0; i < mat.rows * mat.cols; i++){
        if(mat.data[i*3]>150 &&
           mat.data[i*3+1]<40 &&
           mat.data[i*3+2]<40){
            mat.data[i*3] = 255-mat.data[i*3];
            mat.data[i*3+1] = 255-mat.data[i*3+1];
            mat.data[i*3+2] = 255-mat.data[i*3+2];
        }
    }
    
    for(int x = 0; x < mat.cols; x++){
        for(int y = 0; y < mat.rows; y++){
            if(mat.data[(x+y*mat.cols)*3]>200 &&
               mat.data[(x+y*mat.cols)*3+1]>200 &&
               mat.data[(x+y*mat.cols)*3+2]>200){
                mat.data[(x+y*mat.cols)*3] = 255-mat.data[(x+y*mat.cols)*3];
                mat.data[(x+y*mat.cols)*3+1] = 255-mat.data[(x+y*mat.cols)*3+1];
                mat.data[(x+y*mat.cols)*3+2] = 255-mat.data[(x+y*mat.cols)*3+2];
            }

        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    drawMat(rgb[0],0,0);
    drawMat(rgb[1],im.getWidth(),0);
    drawMat(rgb[2],im.getWidth()*2,0);
    drawMat(mat,im.getWidth()*3,0);
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
