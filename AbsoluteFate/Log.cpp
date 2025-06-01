#include "Log.h"
#include <SDL_error.h>

//Print value in consol
void Log::Info(const std::string& message)
{
	SDL_Log(message.c_str());
}

//Print error in consol
void Log::Error(LogType category, const std::string& message)
{
	SDL_LogError(static_cast<int>(category), "%s | SDL : %s", message.c_str(), SDL_GetError());
}