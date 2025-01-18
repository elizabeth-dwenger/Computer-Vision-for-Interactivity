#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofBackground(100);
    
    gui.setup();

    gui.add(brushSize.setup("Brush Size", 12, 5, 50));
        
    imgBg.load("bg.jpg");
    imgMan.load("running.jpg");
    matBg = toCv(imgBg);
    matMan = toCv(imgMan);
        
    int width = imgBg.getWidth();
    int height = imgBg.getHeight();
    
    // Shader
    string shaderProgram = "#version 120\n \
    #extension GL_ARB_texture_rectangle : enable\n \
    \
    uniform sampler2DRect tex0;\
    uniform sampler2DRect maskTex;\
    \
    void main (void){\
    vec2 pos = gl_TexCoord[0].st;\
    \
    vec3 src = texture2DRect(tex0, pos).rgb;\
    float mask = texture2DRect(maskTex, pos).r;\
    \
    gl_FragColor = vec4( src , mask);\
    }";
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
    
    
    maskFbo.allocate(width, height);
    fbo.allocate(width, height);
    
    maskFbo.begin();
        ofClear(0,0,0,255);
    maskFbo.end();
         
    fbo.begin();
        ofClear(0,0,0,255);
    fbo.end();
    
    isPainting = false;
    isBackground = false;

    
}

//--------------------------------------------------------------
void ofApp::update(){
//    for (int r = 0; r < matMan.rows; r++){
//        for (int c = 0; c < matMan.cols; c++){
//            bool Background =
//                matMan.at<Vec3b>(r, c)[0] <= 128 &&
//                matMan.at<Vec3b>(r, c)[1] >= 100 &&
//                matMan.at<Vec3b>(r, c)[2] <= 128;
//            if (!Background) {
//                maskFbo.begin();
//                    if (isPainting){
//                        ofSetColor(ofColor::aliceBlue);
//                        ofDrawCircle(mouseX, mouseY, brushSize, brushSize);
//                    }
//                maskFbo.end();
//            }
//        }
//    }

    maskFbo.begin();
        if (isPainting){
            ofSetColor(255,255,0);
            ofDrawCircle(mouseX, mouseY, brushSize, brushSize);
        }
    maskFbo.end();
    
    
    fbo.begin();
        ofClear(0, 0, 0, 0);
        shader.begin();
        shader.setUniformTexture("maskTex", maskFbo.getTexture(), 1);
        drawMat(matBg, 0, 0);
        gui.draw();
        shader.end();
    fbo.end();
      
    //
}

//--------------------------------------------------------------

void ofApp::draw(){
    ofSetColor(255, 255);
    
    drawMat(matMan, 0, 0);
    gui.draw();
    
    fbo.draw(0, 0);
}


void ofApp::togglePainting(){
    isPainting = !isPainting;

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//    for (int r = 0; r < matMan.rows; r++){
//        for (int c = 0; c < matMan.cols; c++){
//            bool Background =
//                matMan.at<Vec3b>(r, c)[0] <= 128 &&
//                matMan.at<Vec3b>(r, c)[1] >= 100 &&
//                matMan.at<Vec3b>(r, c)[2] <= 128;
//            if (!Background) {
//                matBg.at<Vec3b>(r, c) = matMan.at<Vec3b>(r, c);
//            }
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    togglePainting();
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    togglePainting();
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
