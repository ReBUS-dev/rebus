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

std::vector<std::string> WorkFile::scan_dir(std::vector<std::string> &path) {
    std::vector<std::string> file_for_path;

    for (int iteration = 0; iteration < path.size(); iteration++) {
        for (const auto &path_file : std::filesystem::directory_iterator(path[ iteration ])) {
            if (std::filesystem::is_directory(path_file)) {
                path.push_back(path_file.path());
                std::cout << path_file.path() << std::endl;
                continue;
            }
            file_for_path.push_back(path_file.path());
        }
    }

    return file_for_path;
}



std::vector<std::string> WorkFile::working_once_dir(const std::string &path) {
    std::vector<std::string> file_for_path;

    if (std::filesystem::is_directory(path)) {
        file_for_path.push_back(path);
        return scan_dir(file_for_path);
    }

    file_for_path.push_back(path);
    return file_for_path;
}

std::vector<std::string> WorkFile::data_for_file(std::string file_path_conf) {
    std::vector<std::string> data_is_file;

    std::fstream path_file;
    path_file.open(file_path_conf, std::ios::in);

    if (path_file.is_open()) {
        std::string path;

        while (getline(path_file, path)) {
            data_is_file.push_back(path);
        }
        path_file.close();
    }

    return data_is_file;
}