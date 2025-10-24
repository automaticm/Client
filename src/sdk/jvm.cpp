#include "minecraft/minecraft.h"
#include "jvm.h"

#include <iostream>
#include <thread>
#include <chrono>

void jvm::load() {
	JNI_GetCreatedJavaVMs(&vm, 1l, nullptr);
	if (vm->GetEnv(reinterpret_cast<void**>(&environment), JNI_VERSION_24) == JNI_EDETACHED) {
		vm->AttachCurrentThreadAsDaemon(reinterpret_cast<void**>(&environment), nullptr);
	}
}

c_jobject::c_jobject(jobject object_in) {
	this->cached_object = object_in;
}

c_jobject::~c_jobject() {
	if (this->cached_object != nullptr) {
		jvm::environment->DeleteLocalRef(this->cached_object);
	}
}

//jclass getMinecraftVersion() {
//	return cheeto.environment->FindClass("ave");
//}
//
//jobject getMinecraft() {
//	jmethodID getMinecraftID = cheeto.environment->GetStaticMethodID(getMinecraftVersion(), "A", "()Lave;");
//	return cheeto.environment->CallStaticObjectMethod(getMinecraftVersion(), getMinecraftID);
//}
//
//jobject getPlr() {
//	jfieldID getField = cheeto.environment->GetFieldID(getMinecraftVersion(), "h", "LBew;");
//	return cheeto.environment->GetObjectField(getMinecraft(), getField);
//}
//
//jobject getWorld() {
//	jfieldID getField = cheeto.environment->GetFieldID(getMinecraftVersion(), "f", "Lbdb;");
//	return cheeto.environment->GetObjectField(getMinecraft(), getField);
//}
//
////sprint in any direction
//void omnisprint() {
//	jmethodID setSprint = cheeto.environment->GetMethodID(cheeto.environment->GetObjectClass(getPlr()), "d", "(Z)V");
//	cheeto.environment->CallBooleanMethod(getPlr(), setSprint, true);
//}
//
//void modules() {
//	// if null then dont do notin
//	while (true) {
//		if (!!getMinecraft()) continue;
//		if (!!getPlr()) continue;
//		if (!!getWorld()) continue;
//
//		omnisprint();
//		std::cout << "omnisprint on";
//
//		std::this_thread::sleep_for(std::chrono::milliseconds(5));
//	}
//}