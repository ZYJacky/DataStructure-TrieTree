/*
 *                                          TrieNode.h 
 * 
 *          Defines the class TrieNode that represents each node in a Trie tree.
 * 
 *                                    Last modified: 1/3/22
 */

#ifndef TRIENODE_H
#define TRIENODE_H

#include <vector>
#include <string>

class TrieNode
{
    public:
        TrieNode();
        TrieNode(char _c, int _val = 1);

        void insert(std::string, int val = 1);
        bool find(std::string);
        int find_val(std::string);
        bool modify(std::string, int);

    private:
        char c;                         // character at this node
        int val;                        // value associated with the character (e.g. count)
        std::vector<TrieNode*> next;    // hold the children
};

#endif