/*
** EPITECH PROJECT, 2019
** epitech, 2019
** File description:
**  Cmd.hpp
*/

#ifndef _CMD_MANAGER_H_
#define _CMD_MANAGER_H_

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include "Cpu.hh"

class Cmd {
  public:
    // Variables
    // Methodes
    std::vector<std::string> getCmdsFromStdin();
    std::vector<std::string> getCmdsFromfile(const std::string &);
    int getCmds(std::string &);
    std::vector<std::string> saveCommands(std::string);
    int execCommandsFromStdin();
    int execCommandsFromfile(const std::string &);
    int checkCmd(std::vector<std::string>);

    // Constructeurs
    Cmd();
    // Destructeurs
    ~Cmd();

  private:
    // Variables
    Cpu cpu;
    std::map<const std::string, int (Cpu::*)(const std::string &)> cmd_map
        = {{"dup", &Cpu::dup}, {"push", &Cpu::push}, {"pop", &Cpu::pop}, {"clear", &Cpu::clear}, {"swap", &Cpu::swap},
            {"load", &Cpu::load}, {"store", &Cpu::store}, {"dup", &Cpu::dup}, {"assert", &Cpu::assert}, {"sub", &Cpu::sub},
            {"mul", &Cpu::mul}, {"div", &Cpu::div}, {"add", &Cpu::add}, {"mod", &Cpu::mod}, {"dump", &Cpu::dump},
            {"print", &Cpu::print}, {"exit", &Cpu::mExit}, {";;", &Cpu::mExit}};

  protected:
};

#endif
