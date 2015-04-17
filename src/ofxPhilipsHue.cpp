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

void ofxPhilipsHue::setLightOn(){

    string actionUrl = lightUrl + "state/";
    
    
    stringstream input;
    
    if(isOn){
        input << "{\"transitiontime\": 0, \"on\": false}";
        isOn = false;
    }
    else{
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
    
    ofLog(OF_LOG_NOTICE, "setBri: %d", bri);
    httpUtils.putData(actionUrl, buff, "application/json");
    
    
}

bool ofxPhilipsHue::getIsOn(){

    return isOn;
    
}

