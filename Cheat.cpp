#include "Cheat.h"
#include "Java.h"

jclass getMinecraftVersion() {
	return cheeto.environment->FindClass("ave");
}

jobject getMinecraft() {
	jmethodID getMinecraftID = cheeto.environment->GetStaticMethodID(getMinecraftVersion(), "A", "()Lave;");
	return cheeto.environment->CallStaticObjectMethod(getMinecraftVersion(), getMinecraftID);
}

jobject getWorld() {
	jfieldID getField = cheeto.environment->GetFieldID(getMinecraftVersion(), "f", "()lbdb");
}

void modules() {

}