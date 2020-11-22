#ifndef SERVER_SRC_SERVER_SYSTEM_H_
#define SERVER_SRC_SERVER_SYSTEM_H_

#include <map>
#include <mutex>

class System {
 private:
    std::map<std::string,std::string> hardDrive;
    std::mutex getFileMtx;
    std::mutex loadFileMtx;
    std::mutex stdoutMtx;

 public:
    /* Constructor */
    System(std::string rootFile);

    std::string getFile(std::string fileName);

    void loadFile(std::string& fileName, std::string& file);

    void printOnScreen(std::string& str);

    /* Destructor */
    ~System();
};

#endif  // SERVER_SRC_SERVER_SYSTEM_H_
