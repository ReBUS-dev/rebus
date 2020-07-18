//
// Created by Stepan Bezhuk on 12.07.2020.
//

#include "header/Core.h"

using namespace std;

char *read_file_data(string path_file) {
    ifstream file_data(path_file);

    char *data_file = new char [ filesystem::file_size(path_file) ];

    file_data.read(data_file, filesystem::file_size(path_file));

    return data_file;
}

void read_to_archive(ofstream *archive_name, string path_file) {
    unsigned long long file_size = filesystem::file_size(path_file);

    *archive_name << filesystem::path(path_file).filename();

    archive_name->write((char*) "\0", 1);
    archive_name->write((char*) &file_size, 8);
    archive_name->write(read_file_data(path_file), filesystem::file_size(path_file));
}

void create_archive(vector<string> path_name, string path = "") {
    ofstream archive_name("archive" + FORMAT_ARCHIVE, ios::app);
    string signatura = FORMAT_ARCHIVE + "><";

    archive_name << signatura;

    if (!path.empty()) {
        read_to_archive(&archive_name, path);
    } else {
        for (int iterations = 0; iterations < path_name.size(); ++iterations) {
            read_to_archive(&archive_name, path_name[ iterations ]);
        }
    }
}

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

vector<string> Core::scan_dir(const string &path) {
    vector<string> file_for_path;

    if (!filesystem::is_directory(path)) {
        create_archive(file_for_path, path);

        return file_for_path;
    }

    for (const auto &path_file : filesystem::directory_iterator(path)) {
        if (filesystem::is_directory(path_file)) {
            continue;
        }

        file_for_path.push_back(path_file.path());
    }

    create_archive(file_for_path);

    return file_for_path;
}