#include "SoundManager.h"


SoundManager* SoundManager::Instance()
{
	static SoundManager instance;

	return &instance;
}

void SoundManager::Init()
{
	FSOUND_Init(44100, 32, 0);
	AddSound("Explosion", "../data/sound/boom.wav");
	AddSound("GetGirl", "../data/sound/ooooo.wav");
	AddSound("Rock", "../data/sound/mine.wav");
}

void SoundManager::PlaySound(std::string name, char volume= char(255))
{
	int channel;
	channel = FSOUND_PlaySound(FSOUND_FREE,m_Sound[name]);
	FSOUND_SetVolume(channel,255);
}

void SoundManager::PlayMusic(std::string name,char volume = char(255))
{
	int channel;
	channel = FSOUND_PlaySound(FSOUND_FREE,m_Music[name]);
	//FSOUND_SetVolume(channel,volume);
}

void SoundManager::AddSound(std::string name, std::string path)
{
	//m_Sound[name] =	FSOUND_Stream_Open(path.c_str(),FSOUND_2D,0,0);
	m_Sound[name] =FSOUND_Sample_Load(FSOUND_UNMANAGED,path.c_str(),FSOUND_2D,0,0);
}

void SoundManager::AddMusic(std::string name, std::string path)
{
	m_Music[name] =FSOUND_Sample_Load(FSOUND_UNMANAGED,path.c_str(),FSOUND_2D,0,0);
}
