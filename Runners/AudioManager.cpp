#include "AudioManager.h"

AudioManager::AudioManager()
{
	// Some initial setup of music.
	// All music will loop and have half the normal volume (so background music is quieter).
	music.setLoop(true);
	music.setVolume(50);
}

AudioManager::~AudioManager() {}

// Given a filename and key a new SOUND object is added to the list. Loading the object into memory for playback
void AudioManager::AddSound(std::string filename, std::string lname)
{
	
	sounds.push_back(s);
	sounds.back().LoadSound(filename, lname);
	
}

// Play back sound based on provided key.
void AudioManager::PlaySoundbyName(std::string lname)
{
	for (int i = 0; i < sounds.size(); i++)
	{
		if (sounds[i].name == lname)
		{
			sounds[i].sound.play();
			return;
		}
	}
}

// Stop all sounds. Possible that multiple sounds (not music) can be played simultaneously. This stops all sounds.
void AudioManager::StopAllSounds()
{
	for (int i = 0; i < sounds.size(); i++)
	{
		sounds[i].sound.stop();
	}
}

// Stores filename and key of music file. These are not loaded into memory but streamed when required.
void AudioManager::AddMusic(std::string filename, std::string lname)
{
	MusicObject mu;
	musics.push_back(mu);
	musics.back().SetMusic(filename, lname);
}

// Starts streaming music file based on key provided.
void AudioManager::PlayMusicbyName(std::string lname)
{
	for (int i = 0; i < musics.size(); i++)
	{
		if (musics[i].name == lname)
		{
			music.openFromFile(musics[i].filename);
			music.play();
			return;
		}
	}
}

// Stops music.
void AudioManager::StopAllMusic()
{
	music.stop();
}