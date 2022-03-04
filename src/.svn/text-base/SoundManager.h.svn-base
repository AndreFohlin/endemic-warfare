#pragma once
#include <map>
#include <string>
#include <../include/fmod/fmod.h>

class SoundManager
{
public:
	static SoundManager* Instance();
	void Init();

	void PlaySound(std::string name,char volume);
	void PlayMusic(std::string name,char volume);
	void AddSound(std::string name, std::string path);
	void AddMusic(std::string name, std::string path);


private:

	std::map<std::string,FSOUND_SAMPLE*> m_Sound;
	std::map<std::string,FSOUND_SAMPLE*> m_Music;
	SoundManager(){}
	SoundManager(const SoundManager&);
	SoundManager& operator=(const SoundManager&);
};