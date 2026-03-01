#ifndef ENCODER_HPP
#define ENCODER_HPP

#include "morse_tree.hpp"

#include <string>
#include <vector>

bool getCharMorse(char target, node* root, std::string& path);
std::vector<std::string> encode(const std::string& message, node* root);

#endif

