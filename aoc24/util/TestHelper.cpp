//
// Created by mins on 12/2/2024.
//

#include "TestHelper.h"

#include <fstream>
#include <string>
#include <vector>

using namespace TestHelper;

std::string TestHelper::readFileToString(const std::string &fileName)
{
    std::ifstream ifs(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

    std::ifstream::pos_type fileSize = ifs.tellg();
    if (fileSize < 0)
        return {};

    ifs.seekg(0, std::ios::beg);

    std::vector<char> bytes(fileSize);
    ifs.read(&bytes[0], fileSize);

    return {&bytes[0], fileSize};
}

std::vector<std::string> TestHelper::tokenize( const std::string& str, const std::string&  delim )  {
    std::vector<std::string> result;
    std::string_view sv(str);

    while (!sv.empty()) {
        auto pos = sv.find(delim);
        if (pos == std::string_view::npos) {
            result.emplace_back(sv);
            break;
        }
        result.emplace_back(sv.substr(0, pos));
        sv.remove_prefix(pos + delim.size());
    }

    return result;
}
