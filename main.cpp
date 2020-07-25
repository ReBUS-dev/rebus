#include <utility>
#include <vector>
#include <list>
#include "RebusBackup/lib/header/WorkArchive.h"

void get_files(const std::string& one_path, std::string name);

WorkArchive *archive_work;
WorkFile *file_work;

int main(int argc, char **argv) {
    std::string default_path;
    std::string name = "archive";

    if (!strcmp(argv[1], "-c") && strcmp(argv[2], "-n")) {
        default_path = argv[2];
    }

    if (!strcmp(argv[1], "-u") && argv[2]) {
        char* archive_filename;
        archive_filename = argv[2];

        archive_work->unpack_archiv(archive_filename);

        return 0;
    }

    if (!strcmp(argv[1], "-c")) {
        if (argv[2] && !strcmp(argv[2], "-n") && argv[3]) {
            name = argv[3];
        }

        get_files(default_path, name);
    }

    return 0;
}

void get_files_for_patch(std::string path_config_backup, std::string name) {
    archive_work = new WorkArchive(std::move(path_config_backup));

    std::vector<std::string> path = file_work->data_for_file(archive_work->file_path);

    std::vector<std::string> file_in_dir = file_work->scan_dir(path);

    archive_work->create_archiv_proccess(file_in_dir, name);
}

void get_files_of_key_dir(const std::string& current_dir, std::string name) {
    archive_work = new WorkArchive(PATH_CONF);

    std::vector<std::string> file_in_dir = file_work->working_once_dir(current_dir);

    archive_work->create_archiv_proccess(file_in_dir, name);
}

void get_files(const std::string& one_path, std::string name) {
    if (one_path.empty()) {
        get_files_for_patch(PATH_CONF, name);
    } else {
        get_files_of_key_dir(one_path, name);
    }
}
