#include <utility>
#include <vector>
#include <list>
#include "RebusBackup/lib/header/WorkArchive.h"

void get_files(const std::string& one_path);

WorkArchive *archive_work;
WorkFile *file_work;

int main(int argc, char **argv) {
    std::string default_path;

    if (!strcmp(argv[1], "-c") && argv[2]) {
        default_path = argv[2];
    }

    if (!strcmp(argv[1], "-u") && argv[2]) {
        char* archive_filename;
        archive_filename = argv[2];

        archive_work->unpack_archiv(archive_filename);

        return 0;
    }

    if (!strcmp(argv[1], "-c")) {
        get_files(default_path);
    }

    return 0;
}

void get_files_for_patch(std::string path_config_backup) {
    archive_work = new WorkArchive(std::move(path_config_backup));

    std::vector<std::string> path = archive_work->data_for_file();

    std::vector<std::string> file_in_dir = file_work->scan_dir(path[0]);

    archive_work->create_archiv_proccess(file_in_dir);
}

void get_files_of_key_dir(const std::string& current_dir) {
    archive_work = new WorkArchive(PATH_CONF);

    std::vector<std::string> file_in_dir = file_work->scan_dir(current_dir);

    archive_work->create_archiv_proccess(file_in_dir);
}

void get_files(const std::string& one_path) {
    if (one_path.empty()) {
        get_files_for_patch(PATH_CONF);
    } else {
        get_files_of_key_dir(one_path);
    }
}
