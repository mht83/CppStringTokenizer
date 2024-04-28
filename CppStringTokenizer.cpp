//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


std:: vector<std:: string> splitStringByDelimiters(const std:: string& str, const std:: string delimiters) {
    std:: vector<std:: string> tokens;
    std:: string token;
    int start = 0, end = 0;

    while ((end = str.find_first_of(delimiters.data(), start)) != std::string::npos) {
        if (end != start) {
            token = str.substr(start, end - start);
            tokens.push_back(token);
        }
        start = end + 1;
    }

    if (start < str.size()) {
        tokens.push_back(str.substr(start));
    }

    return tokens;
}

int main() {
    std::string input = "this,is.a sample!!";
    std::string delimiters = ",.! ";
    std::vector<std::string> output = splitStringByDelimiters(input, delimiters);

    std::cout << "Input: \"" << input << "\"\nOutput: {";
    for (int i = 0; i < output.size(); ++i) {
        std::cout << "\"" << output[i] << "\"";
        if (i < output.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";

    return 0;
}
