#include <vector>
#include <string>

#include "core/header/Core.h"

int main() {
    std::string path_config_backup = "../config/path_config.conf";

    Core* core_object = new Core(path_config_backup);
    std::vector<std::string> path = core_object->data_for_file();

    return 0;
}
