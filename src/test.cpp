#include "../inc/TrieNode.h"

#include <iostream>
#include <map>

int main()
{   
    TrieNode root;

    // testing default insertion
    root.insert("test");
    root.insert("test1");
    root.insert("test");

    if(root.find_val("") != 3
       || root.find_val("test1") != 1
       || root.find_val("test") != 3)
       std::cout << "Default insertion failed" << std::endl;
    // end testing default insertion

    return 0;
}