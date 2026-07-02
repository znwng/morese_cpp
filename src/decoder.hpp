#ifndef DECODER_HPP
#define DECODER_HPP

#include "morse_tree.hpp"

#include <string>

char getMorseChar(const std::string& morse, node* root);
std::string decode(const std::string& message, node* root);

#endif // !DECODE_HPP

