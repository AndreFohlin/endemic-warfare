#pragma once

enum ScoreType
{
	KILL,
	BOMB,
	WOMEN,
	MEAD,
	GOLD,
	SUICIDE

};

class ScoreManager
{
public:
	static ScoreManager*	Instance()
	{
		static ScoreManager instance;
		return &instance;
	}

	int GetScore()
	{
		return m_PlayerScore;
	}
	void AddScore(int score, ScoreType type);
	void ResetMultiplier();

	int getMead(){return m_Mead;}
int m_Women;
	int m_Gold;
	int m_Kills;
	int m_Bomb;
private:
	int m_Mead;
	
	int m_PlayerScore;

	ScoreManager();
	~ScoreManager(){}
};