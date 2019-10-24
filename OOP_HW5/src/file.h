#ifndef FILE_H
#define FILE_H
#include <string>
#include <sys/stat.h>
#include "node.h"
using namespace std;
class File : public Node {
public:
    File(string path) : Node(path)
    {
        path_str = path;

        stat(path.c_str(), &_st);
        if(S_ISREG(_st.st_mode) == 0)
        {
            throw string("It is not File!");
        }
    }

    string findNode(std::string name)
    {
        return this->name();
    }

    string listNode()
    {
        return "";
    }
private:
    string path_str = "";
    struct stat _st;
};
#endif
