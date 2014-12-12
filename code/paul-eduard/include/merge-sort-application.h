// Copyright 2014 Paul Eduard

#ifndef CODE_PAUL_EDUARD_INCLUDE_MERGE_SORT_APPLICATION_H_
#define CODE_PAUL_EDUARD_INCLUDE_MERGE_SORT_APPLICATION_H_

#include <stdint.h>
#include <string>
#include <vector>

class SortApplication {
 public:
    SortApplication();
    SortApplication(const SortApplication&);

    std::string operator()(int argc, const char** argv);

 private:
    std::vector<int64_t> arr;
    std::string message_;
    unsigned int N;
    void help(const char* appname);
    bool parseArguments(int argc, const char** argv);
};


#endif  // CODE_PAUL_EDUARD_INCLUDE_MERGE_SORT_APPLICATION_H_
