#ifndef PLAYLIST_MANAGER_HPP
#define PLAYLIST_MANAGER_HPP

#include <map>
#include "playlist.hpp"

class PlaylistManager {
private:
    std::map<std::string, Playlist> playlists;

public:
    void listPlaylists() const;
    void viewPlaylist(const std::string& playlistName) const;
    void createOrUpdatePlaylist(const std::string& playlistName);
    void deletePlaylist(const std::string& playlistName);
    void playPlaylist(const std::string& playlistName);
};

#endif
