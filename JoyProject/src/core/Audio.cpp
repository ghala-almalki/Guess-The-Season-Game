#include "core/Audio.h"

// Windows sound library for background music
// Source: Microsoft PlaySound documentation: https://learn.microsoft.com/en-us/windows/win32/api/mmsystem/nf-mmsystem-playsound
#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#endif

void playLoop(const char* path) {
#ifdef _WIN32
    PlaySoundA(path, NULL, SND_ASYNC | SND_LOOP);
#endif
}

void playOnce(const char* path) {
#ifdef _WIN32
    PlaySoundA(path, NULL, SND_ASYNC);
#endif
}