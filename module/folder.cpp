    #include"folder.hpp"

    Folder::Folder(string FolderPath) : FolderPath(FolderPath){}

    Folder::Folder(string FolderPath, vector<File> folder) : FolderPath(FolderPath), folder(folder){}

    void Folder::setFolderPath(string FolderPath){FolderPath = FolderPath;}

    string Folder::getFolderPath(){return FolderPath;}

    void Folder::showAllMediaFiles() {
    map<fs::path, vector<fs::path>> filesByDirectory;
    vector<fs::path> allMediaFiles; // For collecting all media files

    // Supported media extensions (you can add more as needed)
    vector<string> supportedExtensions = { ".mp3", ".wav", ".flac", ".mp4", ".avi", ".mkv", ".mov" };

    // Iterate through all files and group them by folder
    for (const auto& entry : fs::recursive_directory_iterator(FolderPath)) {
        if (entry.is_regular_file()) {
            fs::path fullPath = entry.path(); // Get full path of the file
            string ext = fullPath.extension().string();
            
            // Check if the file has a supported extension
            if (std::find(supportedExtensions.begin(), supportedExtensions.end(), ext) != supportedExtensions.end()) {
                allMediaFiles.push_back(fullPath); // Collect all media files in a single list
            }
        }
    }

    // Pagination logic: Display 25 files per page
    size_t pageSize = 25;
    size_t totalFiles = allMediaFiles.size();
    size_t totalPages = (totalFiles + pageSize - 1) / pageSize;

    if (totalFiles == 0) {
        std::cout << "No media files found in the folder.\n";
        return;
    }

    size_t currentPage = 0;
    char userInput;

    do {
        // Clear the console (optional, for readability between pages)
        std::system("clear");

        // Calculate the range for the current page
        size_t start = currentPage * pageSize;
        size_t end = std::min(start + pageSize, totalFiles);

        std::cout << "Displaying files " << start + 1 << " to " << end << " of " << totalFiles << "\n";

        // Display files for the current page
        for (size_t i = start; i < end; ++i) {
            std::cout << allMediaFiles[i] << "\n";
        }

        // Show page navigation options
        std::cout << "\nPage " << (currentPage + 1) << " of " << totalPages << "\n";
        if (currentPage > 0) {
            std::cout << "[p] Previous page\n";
        }
        if (currentPage < totalPages - 1) {
            std::cout << "[n] Next page\n";
        }
        std::cout << "[q] Quit\n";

        std::cout << "Enter your choice: ";
        std::cin >> userInput;

        // Handle user input for pagination
        if (userInput == 'n' && currentPage < totalPages - 1) {
            ++currentPage;
        } else if (userInput == 'p' && currentPage > 0) {
            --currentPage;
        } else if (userInput == 'q') {
            break;
        }

    } while (userInput != 'q');
}