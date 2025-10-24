#include "Cheat.h"
#include "Java.h"

#include <iostream>
#include <thread>
#include <chrono>

jclass getMinecraftVersion() {
	return cheeto.environment->FindClass("ave");
}

jobject getMinecraft() {
	jmethodID getMinecraftID = cheeto.environment->GetStaticMethodID(getMinecraftVersion(), "A", "()Lave;");
	return cheeto.environment->CallStaticObjectMethod(getMinecraftVersion(), getMinecraftID);
}

jobject getPlr() {
	jfieldID getField = cheeto.environment->GetFieldID(getMinecraftVersion(), "h", "LBew;");
	return cheeto.environment->GetObjectField(getMinecraft(), getField);
}

jobject getWorld() {
	jfieldID getField = cheeto.environment->GetFieldID(getMinecraftVersion(), "f", "Lbdb;");
	return cheeto.environment->GetObjectField(getMinecraft(), getField);
}

//sprint in any direction
void omnisprint() {
	jmethodID setSprint = cheeto.environment->GetMethodID(cheeto.environment->GetObjectClass(getPlr()), "d", "(Z)V");
	cheeto.environment->CallBooleanMethod(getPlr(), setSprint, true);
}

void modules() {
	// if null then dont do notin
	while (true) {
		if (!!getMinecraft()) continue;
		if (!!getPlr()) continue;
		if (!!getWorld()) continue;

		omnisprint();
		std::cout << "omnisprint on";

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}