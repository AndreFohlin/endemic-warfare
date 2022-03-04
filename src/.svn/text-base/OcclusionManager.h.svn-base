
#include <./sdl/SDL.h>

class OcclusionManager
{
public:
	static OcclusionManager* Instance()
	{
		static OcclusionManager instance;
		return &instance;
	}
	void Init(char* path);
	void Update();
	void Show(int x, int y);
	void Render();
	void ShowTile(int x, int y);

private:
	
	bool isHidden(int x, int y);


	OcclusionManager();

	OcclusionManager(const OcclusionManager&);
	OcclusionManager& operator=(const OcclusionManager&);

	bool m_Visable[65][41];
	SDL_Surface* m_Surface;


};
