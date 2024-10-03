#include "playlist.hpp"
#include "menu_file.hpp"
#include <iostream>
#include <thread>
#include "media_controller.hpp"

Playlist::Playlist(std::string name) : name(name), currentSongIndex(0) {}

void Playlist::addFile(const File& file) {
    files.push_back(file);
}

void Playlist::removeFile(const std::string& filePath) {
    for (auto it = files.begin(); it != files.end(); ++it) {
        if (it->getFilePath() == filePath) {
            files.erase(it);
            return;
        }
    }
}

void Playlist::viewPlaylist() const {
    std::cout << "Playlist: " << name << std::endl;
    for (const auto& file : files) {
        std::cout << file.getFilePath() << std::endl;
    }
}

void Playlist::playCurrentSong() {
    if (!files.empty()) {
        files[currentSongIndex].play();
    } else {
        std::cerr << "No files in the playlist to play.\n";
    }
}

void Playlist::pauseCurrentSong() {
    files[currentSongIndex].pause();
}

void Playlist::resumeCurrentSong() {
    files[currentSongIndex].resume();
}

void Playlist::nextSong() {
    if (currentSongIndex < int(files.size()) - 1) {
        currentSongIndex++;
        playCurrentSong();
    } else {
        std::cout << "Reached the end of the playlist.\n";
    }
}

void Playlist::previousSong() {
    if (currentSongIndex > 0) {
        currentSongIndex--;
        playCurrentSong();
    } else {
        std::cout << "Already at the first song.\n";
    }
}

void Playlist::playPlaylistWithControls() {
    char command;
    std::thread timeThread;
    playCurrentSong();
    while (command != 'q') {
        std::cout << "\nType 'p' to pause the song\n";
        std::cout << "Type 'r' to resume the song\n";
        std::cout << "Type 'n' to next the song\n";
        std::cout << "Type 'b' to back the song\n";
        std::cout << "Type 's' to show current and total time\n";
        std::cout << "Type 'q' to quit the playlist\n";
        std::cout << "Controls: [p]ause, [r]esume, [n]ext, [b]ack, [s]howtime, [q]uit\n";
        std::cin >> command;

        switch (command) {
            case 'p':
                pauseCurrentSong();
                break;
            case 'r':
                resumeCurrentSong();
                break;
            case 'n':
                nextSong();
                break;
            case 'b':
                previousSong();
                break;
            case 's':
                if (!showTimeFlag) {
                    showTimeFlag = true;  // Set the flag to start time display
                    timeThread = std::thread(displayTimeThread, std::ref(files[currentSongIndex]));  // Start time thread
                } else {
                    showTimeFlag = false;  // Stop the time display
                    if (timeThread.joinable()) {
                        timeThread.join();  // Wait for the thread to finish
                    }
                }
                break;
            case 'q':
                std::cout << "Stopping playback.\n";
                break;
            default:
                std::cerr << "Invalid command.\n";
        }
    }
}

std::string Playlist::getName() const {
    return name;
}
