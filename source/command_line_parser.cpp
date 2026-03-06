#include "utilities.h"
#include "command_line_parser.h"

#include <stdexcept>

bool is_valid_interger(std::string str)
{
    if (str.size() > 9) return false;
    for (char c: str)
    {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

bool is_valid_algorithm(std::string str) 
{
    if (str != "selection-sort" && 
        str != "insertion-sort" && 
        str != "binary-insertion-sort" &&
        str != "bubble-sort" && 
        str != "shaker-sort" && 
        str != "shell-sort" && 
        str != "heap-sort" && 
        str != "merge-sort" && 
        str != "quick-sort" && 
        str != "counting-sort" && 
        str != "radix-sort" && 
        str != "flash-sort")  
        return false;
    return true;
}

bool is_valid_input_file(std::string str)
{
    return str.size();
}

bool is_valid_output_parameter(std::string str)
{
    return str == "-time" || str == "-comp" || str == "-both";
}

bool is_valid_input_size(int n)
{
    return n > 0 && n <= 1e6;
}

bool is_valid_input_order(std::string str)
{
    return str == "-sorted" || str == "-nsorted" || str == "-rev" || str == "-rand";
}

bool is_valid_command (int argc, const Config &config)
{
    if (config.commandType < 1 || config.commandType > 5) return false;
    // if (config.mode != "-a" && config.mode != "-c") return false;
    if (config.commandType == 1)
    {
        return is_valid_algorithm(config.algorithm1) && is_valid_input_file(config.inputFile) && is_valid_output_parameter(config.outputParameter);
    }
    else if (config.commandType == 2)
    {
        return is_valid_algorithm(config.algorithm1) && is_valid_input_size(config.inputSize) && is_valid_input_order(config.inputOrder) && is_valid_output_parameter(config.outputParameter);
    }
    else if (config.commandType == 3)
    {
        return is_valid_algorithm(config.algorithm1) && is_valid_input_size(config.inputSize) && is_valid_output_parameter(config.outputParameter);
    }
    else if (config.commandType == 4)
    {
        return is_valid_algorithm(config.algorithm1) && is_valid_algorithm(config.algorithm2) && config.algorithm1 != config.algorithm2 && is_valid_input_file(config.inputFile);
    }
    else if (config.commandType == 5)
    {
        return is_valid_algorithm(config.algorithm1) && is_valid_algorithm(config.algorithm2) && config.algorithm1 != config.algorithm2 && is_valid_input_size(config.inputSize) && is_valid_input_order(config.inputOrder);
    }
    else throw std::runtime_error("Invalid arguments!");
}

void report_error()
{
    throw std::runtime_error("Invalid arguments!");
}

Config parse_command(int argc, char* argv[])
{
    if (argc < 5) 
    {
        report_error();
    }

    Config config;
    config.commandType = -1;
    config.mode = argv[1];

    if (config.mode == "-a")
    {
        config.algorithm1 = argv[2];
        if (argc == 6) //type 2
        {
            config.commandType = 2;
            if (!is_valid_interger(std::string(argv[3]))) report_error();
            config.inputSize = std::stoi(std::string(argv[3]));
            config.inputOrder = argv[4];
            config.outputParameter = argv[5];
        }
        else if (argc == 5)
        {
            config.outputParameter = argv[4];
            if (is_valid_interger(std::string(argv[3])) == false) //type 1
            {
                config.commandType = 1;
                config.inputFile = argv[3];
            }
            else //type 3
            {
                config.commandType = 3;
                config.inputSize = std::stoi(std::string(argv[3]));
            }
        }
    }
    else if (config.mode == "-c" && argc >= 5)
    {
        config.algorithm1 = argv[2];
        config.algorithm2 = argv[3];
        if (argc == 5) //type 4
        {
            config.commandType = 4;
            config.inputFile = argv[4]; 
        }   
        else if (argc == 6) //type 5
        {
            config.commandType = 5;
            if (!is_valid_interger(argv[4])) report_error();
            config.inputSize = std::stoi(std::string(argv[4]));
            config.inputOrder = argv[5];
        }
    }

    if (!is_valid_command(argc, config))
    {
        report_error();
    }

    return config; 
}