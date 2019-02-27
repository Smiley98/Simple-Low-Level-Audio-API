#include "SoundSystem.h"

int main() {
	SoundSystem::init();
	SoundSystem::playSound(Sounds::SOUND_1);

	getchar();
	return 0;
}