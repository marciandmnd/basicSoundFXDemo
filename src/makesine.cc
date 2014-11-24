/*
    File:   makesine.cc
    By:     Marcian Diamond
    Instructor: Dr. Hsu
    Course: CSC699 Independent Study; Software Techniques for Computer Music
    Date:   9.16.2013
    
    Compile:
    Usage:
    
    Description:

*/

#include <iostream>
#include <stdio.h>
#include "sndfile.h"
#include "makesine.h"
#include <math.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

//default constructor, 5s 100 Hz sine wave
MakeSine::MakeSine(){
    length = 5000;
    frequency = 100;
    initialPhase = 0;
    numSamples = length*SR/1000;
    angleIncrement = findAngleIncrement(frequency);
    currTimeIndex = 0;
}

MakeSine::MakeSine(double freq){
    length = 5000; // default sound file length in ms
    frequency = freq;
    initialPhase = 0;
    numSamples = length*SR/1000;
    angleIncrement = findAngleIncrement(frequency);
    currTimeIndex = 0;
}

MakeSine::MakeSine(double freq, double phi){
    length = 5000; // default sound file length in ms
    frequency = freq;
    initialPhase = phi;
    numSamples = length*SR/1000;
    angleIncrement = findAngleIncrement(frequency);
    currTimeIndex = 0;
}
MakeSine::MakeSine(double freq, double phi, double duration){
    length = duration; // default sound file length in ms
    frequency = freq;
    initialPhase = phi;
    numSamples = length*SR/1000;
    angleIncrement = findAngleIncrement(frequency);
    currTimeIndex = 0;
}
//destructor
MakeSine::~MakeSine(){

}

// set current frequency of sinusoid
void MakeSine::setMakeSineFreq(double){

} 
// get current frequency of sinusoid
double MakeSine::getMakeSineFreq(){
    return frequency;
}   

// set initial phase of sinusoid  
void MakeSine::setMakeSineInitPhase(double){

} 
// get initial phase of sinusoid
double MakeSine::getMakeSineInitPhase(){
    return initialPhase;
} 
// set length for generated sine wave
 void  MakeSine::setLength(double){

}  
//get length for generated sine wave
double  MakeSine::getLength(){
    return length;
}       

double MakeSine::findAngleIncrement(double freq){
    return freq/SR;
}
double  MakeSine::getNumSamples(){
    return numSamples;
}      
double MakeSine::tick(){
    double output; 
    output = sin(2.*M_PI*(angleIncrement*currTimeIndex)+initialPhase);
    currTimeIndex++;
    return output;
}
