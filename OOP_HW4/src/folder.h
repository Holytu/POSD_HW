#ifndef FOLDER_H
#define FOLDER_H
#include <string>
#include <sys/stat.h>
#include <vector>
#include "node.h"
using namespace std;

class Folder : public Node {
public:
    Folder(string path) : Node(path)
    {
        folder_path_str = path;
        stat(path.c_str(), &_st);

        if(S_ISDIR(_st.st_mode) == 0)
        {
            throw(string("It is not Folder!"));
            //throw(string("Node is not exist!"));
        }
    }

    void addChild(Node* child)
    {
        _v.push_back(child);
    }

    Node* getChild(int num)
    {
        return _v[num];
    }

    int infoByte()
    {
        int total = 0;
        for (int i = 0; i < _v.size() ; i++)
        {
            total = total + _v.at(i)->infoByte();
        }
        return total;
    }

    int vecSize()
    {
        return _v.size();
    }

    string findNode(string name)
    {
        vector<string> vec;

        if(_v.size() == 1 && _v[0]->name() == name)
        {
            return "./"+name;
        }

        this->DiveInFolders(name , &vec);

        for (int i = 0 ; i < vec.size() ; i++ )
        {
            vec[i].erase(0, this->returns_Path().size());
        }

        string str = "";

        for (int i = 0 ; i < vec.size() ; i++ )
        {
            str = str + "." + vec[i];
            if(i < vec.size() - 1 )
            {
                str = str + "\n";
            }
        }
        return str;
    }

    void DiveInFolders(string name, vector<string> *vec)
    {
        for (int i = 0 ; i < _v.size() ; i++)
        {
            if(_v[i]->name() == name)
            {
                vec->push_back(_v[i]->returns_Path());
            }
            struct stat st;
            stat(_v[i]->returns_Path().c_str(), &st);
            if(S_ISDIR(st.st_mode) == 1 )
            {
                _v[i]->DiveInFolders(name,vec);
            }
        }
    }

    string listNode()
    {
        string FoldersFiles = "";
        vector<string> sortNode;

        for (int i = 0 ; i < _v.size() ; i++ )// Folder
        {
            sortNode.push_back(_v[i]->name());
        }

        sort(sortNode.begin() , sortNode.end() );

        for (int i = 0 ; i < _v.size() ; i++ )
        {
            FoldersFiles = FoldersFiles + sortNode[i]+ " ";
        }
        FoldersFiles.erase(FoldersFiles.size() - 1 , 1 );

        return FoldersFiles;
    }

private:
    vector<Node*> _v;
    string _path = "";
    string folder_path_str = "";

    struct stat _st;
};
#endif
