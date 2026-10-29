#pragma once

// Source: Microsoft PlaySound documentation: https://learn.microsoft.com/en-us/windows/win32/api/mmsystem/nf-mmsystem-playsound
void playLoop(const char* path); // loops the sound (start, winter, spring, summer, autumn)
void playOnce(const char* path); // plays the sound one time (end screen)