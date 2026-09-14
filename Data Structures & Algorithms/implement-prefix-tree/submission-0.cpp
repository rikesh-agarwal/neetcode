class PrefixTree {
struct TrieNode {
    bool is_end;
    TrieNode* child[26];

    TrieNode() {
        is_end=false;
        for(int i=0;i<26;i++) child[i]=nullptr;
    }
};

TrieNode* head;

public:
    PrefixTree() {
        head=new TrieNode();
    }

    TrieNode* searchPrefix(string& word) {
        TrieNode* curr=head;

        for(char ch:word) {
            int index = ch-'a';
            if(curr->child[index]==nullptr) return nullptr;
            curr=curr->child[index];
        }

        return curr;
    }
    
    void insert(string word) {
        TrieNode* curr=head;

        for(char ch: word) {
            int index = ch-'a';
            if(curr->child[index]==nullptr) curr->child[index] = new TrieNode();
            curr=curr->child[index];
        }

        curr->is_end=true;
    }

    bool search(string word) {
        TrieNode* curr = searchPrefix(word);
        if(curr==nullptr) return false;
        return curr->is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = searchPrefix(prefix);
        if(curr==nullptr) return false;
        return true;
    }
};



