/*
 *                                          TrieNode.cpp
 * 
 *          Implements member functions declared in TrieNode.h
 * 
 *                                    Last modified: 1/3/22
 */

#include "../inc/TrieNode.h"
#include <iostream>

// default constructor
TrieNode::TrieNode():val(0) {}

// constructor for special use
TrieNode::TrieNode(char _c, int _val):c(_c), val(_val) {}

// insert a word into the tree, value default to 1 meaning ocurrence
void TrieNode::insert(std::string str, int _val)
{   
    TrieNode* cur_node = this;
    val += _val;
    bool exist = false;

    for(int i = 0; i < str.length(); ++i)
    {   
        exist = false;
        for(auto node : cur_node->next)
        {   
            // already has a node
            if(node->c == str[i])
            {
                cur_node = node;
                node->val += _val;
                exist = true;
                break;
            }
        }

        if(!exist) 
        {   
            TrieNode* new_node = new TrieNode(str[i], _val);
            cur_node->next.push_back(new_node);
            cur_node = new_node;
        }
    }
}

// check whether a word exists; this is separated
bool TrieNode::find(std::string str)
{   
    TrieNode* cur_node = this;
    bool exist = false;
    for(int i = 0; i < str.length(); ++i)
    {   
        exist = false;
        for(auto node : cur_node->next)
        {
            if(node->c == str[i])
            {
                cur_node = node;
                exist = true;
                break;
            }
        }
        if(!exist) return false;
    }
    return true;
}

// return the value associated with a str (default to ocurrence of words starting with str)
int TrieNode::find_val(std::string str)
{   
    TrieNode* cur_node = this;
    bool exist = false;
    for(int i = 0; i < str.length(); ++i)
    {   
        exist = false;
        for(auto node : cur_node->next)
        {
            if(node->c == str[i])
            {
                cur_node = node;
                exist = true;
                break;
            }
        }
        if(!exist) return 0;
    }
    return cur_node->val;
}

// add or subtract value associated with a string
bool TrieNode::modify(std::string str, int delta)
{   
    if(!find(str)) return false; // verify word exist

    TrieNode* cur_node = this;
    cur_node->val += delta;

    for(int i = 0; i < str.length(); ++i)
    {   
        for(auto node : cur_node->next)
        {
            if(node->c == str[i])
            {
                cur_node = node;
                node->val += delta;
                break;
            }
        }
    }
    return true;
}