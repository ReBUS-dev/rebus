//
// Created by Stepan Bezhuk on 25.07.2020.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

#ifndef REBUSDEVBACKUP_WORKFILE_H
#define REBUSDEVBACKUP_WORKFILE_H


class WorkFile {

public:

    std::vector<std::string> scan_dir(std::vector<std::string> &path);
    std::vector<std::string> working_once_dir(const std::string &path);

    static char *read_file_data(std::string path_file);

    std::vector<std::string> data_for_file(std::string file_path_conf);
};


#endif //REBUSDEVBACKUP_WORKFILE_H
