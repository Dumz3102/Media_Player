#include "file.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

File::File(string filePath) : filePath(filePath), music(nullptr) {}

void File::edit() {
        // Get new metadata from the user
        string title, artist, album, genre;
        uint year, track;

        cout << "Enter new Title: ";
        getline(cin, title);
    
        cout << "Enter new Artist: ";
        getline(cin, artist);
    
        cout << "Enter new Album: ";
        getline(cin, album);
    
        cout << "Enter new Year: ";
        cin >> year;
    
        cout << "Enter new Track Number: ";
        cin >> track;
        cin.ignore(); // Ignore the newline character left in the buffer

        cout << "Enter new Genre: ";
        getline(cin, genre);

        TagLib::FileRef file(filePath.c_str());
    if (!file.isNull() && file.tag()) {
        TagLib::Tag *tag = file.tag();
        
        // Update the metadata
        tag->setTitle(title);
        tag->setArtist(artist);
        tag->setAlbum(album);
        tag->setYear(year);
        tag->setTrack(track);
        tag->setGenre(genre);

        // Save changes
        if (file.save()) {
            std::cout << "Metadata updated successfully.\n";
        } else {
            std::cerr << "Failed to save changes.\n";
        }
    } else {
        std::cerr << "Unable to open file for writing metadata.\n";
    }
}

void File::play() {
    // Load the audio file
    music = Mix_LoadMUS(filePath.c_str());
    if (music == NULL) {
        cout << "Failed to load music: " << Mix_GetError() << endl;
        return;
    }

    // Play the music
    if (Mix_PlayMusic(music, 0) == -1) {
        cout << "Mix_PlayMusic failed: " << Mix_GetError() << endl;
    } else {
        cout << "Playing music: " << filePath << endl;
    }
}

void File::pause() {
    if (Mix_PlayingMusic() && !Mix_PausedMusic()) {
        Mix_PauseMusic();
        cout << "Music paused." << endl;
    }
}

void File::show(){
        ifstream fileCheck(filePath.c_str());
    if (!fileCheck.good()) {
        cerr << "File does not exist or cannot be opened: " << filePath << "\n";
        return;
    }
    fileCheck.close();

    // Open the media file with TagLib
    TagLib::FileRef file(filePath.c_str());
    if (!file.isNull() && file.tag()) {
        TagLib::Tag *tag = file.tag();
        cout << "\nMetadata for file: " << filePath << "\n";
        cout << "------------------------------\n";
        cout << "Title: " << tag->title() << "\n";
        cout << "Publisher: " << tag->artist() << "\n";
        cout << "Album: " << tag->album() << "\n";
        cout << "Public Year: " << tag->year() << "\n";
        cout << "Track: " << tag->track() << "\n";
        cout << "Genre: " << tag->genre() << "\n";
    } else {
        cerr << "Unable to open file or read metadata.\n";
    }
}

void File::resume() {
    if (Mix_PausedMusic()) {
        Mix_ResumeMusic();
        cout << "Music resumed." << endl;
    }
}

int File::getCurrentTime() {
    if (Mix_PlayingMusic()) {
        return static_cast<int>(Mix_GetMusicPosition(music)); // Get current position in seconds
    }
    return 0; // Return 0 if music is not playing
}

int File::getDuration() {
    if (music) {
        return static_cast<int>(Mix_MusicDuration(music)); // Get total duration in seconds
    }
    return 0; // Return 0 if music is not loaded
}


File::~File() {}
