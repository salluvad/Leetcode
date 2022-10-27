int countPrefix(string s)
{
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc == 0)
            return 0;   //No string with given prefix is present
        curr = curr->child[index];
    }
    return curr->wc;
}
