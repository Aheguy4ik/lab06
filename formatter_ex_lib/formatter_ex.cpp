#include "formatter_ex.h"
#include <fstream>

void print_ex(const std::string& text) {
    std::ofstream out("log.txt");
    out << text;
    out.close();
}
