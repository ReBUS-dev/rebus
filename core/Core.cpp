//
// Created by Stepan Bezhuk on 12.07.2020.
//

#include "header/Core.h"

using namespace std;

Core::Core(string file_path) {
    this->Core::file_path = move(file_path);
}

vector<string> Core::data_for_file() {
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

list<string> Core::scan_dir(const string& path) {
    list<string> file_for_path;

    for (const auto & path_file : filesystem::directory_iterator(path)) {
        file_for_path.push_front(path_file.path());
    }

    return file_for_path;
}
