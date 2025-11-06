#include "main.h"

void plrJump(JNIEnv* env){
    // Setting up Minecraft instance
    jclass minecraftClass = env->FindClass("ave");
    // if (minecraftClass == NULL) {
    //     printf("Failed to find class 'ave'.\n");
    //     return;
    //}
    jmethodID getMinecraft = env->GetStaticMethodID(minecraftClass, "A", "()Lave;");
    // if (getMinecraft == NULL) {
    //     printf("Failed to find method 'A'.\n");
    //     return;
    // }
    jobject minecraftInstance = env->CallStaticObjectMethod(minecraftClass, getMinecraft);
    
    // Player attributes
    jfieldID plrField = env->GetFieldID(minecraftClass, "h", "Lbew;");
    // if (plrField == NULL) {
    //     printf("Failed to find player field 'h'.\n");
    //     return;
    // }
    jobject plr = env->GetObjectField(minecraftInstance, plrField);
    
    // if(plr == NULL){
    //     printf("Player object is null, are you loaded in a game yet?");
    //     return;
    // }

    jclass plrClass = env->GetObjectClass(plr);
    // Calling player.jump();
    jmethodID jumpMethod = env->GetMethodID(plrClass, "bF", "()V");
    // if (jumpMethod == NULL) {
    //     printf("Failed to find jump method 'bf'.\n");
    //     return;
    // }
    env->CallVoidMethod(plr, jumpMethod);
}