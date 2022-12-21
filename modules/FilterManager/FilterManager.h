#pragma once
#include "../Filters/Filter.h"
#include <sstream>


class FilterManager {
public:
    FilterManager() = default;
    ~FilterManager() = default;

    bool CreateFilters(int argc, char **argv);
    void Start(Image &image);
private:
    bool GetInt(char * str, int & a);
    bool GetDouble(char * str, double & a);
    std::vector<Filter*> filters_;
};
