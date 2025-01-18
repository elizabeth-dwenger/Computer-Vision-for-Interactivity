#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    im.load("noise.jpg");
    im.setImageType(OF_IMAGE_GRAYSCALE);
    mat = toCv(im);
    
    
    //box filter
    //method 1: define your own kernel
    float kernelData[] ={
        1,1,1,
        1,1,1,
        1,1,1
    };
    
    boxKernel = Mat(boxKernelSize, boxKernelSize, CV_32F, kernelData);
    
    boxKernel /= sum(boxKernel)[0];
    
    filter2D(mat, boxResult, -1, boxKernel);
    
    //method 2: directly call built-in function
    //boxFilter(mat, result, -1, cv::Size(kernelSize, kernelSize));
    
    
    //Gaussian Filter
    //method 1
    gaussianKernel = getGaussianKernel(gaussianKernelSize, 5);
    sepFilter2D(mat, gaussianResult, -1, gaussianKernel, gaussianKernel);
    
    //method 2
    //GaussianBlur(mat, gaussianResult, cv::Size(kernel, kernel), 5);
    
    //Median Filter
    medianBlur(mat, medianResult, medianKernelSize);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    drawMat(mat, 0, 0);
    drawMat(boxResult, im.getWidth(),0);
    drawMat(gaussianResult, im.getWidth()*2,0);
    drawMat(medianResult, im.getWidth()*3,0);
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
