#ifndef COMMAND_LINE_PARSER_H 
#define COMMAND_LINE_PARSER_H

#include "utilities.h"

bool is_number(std::string str);
bool is_valid_algorithm(std::string str);
bool is_valid_input_file(std::string str);
bool is_valid_output_parameter(std::string str);
bool is_valid_input_size(int n);
bool is_valid_input_order(std::string str);
bool is_valid_command(int argc, const Config &config);

void report_error();

Config parse_command(int argc, char* argv[]);

#endif // COMMAND_LINE_PARSER_H