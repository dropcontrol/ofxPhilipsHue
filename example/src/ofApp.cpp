#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    gui.setup(); // most of the time you don't need a name
//    gui.add(bri.setup("brightness", 0, 0, 254));
//    bri.addListener(this, &ofApp::changeBrightness);
//    gui.add(filled.setup("on/off", true));
    gui.add(colorSlider.setup("color",ofColor(100,100,140),ofColor(0,0),ofColor(255,255)));
    
    
    hue1.setup("192.168.100.130", "newdeveloper", 1);
    
}

//void ofApp::changeBrightness(ofParameter<ofColor> color) {
//    
//    ofLog(OF_LOG_NOTICE, "%d", (int)color->getBrightness());
//    hue1.setBri((int)color->getBrightness());
//    
//}

//
// http://ja.wikipedia.org/wiki/HSV色空間
//

int getHue(float r, float g, float b) {
    float max = MAX(MAX(r, g), b);
    float min = MIN(MIN(r, g), b);

    float h;
    
    if (min == max) {
        return 0;
    } else if (max == r) {
        h = 60 * ((g - b) / (max - min));
    } else if (max == g) {
        h = 60 * ((b - r) / (max - min)) + 120;
    } else if (min == b) {
        h = 60 * ((r - g) / (max - min)) + 240;
    }
                
    if (h < 0) {
        h += 360;
    }
    return (int)h;

}

int getSaturation(float r, float g, float b) {
    float min = MIN(MIN(r, g), b);
    float max = MAX(MAX(r, g), b);
    float delta = max-min;
    if (max!=0) return int(delta/max*255);
    return 0;
}

int getBrightness(float r, float g, float b) {
    return MAX(MAX(r,g),b);
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    color = colorSlider;
    ofLog(OF_LOG_NOTICE, "r: %d", (int)color->r);
    ofLog(OF_LOG_NOTICE, "g: %d", (int)color->g);
    ofLog(OF_LOG_NOTICE, "b: %d", (int)color->b);
//    ofLog(OF_LOG_NOTICE, "a: %d", (int)color->a);
    
    hue1.setBri(color->getBrightness());

//    hue1.setHue(getHue(color->r, color->g, color->b));
    hue1.setHue(2000);
    
    int hoge = getHue(color->r, color->g, color->b);
    ofLog(OF_LOG_NOTICE, "the number is " + ofToString(hoge));
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

