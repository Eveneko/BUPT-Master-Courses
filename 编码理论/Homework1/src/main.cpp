#include "huffmanTree.h"

using namespace HuffmanTree;

int main() {
    std::map<char, int> _alphabet = {{'a', 5}, {'b', 4}, {'c', 3}, {'d', 2}, {'e', 1}};
    std::map<char, std::string> _codeMap;

    huffmanTree tree(_alphabet);
    tree.huffmanCode(_codeMap);

    for(auto x : _codeMap) {
        printf("%c: %s\n", x.first, x.second.c_str());
    }

    return 0;
}