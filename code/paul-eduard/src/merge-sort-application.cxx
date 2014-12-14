// Copyright 2014 Paul Eduard

#include "include/merge-sort.h"
#include "include/merge-sort-application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

SortApplication::SortApplication() : arr(0), message_(""), N(0) {}

void SortApplication::help(const char* appname, const char* message = "") {
    message_ = std::string(message)
             + std::string("This is a sort application.\n\n")
             + "Please provide arguments in the following format:\n\n"
             + "  $ " + appname + " <argument1> <argument2> <argument3> "
             + "and so on.\n\nWhere first argument is integer number that "
             + "means count of elements, and other are integer numbers that "
             + "you want to sort.\n";
}

int64_t parseInteger(const char* arg);
int64_t parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);
    if (end[0]) {
        throw "Wrong number format";
    }
    return value;
}

bool SortApplication::parseArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc == 2) {
        help(argv[0], "ERROR: Should be 2 or more arguments.\n\n");
        return false;
    }

    try {
        N = static_cast<unsigned int>(parseInteger(argv[1]));
    }
    catch(...) {
        message_ = "Wrong number of elements format!\n";
        return false;
    }

    if ((argc-2) != static_cast<int>(N)) {
        message_ = "Wrong number of elements!\n";
        return false;
    }

    try {
        for (unsigned int i = 0; i < N; i++) {
            arr.push_back(parseInteger(argv[2 + i]));
        }
    }
    catch(...) {
        message_ = "Wrong numbers format!\n";
        return false;
    }

    return true;
}

std::string SortApplication::operator()(int argc, const char** argv) {
    bool returnCode = parseArguments(argc, argv);
    if (returnCode != true)
        return message_;

    std::ostringstream stream;
    stream << "Result: ";

    Merge_Sort(&arr, 0, N-1);
    for (unsigned int i = 0; i < N; i++)
        stream << arr[i] << " ";

    message_ = stream.str();

    return message_;
}
