#include "../jvm.h"
#include "classes.h"

void classes::load() {
	minecraft_class = jvm::environment->FindClass("ave");
}