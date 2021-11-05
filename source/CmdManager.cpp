/*
** EPITECH PROJECT, 2019
** IA_Cmd
** File description:
** Cmd.c
*/

#include "CmdManager.hh"
#include "Cpu.hh"

Cmd::Cmd()
{
}

int Cmd::execCommandsFromStdin()
{
    std::vector<std::string> &&cmds = getCmdsFromStdin();
    for (auto &vect_cmd : cmds)
        getCmds(vect_cmd);
    return 0;
}

int Cmd::execCommandsFromfile(const std::string &av)
{
    std::vector<std::string> &&cmds = getCmdsFromfile(av);
    for (auto &vect_cmd : cmds)
        getCmds(vect_cmd);
    return 0;
}

// Get all commands and put it on vector
std::vector<std::string> Cmd::getCmdsFromStdin()
{
    std::string input_str = "";
    std::ofstream outfile;
    std::vector<std::string> cmds;
    cmds.reserve(50);

    while (1) {
        getline(std::cin, input_str);
        cmds.push_back(input_str);
        if (input_str == ";;")
            return (cmds);
    }
    return (cmds);
}

// Get all commands and put it on vector
std::vector<std::string> Cmd::getCmdsFromfile(const std::string &av)
{
    std::string line;
    std::ifstream myfile(av);
    std::vector<std::string> cmds;
    cmds.reserve(50);
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            getline(myfile, line);
            cmds.emplace_back(line);
        }
    } else {
        std::cout << "The file might not exit" << std::endl;
        return cmds;
    }
    myfile.close();
    return cmds;
}

int Cmd::getCmds(std::string &str)
{
    int return_value;
    std::string input_str = "";
    std::string first_word = "";

    if (str.empty())
        return 0;
    if (str == "" || str == ";")
        return 0;

    if (str.find(" ") == std::string::npos) {
        first_word = str;
    } else {
        first_word = str.substr(0, str.find_first_of(" "));
        str = str.substr(str.find_first_of(" ") + 1);
    }
    const auto &&iter = cmd_map.find(first_word);
    if (iter == cmd_map.end())
        return 82;
    return_value = ((this->cpu).*iter->second)(str);
    return return_value;
}

Cmd::~Cmd()
{
}
