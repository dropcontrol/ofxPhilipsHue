//
//  ofxPhilipsHue.h
//  philipsHueTest
//
//  Created by Ryota Katoh on 2014/06/03.
//
//

#ifndef __philipsHueTest__ofxPhilipsHue__
#define __philipsHueTest__ofxPhilipsHue__

#include <iostream>

#include "ofMain.h"

#include "ofxHttpUtilsPlus.h"
#include "ofxJSONElement.h"

class ofxPhilipsHue{

    string  lightUrl;
    
    bool    isOn;
    
    ofxHttpUtilsPlus httpUtils;
    
    ofxJSONElement response;
    
public:
    

    void setup(string ipAdress, string appName, int lightNumber);
    
    void setLightOn();
    
    void setHue(int hue);
    
    void setBri(int bri);
    
    bool getIsOn();
    
};

#endif /* defined(__philipsHueTest__ofxPhilipsHue__) */
