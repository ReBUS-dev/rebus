//
// Created by Stepan Bezhuk on 12.07.2020.
//

#include "header/Core.h"

using namespace std;

Core::Core(std::string file_path) {
    this->Core::file_path = move(file_path);
}

std::vector<std::string> Core::data_for_file() {
    vector<string> data_is_file;

    fstream path_file;
    path_file.open(Core::file_path, ios::in);

    if (path_file.is_open()) {
        string path;

        while (getline(path_file, path)) {
            data_is_file.push_back(path);
        }

        path_file.close();
    }

    return data_is_file;
}
