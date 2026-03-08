#include "command_line_parser.h"
#include "file_manager.h"
#include "dispatch_sorting_algorithm.h"
#include "data_generator.h"

#include <iostream>

int main(int argc, char *argv[])
{
    try
    {
        Config config = parse_command(argc, argv);
        ArrayData data;
        if (config.mode == "-a")
        {
            if (config.commandType == 1)
            {
                read_file(config.inputFile, data);
                config.inputSize = data.dataSize;
                SortResult result = dispatch_sorting_algorithm(config.algorithm1, data);
                write_file("output.txt", data);
                write_console_1(config, result);
            }
            else if (config.commandType == 2)
            {
                data.dataSize = config.inputSize;
                GenerateData(data.element, data.dataSize, config.inputOrder);
                write_file("input.txt", data);
                SortResult result = dispatch_sorting_algorithm(config.algorithm1, data);
                write_console_2(config, result);
                write_file("output.txt", data);
            }
            else if (config.commandType == 3)
            {
                data.dataSize = config.inputSize;

                GenerateData(data.element, data.dataSize, "-rand");
                write_file("input_1.txt", data);
                SortResult result1 = dispatch_sorting_algorithm(config.algorithm1, data);

                GenerateData(data.element, data.dataSize, "-nsorted");
                write_file("input_2.txt", data);
                SortResult result2 = dispatch_sorting_algorithm(config.algorithm1, data);   

                GenerateData(data.element, data.dataSize, "-sorted");
                write_file("input_3.txt", data);
                SortResult result3 = dispatch_sorting_algorithm(config.algorithm1, data);   

                GenerateData(data.element, data.dataSize, "-rev");
                write_file("input_4.txt", data);
                SortResult result4 = dispatch_sorting_algorithm(config.algorithm1, data); 

                write_console_3(config, result1, result2, result3, result4);               
            }
        }
        else 
        {
            if (config.commandType == 4)
            {
                read_file(config.inputFile, data);
                config.inputSize = data.dataSize;
                ArrayData dataCoppy = data;
                SortResult result1 = dispatch_sorting_algorithm(config.algorithm1, data);  
                SortResult result2 = dispatch_sorting_algorithm(config.algorithm2, dataCoppy);  
                write_console_4(config, result1, result2);
            }
            else if (config.commandType == 5)
            {
                data.dataSize = config.inputSize;
                GenerateData(data.element, data.dataSize, config.inputOrder);
                write_file("input.txt", data);
                ArrayData dataCoppy = data;
                SortResult result1 = dispatch_sorting_algorithm(config.algorithm1, data);  
                SortResult result2 = dispatch_sorting_algorithm(config.algorithm2, dataCoppy);
                write_console_5(config, result1, result2);
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Please check the usage and try again." << '\n';
        return 1;
    }
    
    return 0;
}