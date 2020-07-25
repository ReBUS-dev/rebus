//
// Created by Stepan Bezhuk on 12.07.2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <list>
#include <bitset>

#include "../../global_value.cpp"
#include "../../Core/lib/header/WorkFile.h"

#ifndef REBUSDEVBACKUP_CORE_H
#define REBUSDEVBACKUP_CORE_H

class WorkArchive : WorkFile {

public:
    explicit WorkArchive(std::string file_path);
    void create_archiv_proccess(std::vector<std::string>, std::string archive_name_custom);

    void create_archive(std::vector<std::string> path_name, std::string archive_name);
    int unpack_archiv(std::string archive_filename);

    std::string file_path;
};

#endif
