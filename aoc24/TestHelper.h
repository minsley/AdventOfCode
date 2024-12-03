//
// Created by mins on 12/2/2024.
//

#ifndef TESTHELPER_H
#define TESTHELPER_H

namespace TestHelper {
    std::string ReadFileToString(const std::string &fileName);
    std::vector<std::string> tokenize(const std::string& p_pcstStr, const std::string& delim);
}

#endif //TESTHELPER_H
