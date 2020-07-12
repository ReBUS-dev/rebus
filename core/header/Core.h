//
// Created by Stepan Bezhuk on 12.07.2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

#ifndef REBUSDEVBACKUP_CORE_H
#define REBUSDEVBACKUP_CORE_H

class Core {
private:
    std::string file_path;

public:
    explicit Core(std::string file_path);

    std::vector<std::string> data_for_file();
};

#endif //REBUSDEVBACKUP_CORE_H
