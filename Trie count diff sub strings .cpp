// brute force is run two loops and find sub strung from i to j , TC is (n2 * n(sub string))

//other optimization is instead of using sub string we need to use string appending 

// to get distinct substrings , put them into set which take another logn time 

// efficient approach is to use a trie  , O(n^2)


int countDistinctSubstring(string str)
{
    TrieNode* head = new TrieNode();
 
    // will hold the count of unique substrings
    int count = 0;
    // included count of substr " "
 
    for (int i = 0; i < str.length(); i++) {
        TrieNode* temp = head;
 
        for (int j = i; j < str.length(); j++) {
            // when char not present add it to the trie
            if (temp->child[str[j] - 'a'] == NULL) {
                temp->child[str[j] - 'a'] = new TrieNode();
                temp->isWord = 1;
                count++;
            }
            // move on to the next char
            temp = temp->child[str[j] - 'a'];
        }
    }
 
    return count;
}
