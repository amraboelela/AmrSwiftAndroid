#include <string.h>
#include <jni.h>
#include <stdint.h>
#include <stdio.h>

// Unfortunately this has to be hand-generated for now...
#define SWIFT_ADD _T08AddSwift13addTwoNumberss5UInt8VAD5first_AD6secondtF


uint8_t SWIFT_ADD(uint8_t, uint8_t);

jstring Java_com_example_addswift_MainActivity_stringFromJNI(JNIEnv * env, jobject thiz ) {
    
    uint8_t a = 123;
    uint8_t b = 45;
    uint8_t c = SWIFT_ADD(a,b);
    
    char result[255];
    sprintf(result, "We are computing the addition of %d and %d.\n\nThe result is %d.\n\nThis computation was written in Swift and is running on this Android device!", a, b, c);
    
    return (*env)->NewStringUTF(env, result);
}
