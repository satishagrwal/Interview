#include <unordered_map>

using namespace std;

class LRUCache {
private:

   struct Node {
      int key;
      int value;
      Node* pre;
      Node* post;
   };

unordered_map<int, Node*> cache;
int count;
int capacity;
Node* head;
Node* tail;

// Add new node right after head
void addNode(Node* node)
{
   node->pre = head;
   node->post = node;

   head->post->pre = node;
   head->post = node;
}

// Remove an existing node from linklist
void removeNode(Node* node)
{
    Node* pre = node->pre;
    Node* post = node->post;

    pre->post = post;
    post->pre = pre;
}

// Mve node in between to head
void moveToHead(Node* node)
{
   removeNode(node);
   addNode(node);
}

// Pop the current tail
Node* popTail()
{
   Node* res = tail->pre;
   removeNode(res);
   return res;
}


public:
  LRUCache(init capacity)
  {
     this->count = 0;
     this->capacity = capacity;

     head = new Node();
     head->pre = nullptr;

     tail = new Node();
     tail->post = nullptr;

     // Create link 
     head->post = tail;
     rail->pre = head;
  }

  int get(int key)
  {
      if(cache.find(key) == cache.end())
      {
          return -1;
      }
      Node* node = cache[key];
      moveToHead(node);
      return node->value;
  }

  void put(int key, int value)
  {
      if(cache.find(key) == cache.end())
      {
          Node* newNode = new Node();
          newNode->key = key;
          newNode->value = value;

          cache[key] = newNode;
          addNode(newNode);

          ++count;

         if(count>capacity)
         {
              // pop tail
              Node* tailNode = popTail();
              cache.erase(tailNode->key);
              --count;
         }
      }
      else
      {
          // Update value and move to front
          Node* node = cache[key];
          node->value = value;
          moveToHead(node);
      } 
  }
};


















