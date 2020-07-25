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
private:
    std::string file_path;

public:
    explicit WorkArchive(std::string file_path);
    std::vector<std::string> data_for_file();
    void create_archiv_proccess(std::vector<std::string>);

    void create_archive(std::vector<std::string> path_name);
};

#endif
