#include <utility>
#include <vector>
#include <list>
#include "core/header/Core.h"

void get_files(const std::string& one_path);

Core *core_object;

int main(int argc, char **argv) {
    std::string default_path;

    if (argv[1] && argv[2] && argv[1] == std::string("--PD")) {
        default_path = argv[2];
    }

    get_files(default_path);

    return 0;
}

void get_files_for_patch(std::string path_config_backup) {
    core_object = new Core(std::move(path_config_backup));

    std::vector<std::string> path = core_object->data_for_file();

    std::vector<std::string> file_in_dir = core_object->scan_dir(path[0]);
}

void get_files_of_key_dir(const std::string& current_dir) {
    core_object = new Core(PATH_CONF);

    std::vector<std::string> file_in_dir = core_object->scan_dir(current_dir);
}

void get_files(const std::string& one_path) {
    if (one_path.empty()) {
        get_files_for_patch(PATH_CONF);
    } else {
        get_files_of_key_dir(one_path);
    }
}
