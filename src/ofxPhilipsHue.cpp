//
//  ofxPhilipsHue.cpp
//  philipsHueTest
//
//  Created by Ryota Katoh on 2014/06/03.
//
//

#include "ofxPhilipsHue.h"

void ofxPhilipsHue::setup(string ipAddress, string appName, int lightNumber){

    lightUrl = "http://" + ipAddress + "/api/" + appName + "/lights/" + ofToString(lightNumber) + "/";
    
    response.open(lightUrl);
    isOn = response["state"]["on"].asBool();
     
    httpUtils.start();
    
    
}

void ofxPhilipsHue::setLightOn(bool lightOn){

    string actionUrl = lightUrl + "state/";
    
    
    stringstream input;
    
    if(isOn && !lightOn){
        input << "{\"transitiontime\": 0, \"on\": false}";
        isOn = false;
    }
    else if (lightOn) {
        input << "{\"transitiontime\": 0, \"on\": true}";
        isOn = true;            
    }
    
    string sendData = input.str();
    
    ofBuffer buff;
    buff.set(sendData.c_str(), sendData.size());
    
    httpUtils.putData(actionUrl, buff, "application/json");

}

void ofxPhilipsHue::setHue(int hue){
    
    if(hue > 65525)
        hue = 65525;
    if(hue < 0)
        hue = 0;
    
    
    string actionUrl = lightUrl + "state/";
    
    
    stringstream input;
    
    input << "{\"hue\":" <<hue<< "}";
     
    
    string sendData = input.str();
    
    ofBuffer buff;
    buff.set(sendData.c_str(), sendData.size());
    
    httpUtils.putData(actionUrl, buff, "application/json");
    
}

void ofxPhilipsHue::setBri(int bri){

    if(bri > 255)
        bri = 255;
    if(bri < 0)
        bri = 0;
    
    
    string actionUrl = lightUrl + "state/";
    
    
    stringstream input;
    
    input << "{\"bri\":" <<bri<< "}";
    
    
    string sendData = input.str();
    
    ofBuffer buff;
    buff.set(sendData.c_str(), sendData.size());
    
    httpUtils.putData(actionUrl, buff, "application/json");
    
}

void ofxPhilipsHue::setSat(int sat){
    
    if(sat > 255)
        sat = 255;
    if(sat < 0)
        sat = 0;
    
    
    string actionUrl = lightUrl + "state/";
    
    
    stringstream input;
    
    input << "{\"sat\":" <<sat<< "}";
    
    
    string sendData = input.str();
    
    ofBuffer buff;
    buff.set(sendData.c_str(), sendData.size());
    
    httpUtils.putData(actionUrl, buff, "application/json");
    
}

bool ofxPhilipsHue::getIsOn(){

    return isOn;
    
}

