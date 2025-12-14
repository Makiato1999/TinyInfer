#include <glog/logging.h>
#include <iostream>

int main(int argc, char* argv[]) {
    google::InitGoogleLogging(argv[0]);
    LOG(INFO) << "Hello, World!";
    std::cout << "This is a simple C++17 application using glog." << std::endl;
    return 0;
}