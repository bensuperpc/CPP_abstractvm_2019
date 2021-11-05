/*
** EPITECH PROJECT, 2019
** AbstractVM
** File description:
** tests
*/

#include <string>
#include "CmdManager.hh"

int main(int argc, const char *argv[])
{
    Cmd cmd;
    if (argc > 1) {
        const std::string input(argv[1]);
        cmd.execCommandsFromfile(input);
    } else {
        cmd.execCommandsFromStdin();
    }
}
