#ifndef SINEWAVE_H
#define SINEWAVE_H
#define BUFFER_LEN 1024
#define MAX_CHANNELS    1
#define SR 44100
int generateSineWave(); // function prototype for add.h
int showOptions();
int defaultWave();
int freqWave();
int freqPhiWave();
int freqPhiDurWave();
int createWaveForm();
#endif
