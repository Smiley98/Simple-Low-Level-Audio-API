#pragma once
#include <fmod/fmod.hpp>
#include <vector>

//Give your enums better names.
enum Sounds : unsigned char {
	SOUND_1,
	SOUND_2,
	NUM_SOUNDS
};

class SoundSystem abstract
{
public:
	static void init();
	//Plays no more than one sound at a time through the master channel.
	//Make this better. I suggest making a channel class with all additional information you need like volume, pitch, or stuff like falloff if 3d.
	//Make channel getters similar to my Sounds enum. Use it to modify channel state. Store an array of channels (FMOD::ChannelGroup) within this class.
	static void playSound(Sounds sound);
	//Note:
	//Don't do something like static void playSound(Sounds sound, bool loop).
	//Make new functions rather than overloading or making one function with a bunch of default parameters for legibility.

private:
	static FMOD::System* s_system;
	static FMOD::Sound* s_sounds[Sounds::NUM_SOUNDS];
	//You can have sound and channel groups to organize things, but its overly complex/not necessary.
	//TLDR, channels work the same as sounds. By passing an uninitialized channel* to sys->playSound, fmod will initialize it and write some information to it like whether or not its in use.
	//(Implement channels yourself as you deem fit. I wouldn't bother with dsp or 3d (applications of channels), just focus on playing good 2d sounds.
	//static FMOD::Channel* s_channels;
	//static const int s_numChannels;

	//Also, make an update methods that's called every frame meaning make a wrapper for "s_system->update()". It may not apply since we don't actually set state yet, but you'll want it for things like volume.
	//Lastly, you can release sounds by going s_sounds[SOUND_1]->release(). Just like create(), fmod handles the memory.
	//You won't actually need to do this cause A) you don't have enough resources to have a need to manage memory and B) I made stuff static so it never dies so freeing it would be counter intuitive.
	//Remeber, this library is 32 bit so swap the files out for the 64 bit versions if you wanna build for 64 bit.
};