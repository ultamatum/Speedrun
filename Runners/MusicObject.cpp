#include "MusicObject.h"

MusicObject::MusicObject()
{
}

MusicObject::~MusicObject()
{
}

// Store filename and key for music file
void MusicObject::SetMusic(std::string lfilename, std::string lname)
{
	filename = lfilename;
	name = lname;
}
