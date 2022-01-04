# data_structure-TrieTree

Simple implementation of a Trie tree in C++

## Examples

```
Trie root;

root.insert("hello");

int ret_val = root.find_val("hello");
if(ret_val < 0) cout << "word does not exist in Trie" << std::endl; 
```
