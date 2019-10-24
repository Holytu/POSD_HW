#ifndef NODE_H
#define NODE_H

#include <string>
#include <sys/stat.h>
using namespace std;

class Node {
public:
    Node(string path): _path(path) {
        stat(_path.c_str(), &_st);

        if(stat(_path.c_str(), &_st) == -1)
        {
            throw(string("Node is not exist!"));
        }
    }

    int size()
    {
        return _st.st_size;
    }

    virtual int vecSize()
    {
        return 0;
    }

    virtual int infoByte()
    {
        return size();
    }

    virtual void addChild(Node* child)
    {
        throw string("Invalid add!");
    }

    virtual Node* getChild(int num)
    {
        return nullptr;
    }

    virtual string name() //const = 0;
    {
        int i;
        for ( i = _path.size() - 1 ; _path[i] != '/' ; i-- ) {}

        string str = _path.substr(i+1, _path.size() - 1);
        return str;
    }

    virtual string findNode(string name) //const = 0;
    {
        return "";
    }

    virtual int findNodeResultCount()
    {
        return 2;
    }

    virtual string listNode() //const = 0;
    {
        return "";
    }

    virtual void DiveInFolders(string name, vector<string> *put)
    {
    }

    virtual string returns_Path()
    {
        return _path;
    }

private:
    std::string _path;
    struct stat _st;
};

#endif
