#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Trie {
public:
    // below is the TrieNode which contains a character and wordend and array of TrieNode pointers to next character.
    class TrieNode{
        public:
      char data;
        int we;
        TrieNode* child[26];
        TrieNode(char ch)
        {
            if(ch!='0')
                data=ch;
            for(int i=0;i<26;i++)
                child[i]=NULL;
            we=0;
        }
    };

    TrieNode* root;
    // initialize the root of the Trie.
    Trie(){
        root= new TrieNode('0');
    }
    // for inserting a new string to our trie data structure 
    void insert_util(TrieNode* node,int i,string word){
        // make here the word ending by making we= we+1.
        if(i==word.size())
        {
            node->we+=1;
            return;
        }
        // if the next character is not present then we need to create a new TrieNode
        if(node->child[word[i]-'a']==NULL){
            node->child[word[i]-'a']=new TrieNode(word[i]);
        }
        // recursive call for the next character
        insert_util(node->child[word[i]-'a'],i+1,word);
    }

    // object call to insert function
    void insert_in_trie(string word){
        insert_util(root,0,word);
    }

    // for searching a given string in our trie
    bool search_util(TrieNode* node,int i,string word){
        // checking that is there a word end here in Trie
        if(i==word.size()){
            if(node->we>0)
                return true;
            return false;
        }

        // if no path in front return false
        if(node->child[word[i]-'a']==NULL)
            return false;

        // recursive call to search
        return search_util(node->child[word[i]-'a'],i+1,word);
    }

    // object call to search function
    bool search_in_trie(string word){
        return search_util(root,0,word);
    }

    // for deleting a given string in our trie
    void delete_util(TrieNode* node,int i,string word){
        // if word end, we need to check whether there is really a word or not, then delete
        if(i==word.size()){
            if(node->we>0){
                node->we= node->we-1;
                cout<<word<<" successfully deleted from trie \n";
            }
            else
                cout<<"no such word named "<<word<<" in trie \n";

            return;
        }

        // if front path not there return
        if(node->child[word[i]-'a']==NULL){
            cout<<"no such word named "<<word<<" in trie \n";
            return;
        }

        // recursive call to delete
        delete_util(node->child[word[i]-'a'],i+1,word);
    }

    // object call to delete function
    void delete_from_trie(string word){
        delete_util(root,0,word);
    }
};
int main(){
    // for fast input output
    ios_base::sync_with_stdio(false);  cin.tie(NULL);

    // initial work
    Trie* trie= new Trie();

    // inserting into trie
    vector<string>insertstr={"acgbd","acbdb","bamcdo"};
    for(auto word:insertstr){
        trie->insert_in_trie(word);
    }

    // deleting words
    vector<string>delstring={"acbdb","bbdcd"};
    for(auto word:delstring){
        trie->delete_from_trie(word);
    }

    // searching for words
    vector<string>srchwords={"acbdb","bamcd","acgbd"};
    for(auto word:srchwords){
        if(trie->search_in_trie(word))
            cout<<word<<" is found \n";
        else
            cout<<word<<" not found \n";
    }
}
