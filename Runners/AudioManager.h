// Audio Manager
// Maintains lists of Sound and Music for playback in game
#pragma once

#include "Sound.h"
#include "MusicObject.h"
#include "SFML\Audio.hpp"

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	void AddSound(std::string filename, std::string lname);
	void PlaySoundbyName(std::string lname);
	void StopAllSounds();

	void AddMusic(std::string filename, std::string lname);
	void PlayMusicbyName(std::string lname);
	void StopAllMusic();

private:
	// List of sounds
	std::vector<Sound> sounds;
	// List of Musics
	std::vector<MusicObject> musics;
	// Single Music object as the stream cannot be copied.
	sf::Music music;
	// Re-useable sound object
	Sound s;
};

