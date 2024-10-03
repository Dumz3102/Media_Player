#ifndef FOLDER_HPP
#define FOLDER_HPP

#include"file.hpp"
#include<map>
namespace fs = std::filesystem;

class Folder{
private:
    string FolderPath;
    vector<File> folder;
public:
    Folder(string FolderPath);
    Folder(string FolderPath, vector<File> folder);
    void setFolderPath(string FolderPath);
    string getFolderPath();

    void showAllMediaFiles();


};

#endif