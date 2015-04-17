#include "ofApp.h"

int current_hue = 0;
int current_saturation = 0;
int current_brightness = 0;
bool current_lightOn = true;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(colorSlider.setup("color",ofColor(100,100,100),ofColor(0,0),ofColor(255,255)));
    gui.add(light.setup("light", true));

    hue1.setup("192.168.100.130", "newdeveloper", 1);
    
}

//--------------------------------------------------------------
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
    } else if (max == b) {
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
    

    if (current_hue != ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 65535)) {
        hue1.setHue(ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 65535));
        current_hue = ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 65535);
    }

    // set brightness
    if (current_brightness != color->getBrightness()) {
        hue1.setBri(color->getBrightness());
        current_brightness = color -> getBrightness();
    }
    
    // set saturation
    if (current_saturation != (int)getSaturation(color->r, color->g, color->b)) {
        hue1.setSat(getSaturation(color->r, color->g, color->b));
        current_saturation = getSaturation(color->r, color->g, color->b);
    }
    
    // set light on
    if (light && !hue1.getIsOn()) {
        hue1.setLightOn(true);
        current_lightOn = true;
    } else if (!light && hue1.getIsOn()) {
        hue1.setLightOn(false);
        current_lightOn = false;
    }
    
    // Debug
    ofLog(OF_LOG_NOTICE, "red: %d", color->r);
    ofLog(OF_LOG_NOTICE, "green: %d", color->g);
    ofLog(OF_LOG_NOTICE, "blue: %d", color->b);
    ofLog(OF_LOG_NOTICE, "brightness: %d", current_brightness);
    ofLog(OF_LOG_NOTICE, "saturation: %d", current_saturation);
    
    int hoge = ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 65535);
    ofLog(OF_LOG_NOTICE, "hue: " + ofToString(hoge));
    
    ofLog(OF_LOG_NOTICE, "isOn: %d", current_lightOn);
    
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

