#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxPhilipsHue.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxPanel gui;
    ofxColorSlider colorSlider;
//    ofxToggle filled;
//    ofxIntSlider bri;

    ofParameter<ofColor> color;
    
    ofxPhilipsHue hue1;
    
private:    
    
//    void changeBrightness(ofParameter<ofColor> color);

};
