//
// Created by Stepan Bezhuk on 12.07.2020.
//

#include "header/WorkArchive.h"

using namespace std;

void read_to_archive(ofstream *archive_name, string path_file) {
    unsigned long long file_size = filesystem::file_size(path_file);
    const char *file = WorkFile::read_file_data(path_file);

    *archive_name << filesystem::path(path_file).filename().string();

    archive_name->write((char*) "\0", 1);
    archive_name->write((char*) &file_size, 8);
    archive_name->write(file, filesystem::file_size(path_file));
}

int unpack_proccess(ifstream *file_stream_archive) {
    while (!file_stream_archive->eof()) {
        string filename;
        getline(*file_stream_archive, filename, '\0');

        if (file_stream_archive->eof()) {
            break;
        }

        unsigned long long file_size;
        file_stream_archive->read( (char*) &file_size, 8);
        if (file_stream_archive->eof()) {
            cerr << "The archive is damaged, I can't find the size!\n";
            return 1;
        }

        char* file = new char[file_size];
        file_stream_archive->read(file, file_size);
        if (file_stream_archive->eof()) {
            cerr << "The archive is corrupt, I can't find the files!\n";
            return 1;
        }

        ofstream file_stream (filename, ios::binary);
        if (!file_stream.is_open()) {
            cerr << "I have no rights to record!\n";
            return 1;
        }

        file_stream.write(file, file_size);

        delete[](file);
        file_stream.close();
    }

    return 0;
}

void WorkArchive::create_archive(vector<string> path_name, string archive_name_custom) {
    ofstream archive_name(archive_name_custom + FORMAT_ARCHIVE, ios::app);
    string signatura = FORMAT_ARCHIVE + "><";

    archive_name << signatura;

    for (auto & iterations : path_name) {
        read_to_archive(&archive_name, iterations);
    }
}

void WorkArchive::create_archiv_proccess(std::vector<std::string> path, string archive_name) {
    std::vector<std::string> full_data_archive;

    for (auto & iterations : path) {
        full_data_archive.push_back(iterations);
    }

    create_archive(full_data_archive, archive_name);
}

int WorkArchive::unpack_archiv(std::string archive_filename) {
    ifstream file_stream_archive (archive_filename, ios::binary);
    char signatura[6];

    file_stream_archive.read(signatura, 6);

    if (memcmp(signatura, ".rbb><", 6)) {
        cerr << "This is not a rbb archive\n";
        return 1;
    }
    else {
        unpack_proccess(&file_stream_archive);
    }

    return 0;
}

WorkArchive::WorkArchive(string file_path) {
    this->WorkArchive::file_path = move(file_path);
}

