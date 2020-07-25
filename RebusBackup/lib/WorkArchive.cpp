//
// Created by Stepan Bezhuk on 12.07.2020.
//

#include "header/WorkArchive.h"

using namespace std;

void read_to_archive(ofstream *archive_name, string path_file) {
    unsigned long long file_size = filesystem::file_size(path_file);
    const char *file = WorkFile::read_file_data(path_file);

    *archive_name << filesystem::path(path_file).filename();

    archive_name->write((char*) "\0", 1);
    archive_name->write((char*) &file_size, 8);
    archive_name->write(file, filesystem::file_size(path_file));
}

void WorkArchive::create_archive(vector<string> path_name) {
    ofstream archive_name("archive" + FORMAT_ARCHIVE, ios::app);
    string signatura = FORMAT_ARCHIVE + "><";

    archive_name << signatura;

    for (auto & iterations : path_name) {
        read_to_archive(&archive_name, iterations);
    }
}

void WorkArchive::create_archiv_proccess(std::vector<std::string> path) {
    std::vector<std::string> full_data_archive;

    for (auto & iterations : path) {
        full_data_archive.push_back(iterations);
    }

    create_archive(full_data_archive);
}

WorkArchive::WorkArchive(string file_path) {
    this->WorkArchive::file_path = move(file_path);
}

vector<string> WorkArchive::data_for_file() {
    vector<string> data_is_file;

    fstream path_file;
    path_file.open(WorkArchive::file_path, ios::in);

    if (path_file.is_open()) {
        string path;

        while (getline(path_file, path)) {
            data_is_file.push_back(path);
        }
        path_file.close();
    }

    return data_is_file;
}

//#include <iostream>
//#include <fstream>
//#include <cstring>
//#include <string>
//
//using namespace std;
//
//int main (int argc, char* argv[]) {
//    char* archive_filename;
//    if (!strcmp(argv[1], "-d")) {
//        archive_filename = argv[2];
//    }
//
//    ifstream file_stream_archive (archive_filename, ios::binary);
//    char magic[6];
//    file_stream_archive.read(magic, 6);
//
//    if (memcmp(magic, ".rbb><", 6)) {
//        cerr << "This is not a rbb archive\n";
//        return 1;
//    }
//
//    while (!file_stream_archive.eof()) {
//        string filename;
//        getline(file_stream_archive, filename, '\0');
//
//        if (file_stream_archive.eof()) {
//            break;
//        }
//
//        unsigned long long file_size;
//        file_stream_archive.read( (char*) &file_size, 8);
//        if (file_stream_archive.eof()) {
//            cerr << "Кривий архів.\n";
//            return 1;
//        }
//
//        char* file = new char[file_size];
//        file_stream_archive.read(file, file_size);
//        if (file_stream_archive.eof()) {
//            cerr << "Кривий архів.\n";
//            return 1;
//        }
//
//        ofstream file_stream (filename, ios::binary);
//        if (!file_stream.is_open()) {
//            cerr << "Не можу писати.\n";
//            return 1;
//        }
//
//        file_stream.write(file, file_size);
//
//        delete(file);
//        file_stream.close();
//    }
//
//    return 0;
//}
