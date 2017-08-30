#include <string.h>
#include <jni.h>
#include <stdint.h>
#include <stdio.h>
//#include "gperf.h"

// Unfortunately this has to be hand-generated for now...
//#define SWIFT_ADD _T08AddSwift13addTwoNumberss5UInt8VAD5first_AD6secondtF
//#define AddTwoNumbers _T08AddSwift13addTwoNumberss5UInt8VAD_ADtF
//#define MY_MAIN _T08AddSwift6MyMainyyF

extern uint8_t addTwoNumbers(uint8_t, uint8_t);

// Promise C we've implemented this function.
extern void myMain(void);

JNIEXPORT jstring JNICALL
Java_com_example_addswift_MainActivity_stringFromJNI(JNIEnv * env, jobject thiz ) {
    
    uint8_t a = 231;
    uint8_t b = 137;
    myMain();
    uint8_t c = addTwoNumbers(a, b); //SWIFT_ADD(a,b); a+b;  //
    //GetTicks();
    char result[255];
    sprintf(result, "We are computing the addition of %d and %d.\n\nThe result is %d.\n\nThis computation was written in Swift and is running on this Android device!", a, b, c);
    
    return (*env)->NewStringUTF(env, result);
}
