// Copyright 2014 Paul Eduard

#include <stdio.h>
#include <string>

#include "include/merge-sort-application.h"

int main(int argc, const char** argv) {
    SortApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
