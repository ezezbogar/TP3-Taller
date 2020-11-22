#ifndef SERVER_SRC_SERVER_SYSTEM_H_
#define SERVER_SRC_SERVER_SYSTEM_H_

#include <map>
#include <mutex>
#include <string>

class System {
 private:
    std::map<std::string, std::string> hardDrive;
    std::string rootFile;
    std::mutex getFileMtx;
    std::mutex loadFileMtx;
    std::mutex stdoutMtx;

 public:
    /* Constructor */
    explicit System(std::string rootFile);

    std::string getFile(std::string fileName);

    void loadFile(const std::string& fileName, const std::string& file);

    void printOnScreen(const std::string& str);

    std::string getRootFile();

    /* Destructor */
    ~System();
};

#endif  // SERVER_SRC_SERVER_SYSTEM_H_
