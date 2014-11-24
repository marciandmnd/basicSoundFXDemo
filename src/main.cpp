#include <cstdlib>
#include <iostream>
#include "main.h"
#include "SineWave.h"
using namespace std;

int printMainMenu(void){
    printf("Please Select an Option:\n");
    printf("1) Sine Wave Generator\n");
    printf("2) Delay\n");
    printf("3) Echo\n");
    printf("4) Flanger\n");
    printf("5) Help\n");
    printf("6) About\n");
    printf("7) Exit\n\n");
    return 1;
    
}

int printAbout(void){
    printf("*****ABOUT*****\n");
    printf("Basic SoundFX Demo\n");
    printf("By: Marcian Diamond\n");
    printf("Released under GNU license");
};
int openProgram(void){
    char input;
    printf("Type option then bress Enter: ");
    scanf (" %c",&input);    
    switch(input){
        case '1': printf("Opening Sine Wave Generator Module...\n");
        generateSineWave();
                break;
        case '2': printf("Opening Delay Module...\n");
                break;
        case '3': printf("Opening Echo Module...\n");
                break;
        case '4': printf("Opening Flanger Module...\n");
                break;
        case '5': printf("Opening Help Module...\n");
                break;
        case '6': printAbout();
                break;
        case '7': exitProgram();
                break;
        default: printf("Invalid option! Please try again...\n\n");
                break;
    }
    return 0;
}

int exitProgram(void){
    exit(EXIT_SUCCESS);
}


int main(int argc, char *argv[]){    
    printf("*****BASIC SOUND FX DEMO*****\n");
    while(1){
        printMainMenu();
        openProgram();
    }
    system("PAUSE");
}



