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

    std::vector<std::string> scan_dir(const std::string& path);

    static char *read_file_data(std::string path_file);
};


#endif //REBUSDEVBACKUP_WORKFILE_H
