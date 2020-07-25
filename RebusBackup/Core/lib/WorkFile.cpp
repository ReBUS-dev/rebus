//
// Created by Stepan Bezhuk on 25.07.2020.
//

#include "header/WorkFile.h"

char *WorkFile::read_file_data(std::string path_file) {
    std::ifstream file_data(path_file);

    char *data_file = new char [ std::filesystem::file_size(path_file) ];

    file_data.read(data_file, std::filesystem::file_size(path_file));

    return data_file;
}

std::vector<std::string> WorkFile::scan_dir(const std::string &path) {
    std::vector<std::string> file_for_path;

    if (!std::filesystem::is_directory(path)) {
        file_for_path.push_back(path);
        return file_for_path;
    }

    for (const auto &path_file : std::filesystem::directory_iterator(path)) {
        if (std::filesystem::is_directory(path_file)) {
            continue;
        }

        file_for_path.push_back(path_file.path());
    }

    return file_for_path;
}