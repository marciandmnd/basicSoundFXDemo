#ifndef MAKESINE_H
#define MAKESINE_H
#define SR 44100

class MakeSine {
 public:
  MakeSine();              // constructor with default frequency and phase
  MakeSine(double);        // constructor that sets frequency
  MakeSine(double, double);// constructor that sets frequency and phase
  MakeSine(double, double, double);// constructor that sets frequency, phase, & duration
  ~MakeSine();             // destructor
  void setLength(double);   // set length for generated sine wave
  double getLength();       //get length for generated sine wave
  double getNumSamples();    //get number of samples of generated sine wave
  void setMakeSineFreq(double); // set current frequency of sinusoid
  double getMakeSineFreq();     // get current frequency of sinusoid
  void setMakeSineInitPhase(double); // set initial phase of sinusoid
  double getMakeSineInitPhase();     // get initial phase of sinusoid
  double findAngleIncrement(double);
  double tick();            // tick method; return next sample from generator

 private:
  double angleIncrement; //angle increment per tick
  double length, frequency, initialPhase; //generated wave parameters
  double numSamples;     //number of samples in generated sine wave
  long currTimeIndex;  // internal time index n; initialized to 0
};

#endif
