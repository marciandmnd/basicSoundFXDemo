

#include <sndfile.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "SineWave.h"
#include "makesine.h"

using std::cin;
using std::cout;
using std::endl;

//globals
static double data [BUFFER_LEN] ;
static double outbuf [BUFFER_LEN] ;
SNDFILE *sineWave;
SF_INFO sfinfo ;
double length,samples;
char *outfilename;
MakeSine sine;

int defaultWave(){
    sine = MakeSine();
    createWaveForm();
    return 1;
}

int freqWave(){
    float freq;
    printf("Enter Frequency: ");
    scanf(" %f", &freq);
    sine = MakeSine(freq);
    createWaveForm();
    return 1;
}

int freqPhiWave(){
    float freq;
    float phi;
    printf("Enter Frequency: ");
    scanf(" %f", &freq);
    printf("Enter Phase: ");
    scanf(" %f", &phi);
    sine = MakeSine(freq, phi);
    createWaveForm();
    return 1;
}

int freqPhiDurWave(){
    float freq;
    float phi;
    float duration;
    printf("Enter Frequency: ");
    scanf(" %f", &freq);
    printf("Enter Phase: ");
    scanf(" %f", &phi);
    printf("Enter Duration (ms): ");
    scanf(" %f", &duration);
    sine = MakeSine(freq, phi, duration);
    createWaveForm();
    return 1;
}

int createWaveForm(){
    cout << "creating sine wave... " << endl;
    cout << "frequency =  " << sine.getMakeSineFreq() << " Hz" << endl;
    cout << "phase shift = " << sine.getMakeSineInitPhase() << " rad" << endl;
    cout << "duration = " << sine.getLength() << " ms" << endl;
    cout << "samples = " << sine.getNumSamples() << endl;
    samples = sine.getNumSamples();
    sineWave = sf_open("sine.wav", SFM_WRITE, &sfinfo);
    
    //process sine wave;
    double writecount;
    writecount = (int)BUFFER_LEN%(int)samples;
    while(writecount > 0){   
        writecount = (int)BUFFER_LEN%(int)samples;
        for (int i=0; i<writecount; i++) {
          outbuf[i] = sine.tick();
        }
        samples = samples-writecount;
        sf_write_double(sineWave, outbuf, writecount);
    }
    cout << "final samples: " << samples << endl;
    for (int i=0; i<samples; i++) {
          outbuf[i] = sine.tick();
    }
    sf_write_double(sineWave, outbuf, samples);

    //close output file and exit
    sf_close(sineWave);
    system("pause");
    return 0 ;
}
int showOptions(){
    int input;
    printf("Please Select an Option:\n");
    printf("1) Generate Default Sine Wave\n");
    printf("2) Specific Frequency\n");
    printf("3) Specific Frequency and Phase\n");
    printf("4) Specific Frequency,Phase, and Duration\n");
    printf("5) Return to Main Menu\n");
    printf("Type option then bress Enter: ");
    scanf (" %d",&input);    
    switch(input){
        case 1: defaultWave();
                break;
        case 2: freqWave();
                break;
        case 3: freqPhiWave();
                break;
        case 4: freqPhiDurWave();
                break;
        case 5: return 1;
        default: printf("\nInvalid Input! Please try again...\n");
    }
    return 1;
}

int generateSineWave()
{
    int freq;
    cout << "SINE WAVE GENERATOR EFFECT" << endl;
   
    
    //set soundfile properties
    sfinfo.format =  SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    sfinfo.channels = 1; 
    sfinfo.samplerate = SR;
    showOptions();


}
