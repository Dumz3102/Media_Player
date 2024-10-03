#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <taglib/fileref.h>
#include <taglib/tag.h>

using namespace std;

class File{
protected:
    string filePath;
    Mix_Music* music;
public:
    File(string filePath);
    string getFilePath() const { return filePath; }
    virtual void edit();
    virtual void show();
    void play();
    void pause();
    void resume();
    int getCurrentTime();
    int getDuration();
    ~File();
};

#endif