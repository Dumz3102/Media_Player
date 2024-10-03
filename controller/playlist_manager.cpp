#include "playlist_manager.hpp"
#include <filesystem> 
#include <iostream>

void PlaylistManager::listPlaylists() const {
    if (playlists.empty()) {
        std::cout << "No playlists available.\n";
    } else {
        std::cout << "Available playlists:\n";
        for (const auto& pair : playlists) {
            std::cout << pair.first << std::endl;
        }
    }
}

void PlaylistManager::viewPlaylist(const std::string& playlistName) const {
    auto it = playlists.find(playlistName);
    if (it != playlists.end()) {
        std::cout << "Files in playlist '" << playlistName << "':\n";
        for (const auto& file : it->second.getFiles()) {
            // Extract the file path using the File class's getFilePath method
            std::string filePath = file.getFilePath();

            // Optionally, extract only the filename from the full path
            std::size_t pos = filePath.find_last_of("/\\");
            if (pos != std::string::npos) {
                std::cout << filePath.substr(pos + 1) << "\n";  // Display only the filename
            } else {
                std::cout << filePath << "\n";  // If no path separator is found, print the entire path
            }
        }
    } else {
        std::cerr << "Playlist not found.\n";
    }
}

void PlaylistManager::createOrUpdatePlaylist(const std::string& playlistName) {
    if (playlists.find(playlistName) == playlists.end()) {
        playlists[playlistName] = Playlist(playlistName);
    }
    
    std::string filePath;
    while (true) {
        std::cout << "Enter file path to add to playlist (or type 'done' to finish): ";
        getline(cin,filePath);
        if (filePath == "done") break;
        playlists[playlistName].addFile(File(filePath));
    }
}

void PlaylistManager::deletePlaylist(const std::string& playlistName) {
    playlists.erase(playlistName);
    std::cout << "Playlist deleted.\n";
}

void PlaylistManager::playPlaylist(const std::string& playlistName) {
    auto it = playlists.find(playlistName);
    if (it != playlists.end()) {
        it->second.playPlaylistWithControls();
    } else {
        std::cerr << "Playlist not found.\n";
    }
}
