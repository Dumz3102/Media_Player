#include "menu_play.hpp"
#include "menu_file.hpp"
#include "file.hpp"

void displaySongMenu(){
    int cmt;
    
    do{
        cout << "\nPlay song Menu:\n";
        cout << "1. Play a song\n";
        cout << "2. Play songs from a folder\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> cmt;

        switch (cmt) {
            case 1:
                printf("\e[1;1H\e[2J"); // Clear screen
                displayPlayFile(); // Play a song
                break;
            case 2:
                printf("\e[1;1H\e[2J"); // Clear screen
                managerFolder();   // Play songs in folder
                break;
            case 3:
                cout << "Exiting metadata management...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    while (cmt != 3);
}