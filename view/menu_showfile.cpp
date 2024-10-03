#include"menu_showfile.hpp"

void displayMediaFile(){
    string Folder_Path;
    cout << "Enter the path of folder: ";
    getline(cin, Folder_Path);

    // Check if the file exists
    if (!filesystem::exists(Folder_Path)) {
        cout << "Error: The specified file does not exist. Please try again.\n";
        cout << "\nPress any key to return to the main menu...";
        cin.ignore();  // To clear the input buffer.
        return; // Exit the function if the file doesn't exist
    }

    Folder folder(Folder_Path);

    folder.showAllMediaFiles();

    cout << "\nPress any key to return to the main menu...";
    cin.ignore();  // To clear the input buffer.


}