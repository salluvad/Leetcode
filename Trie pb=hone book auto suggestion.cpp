#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode {
 unordered_map<char , TrieNode*> child;
 bool is_end;

 //constructor
 TrieNode(){
  for(char ch = 'a' ; ch<='z' ; ch++){
     child[ch] = NULL;
  }
  is_end = false ;
 }

};


TrieNode* root = NULL;

void insert(string s){
 int len = s.length();
 //start form root
 TrieNode* itr = root;
 for(int i = 0 ; i<len ;i++){
   char ch = s[i];
   TrieNode* newNode = itr->child[ch];
   if(newNode == NULL){
   // create a node and link it as child
    newNode = new TrieNode();
    itr->child[ch] = newNode;
   }
   itr = itr->child[ch];   // itr = newNode;
  //last char
   if(i == len-1){
    itr->is_end = true ;
   }

 }
}

// add search and delete func
// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->child[index])
            return false;

        pCrawl = pCrawl->child[index];
    }

    return (pCrawl->is_end);
}

//Delete Func

// C++ implementation of delete
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Returns true if root has no children, else false
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

// Recursive function to delete a key from given Trie
TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
    // If tree is empty
    if (!root)
        return NULL;

    // If last character of key is being processed
    if (depth == key.size()) {

        // This node is no more end of word after
        // removal of given key
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // If given is not prefix of any other word
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }

        return root;
    }

    // If not last character, recur for the child
    // obtained using ASCII value
    int index = key[depth] - 'a';
    root->children[index] =
          remove(root->children[index], key, depth + 1);

    // If root does not have any child (its only child got
    // deleted), and it is not end of another word.
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = NULL;
    }

    return root;
}

// display Util , just like DFS of a node
void displayUtil(TrieNode* curr , string prefix){
   if(curr->is_end){
      cout << prefix << endl;
   }
    // check all child for a curr node recurisvely
   for(char ch = 'a' ; ch<='z';ch++){
     if(curr->child[ch]!=NULL){
       displayUtil(curr->child[ch] , prefix+ch);
     }
    }

}


// display suggestions

void display(string s){
   TrieNode* prev = root ;
   string prefix = "";
   int len = s.length();
   //go through each char in str
   int i ;
   for(i = 0 ; i<len;i++){
   //add it to prefix
    prefix+=s[i];
    char LastChar = s[i];
   TrieNode* curr = prev->child[LastChar];
    if(curr == NULL){
    cout << "NO RESULTS";
    i++;
    break;
    }
    cout << "suggestions based on prefix " << prefix << "are" << endl;
    displayUtil(curr,prefix);

    prev = curr;
   }

   // for all char after non existing chars in trie , print No results
   for(;i<len;i++){
     prefix+= s[i];
   cout << "suggestions based on prefix " << prefix << "are" << endl;
   }
}


// Insert all the Contacts into the Trie
void insertIntoTrie(string contacts[],int n)
{
    // Initialize root Node
    root = new TrieNode();

    // Insert each contact into the trie
    for (int i = 0; i < n; i++)
        insert(contacts[i]);
}

int main()
{
    // Contact list of the User
    string contacts[] = {"gforgeeks" , "geeksquiz"};

    // Size of the Contact List
    int n = sizeof(contacts)/sizeof(string);

    // Insert all the Contacts into Trie
    insertIntoTrie(contacts, n);

    string query = "gekk";

    // Note that the user will enter 'g' then 'e', so
    // first display all the strings with prefix as 'g'
    // and then all the strings with prefix as 'ge'
    display(query);

    return 0;
}

