#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include <vector>
#include "file.hpp"

class Playlist {
private:
    std::string name;
    std::vector<File> files;
    int currentSongIndex;

public:
    Playlist(){}
    Playlist(std::string name);

    void addFile(const File& file);
    void removeFile(const std::string& filePath);
    void viewPlaylist() const;
    void playCurrentSong();
    void pauseCurrentSong();
    void resumeCurrentSong();
    void nextSong();
    void previousSong();
    void playPlaylistWithControls();
    std::string getName() const;
    const std::vector<File>& getFiles() const  {
        return files;
    }
};

#endif
