/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a 
sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

1) Every adjacent pair of words differs by a single letter.
2) Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
3) sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest 
transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

Constraints:

1) 1 <= beginWord.length <= 10
2) endWord.length == beginWord.length
3) 1 <= wordList.length <= 5000
4) wordList[i].length == beginWord.length
5) beginWord, endWord, and wordList[i] consist of lowercase English letters.
6) beginWord != endWord
7) All the words in wordList are unique.
*/
#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    int endWordPresent = false;
    set<string> wordSet;
    
    // End word should be present in wordList
    for(int i=0 ; i < wordList.size(); i++)
    {
       if(endWord.compare(wordList[i]) == 0)
       {
           endWordPresent = true;
       }
       wordSet.insert(wordList[i]); 
    }
    
    if(!endWordPresent)
    return 0;
    
    std::queue<string> q;
    q.push(beginWord);
    
    int depth = 0;
    
    while(!q.empty())
    {
        depth +=1;
        
        int lsize = q.size();
        
        while(--lsize)
        {
            string curr = q.front();
            q.pop();
            
            for(int i=0; i < curr.size(); i++)
            {
                string tmp = curr;
                for(char c = 'a'; c <= 'z'; c++)
                {
                    tmp[i] = c;
                   
                    // Compare begin word and skip
                    if(curr.compare(tmp) == 0)
                        continue;
                   
                    if(curr.compare(endWord) == 0)
                    {
                       return depth+1;
                    }
                    
                    if(wordSet.find(tmp) != wordSet.end())
                    {
                       q.push(tmp);
                       wordSet.erase(tmp);
                    }
                   
                }
            }
        }
        
    }
}


int main()
{
    // create wordList
    vector<string> D;
    D.push_back("hot");
    D.push_back("dot");
    D.push_back("dog");
    D.push_back("lot");
    D.push_back("log");
    D.push_back("cog");
    string start = "hit";
    string target = "cog";
    std::cout <<ladderLength(start, target, D )<< std::endl;
	return 0;
}
