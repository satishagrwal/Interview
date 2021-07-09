#include <bits/stdc++.h>
using namespace std;


struct Trie
{
    struct Trie *Node[26];
    bool end;
    
    string meaning;
};

struct Trie *getNode()
{
    struct Trie *pNode = new Trie();
    
    pNode->end = false;
    
    for(int i =0; i < 26 ;i++)
    {
        pNode->Node[i] = NULL;
    }
    
    return pNode;
}

void addWord(struct Trie *root, string word, string meaning)
{
    struct Trie *pTemp = root;
    
    for(int i =0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        
        if(!pTemp->Node[index])
        {
            pTemp->Node[index] = getNode(); 
        }
        
        pTemp= pTemp->Node[index];
    }
    
    pTemp->end = true;
    pTemp->meaning = meaning;
}


string findWord(struct Trie* root, string word)
{
    struct Trie *pTemp = root;
    
    for(int i =0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        
        if(!pTemp->Node[index])
        {
            return "Word not found"; 
        }
        pTemp= pTemp->Node[index];  
    }
    
    return (pTemp->meaning);
}

int main()
{
    // Considering equal size of array
    string word[] = {"one", "two", "three",
                    "four", "five", "six",
                     "seven", "eight" };
    
    string mean[] = {"ek", "do", "teen",
                    "char", "pach", "chha",
                     "saat", "aath" };                 
                     
    int n = sizeof(word)/sizeof(word[0]);
 
    struct Trie *root = getNode();
 
    // Construct trie
    for (int i = 0; i < n; i++)
    {
        addWord(root, word[i], mean[i]);
    }
    
    // Search for different keys
    for (int i = 0; i < n; i++)
    {
      cout<<word[i]<<"-->"<<findWord(root,word[i])<<endl;
    }
    
    return 0;
}
