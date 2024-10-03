#include"menu_playlist.hpp"

static PlaylistManager manager;  // Static variable to persist across multiple calls

void displayPLaylistMenu(){
    // Initialize SDL audio subsystem
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }

    // Initialize SDL_mixer, check if the audio subsystem is correctly opened
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        SDL_Quit();
        return;
    }

//    PlaylistManager manager;
    char option;

    do {
        std::cout << "\nPlaylist Manager\n";
        std::cout << "1. List Playlists\n";
        std::cout << "2. View Playlist\n";
        std::cout << "3. Create/Add song to Playlist\n";
        std::cout << "4. Delete Playlist\n";
        std::cout << "5. Play Playlist\n";
        std::cout << "0. Exit\n";
        std::cout << "Select an option: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (option) {
            case '1': {
                printf("\e[1;1H\e[2J"); // Clear screen
                std::cout << std::endl;
                manager.listPlaylists();
                break;
            }
            case '2': {
                printf("\e[1;1H\e[2J"); // Clear screen
                std::string playlistName;
                std::cout << "\nEnter playlist name: ";
                getline(cin,playlistName);
                manager.viewPlaylist(playlistName);
                break;
            }
            case '3': {
                printf("\e[1;1H\e[2J"); // Clear screen
                std::string playlistName;
                std::cout << "\nEnter playlist name: ";
                getline(cin,playlistName);
                manager.createOrUpdatePlaylist(playlistName);
                break;
            }
            case '4': {
                printf("\e[1;1H\e[2J"); // Clear screen
                std::string playlistName;
                std::cout << "\nEnter playlist name: ";
                getline(cin,playlistName);
                manager.deletePlaylist(playlistName);
                break;
            }
            case '5': {
                printf("\e[1;1H\e[2J"); // Clear screen
                std::string playlistName;
                std::cout << "\nEnter playlist name: ";               
                getline(cin,playlistName);
                manager.playPlaylist(playlistName);
                break;
            }
            case '0':
                std::cout << "Exiting...\n";
                break;
            default:
                std::cerr << "Invalid option.\n";
        }
    } while (option != '0');

}