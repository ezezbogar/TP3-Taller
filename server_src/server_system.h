#ifndef SERVER_SRC_SERVER_SYSTEM_H_
#define SERVER_SRC_SERVER_SYSTEM_H_

#include <map>
#include <mutex>
#include <string>

class System {
 private:
    std::map<std::string, std::string> hardDrive;
    std::string rootFile;
    std::mutex FilesMtx;
    std::mutex stdoutMtx;

 public:
    /* Constructor */
    explicit System(std::string rootFile);

    /* Constructor por copia borrado */
    System(const System& system) = delete;

    /* Asignacion por copia borrado */
    System operator=(const System& system) = delete;

    /* Devuelve un string con el contenido del "archivo"
     * con el nombre de fileName */
    std::string getFile(std::string fileName);

    /* Guarda el contenido de file con el nombre de fileName */
    void loadFile(const std::string& fileName, const std::string& file);

    /* Printea por pantalla el contenido de str (thread-safe) */
    void printOnScreen(const std::string& str);

    /* Devuelve un string con el nombre del rootfile */
    std::string getRootFile();

    /* Destructor */
    ~System();
};

#endif  // SERVER_SRC_SERVER_SYSTEM_H_
