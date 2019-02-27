#include "SoundSystem.h"
#include <cstdio>

FMOD::System* SoundSystem::s_system;
FMOD::Sound* SoundSystem::s_sounds[Sounds::NUM_SOUNDS];

void SoundSystem::init()
{
	//Initialize fmod.
	FMOD_RESULT createResult = FMOD::System_Create(&s_system);
	if (createResult != FMOD_OK)
		printf("FMOD creation failed\n");

	int driverCount = 0;
	s_system->getNumDrivers(&driverCount);
	if (driverCount == 0)
		printf("FMOD drivers failed\n");

	//Consider storing the number of channels. Moreover, create a channel group so you can play more than one sound at once, and with different settings ie pitch and volume.
	s_system->init(32, FMOD_INIT_NORMAL, nullptr);

	//Give your sounds better names.
	FMOD::Sound* sound1;
	//Loop specifies whether or not to play the sound once, or repeat forever.
	//Can also have 3d sounds, but you need a listener and to set a bunch of parameters for it to work.
	s_system->createSound("MySound.mp3", FMOD_2D | FMOD_LOOP_NORMAL, nullptr, &sound1);
	//Remember to store the sound after fmod has allocated memory for it.
	//sound1 will get destroyed after the function exits, but s_sounds holds onto the shared memory between our game and fmod's memory space.
	s_sounds[Sounds::SOUND_1] = sound1;
}

void SoundSystem::playSound(Sounds sound)
{
	s_system->playSound(s_sounds[sound], nullptr, false, nullptr);
}
