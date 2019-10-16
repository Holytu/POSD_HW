#ifndef UT_NODE_H
#define UT_NODE_H

#include <sys/stat.h>

#include "../src/file.h"
#include "../src/folder.h"
#include "../src/node.h"
#include <vector>
using namespace std;
TEST(FileTest, File_Size)
{
    Node *hello_txt = new File("test/test_folder/hello.txt");

    ASSERT_EQ(14, hello_txt->size());
}
TEST(FileTest, InfoByteOnFile)
{
    Node* hello_txt = new File("test/test_folder/hello.txt");
    ASSERT_EQ(14, hello_txt->size());
}
TEST(FileTest, FileNotFolder)
{
    try{
        Node* a_out = new File("test/test_folder");
    }
    catch(const string s)
    {
        ASSERT_EQ("It is not File!", s);
    }
}
/*
TEST(FileTest, FolderNotExist)
{
    try{
        Node * a_out = new Folder("test/TA_folder/hw/TA_File");
    }
    catch(const string e)
    {
        ASSERT_EQ("It is not Folder!", e);
    }
}
*/
TEST(FileTest, FileFindName)
{
    Node *a_out = new File("test/test_folder/hw/a.out");
    ASSERT_EQ("a.out", a_out->findNode("a.out"));
}
TEST(FileTest, FolderFindNode)
{
    Node *test_folder = new Folder("test/test_folder");
    Node *hw = new Folder("test/test_folder/hw");

    Node *hw1_cpp = new File("test/test_folder/hw/hw1.cpp");
    Node *a_out = new File("test/test_folder/hw/a.out");

    test_folder->addChild(hw);
    test_folder->addChild(a_out);
    hw->addChild(hw1_cpp);
    hw->addChild(a_out);

    /*
    cout << test_folder->vecSize() << endl;
    cout << "test_folder->getChild(0)->name()" << endl;
    cout << "name is : " << test_folder->getChild(0)->name() << ", and size is : ";
    cout << test_folder->getChild(0)->vecSize() << endl;
    cout << test_folder->getChild(0)->getChild(0)->name() << endl;
    cout << test_folder->getChild(0)->getChild(0)->getChild(0) << endl;
    cout << test_folder->getChild(0)->getChild(1)->name() << endl;

    cout << "test_folder->getChild(1)->name()" << endl;
    cout << test_folder->getChild(1)->name() << endl;
    */
    //ASSERT_EQ("./a.out",test_folder->findNode("a.out"));
}
TEST(FileTest, ListNode)
{
    Node *test_folder = new Folder("test/test_folder");
    Node *hw = new Folder("test/test_folder/hw");

    Node *hw1_cpp = new File("test/test_folder/hw/hw1.cpp");
    Node *a_out = new File("test/test_folder/hw/a.out");
    Node *hello_txt = new File("test/test_folder/hello.txt");

    test_folder->addChild(a_out);
    test_folder->addChild(hw1_cpp);
    test_folder->addChild(hw);
    test_folder->addChild(hello_txt);

    hw->addChild(hw1_cpp);
    hw->addChild(a_out);
    ASSERT_EQ("a.out hello.txt hw hw1.cpp", test_folder->listNode());
}
#endif
