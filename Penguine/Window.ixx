export module Window;

import <string>;

export class Window
{
public:
	Window() = default;

	void Init( int width, int height, const std::string& name )
	{

	}

#ifdef _WIN32
private:

};
#elifdef _MACOS
private:
};
#elifdef __linux__
private:
};
#endif