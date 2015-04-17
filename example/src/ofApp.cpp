#include "ofApp.h"

int current_red = 0;
int current_green= 0;
int current_blue = 0;
int current_brightness = 0;
bool current_lightOn = true;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(colorSlider.setup("color",ofColor(100,100,140),ofColor(0,0),ofColor(255,255)));
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
    
    if (current_red != (int)color->r){
        hue1.setHue(ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 63555));
        current_red = color->r;
    }
    
    if (current_green != (int)color->g){
        hue1.setHue(ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 63555));
        current_green = color->g;
    }
    
    if (current_red != (int)color->b) {
        hue1.setHue(ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 63555));
        current_blue = color->b;
    }
    
    if (current_brightness != color->getBrightness()) {
        hue1.setBri(color->getBrightness());
        current_brightness = color -> getBrightness();
    }
    
    if (light && !hue1.getIsOn()) {
        hue1.setLightOn(true);
        current_lightOn = true;
    } else if (!light && hue1.getIsOn()) {
        hue1.setLightOn(false);
        current_lightOn = false;
    }
    
    // Debug
    ofLog(OF_LOG_NOTICE, "red: %d", current_red);
    ofLog(OF_LOG_NOTICE, "green: %d", current_green);
    ofLog(OF_LOG_NOTICE, "blue: %d", current_blue);
    ofLog(OF_LOG_NOTICE, "brightness: %d", current_brightness);
    
    int hoge = ofMap(getHue(color->r, color->g, color->b), 0, 360, 0, 63555);
    ofLog(OF_LOG_NOTICE, "the number is " + ofToString(hoge));
    
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

