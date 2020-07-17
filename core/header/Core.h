//
// Created by Stepan Bezhuk on 12.07.2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <list>

#ifndef REBUSDEVBACKUP_CORE_H
#define REBUSDEVBACKUP_CORE_H

class Core {
private:
    std::string file_path;

public:
    explicit Core(std::string file_path);

    std::vector<std::string> data_for_file();
    std::list<std::string> scan_dir(const std::string& path);
};

#endif
