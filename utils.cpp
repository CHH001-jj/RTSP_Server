#include "utils.h"
#include <iostream>
#include <regex>

double Mp4ToH264AndAac(std::string filepath) {
    if (std::remove("output.h264") == 0) {
        std::cout << "Successfully deleted output.h264" << std::endl;
    } else {
        std::cerr << "Failed to delete output.h264" << std::endl;
    }

    if (std::remove("output.aac") == 0) {
        std::cout << "Successfully deleted output.aac" << std::endl;
    } else {
        std::cerr << "Failed to delete output.aac" << std::endl;
    }
    const std::string command = "ffmpeg -i " + filepath + " -c:v libx264 -b:v 1000k -an -f h264 output.h264 -c:a aac -b:a 128k -vn -f adts output.aac 2>&1";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Failed to run FFmpeg command." << std::endl;
        return 0;
    }

    // 读取命令输出并查找帧率
    char buffer[128];
    std::string output;
    while (fgets(buffer, sizeof(buffer), pipe)) {
        output += buffer;
    }
    fclose(pipe);

    // 使用正则表达式查找帧率
    std::regex fps_regex("([0-9]+(?:\\.[0-9]+)?) fps");
    std::smatch match;
    if (std::regex_search(output, match, fps_regex)) {
        std::cout << "Frame rate: " << match[1] << " fps" << std::endl;
    } else {
        std::cerr << "Frame rate not found!" << std::endl;
    }
    return std::stod(match[1]);

}