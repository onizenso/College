#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

#ifndef LISTELEM
#define LISTELEM int
#endif

using namespace std;

struct TreeNode{
    LISTELEM data;
    TreeNode *left;
    TreeNode *right;
};

struct BST{
    TreeNode *root;
    int count;
};

int count = 1;

void centerstring(char *);
void nextline();
bool isInteger(char *); 

TreeNode *createNode(LISTELEM element, 
                    TreeNode *lchild, 
                    TreeNode *rchild);

void initTree(BST*);
bool empty(BST*);
bool empty(TreeNode*);

void deallocate(BST*);
void deallocateSubtree(TreeNode*);

bool insert(BST*, LISTELEM);
bool insertSubtree(TreeNode*, LISTELEM);

TreeNode *search(BST*, LISTELEM);
TreeNode *searchSubtree(TreeNode*, LISTELEM);

void inorderPrint(BST*);
void inorderSubtree(TreeNode*);

bool remove(BST*, LISTELEM);

int main(){
    char header[56] = {"Binary Search Tree Menu"};
    char c;
    int i = 0;

    LISTELEM key = 0;

    ifstream fin;
    ofstream fout;

    char infile[56];
    char outfile[56];

    BST tree;
    initTree(&tree);
    
    do{
        centerstring(header);
        cout<< setw(50) << setfill('=') << "" << endl;
        cout<< "1. Read values from file & insert to tree" << endl;
        cout<< "2. Search the tree for a value" << endl;
        cout<< "3. Delete a value from the tree" << endl;
        cout<< "4. Print the values of the tree in sorted order" << endl;
        cout<< endl;
        cout<< "0. Exit" << endl;
        cout<< setw(50) << setfill('=') << "" << endl;
        cin >> c;

        switch(c){
            case '1':
                cout<< "Enter input file name (include extension) :";
                cin>> setw(512) >> infile;
                cin.ignore(1000, '\n');
                if(cin.fail()){
                    cout<< "File name is too long" << endl;
                    exit(1);
                }

            fin.open(infile);
            if(fin.fail()){
                cout<< "Failed to open " << infile << " for reading." << endl;
                exit(1);
            }

            
            while(fin >> i){
                if(isalpha(i))
                    cout<< "Kill yourself, thats some invalid input." << endl;
                
                insert(&tree, i);
            }

            fin.clear();
            fin.close();

            break;
        
            case '2':
                cout<< "Enter a search value: ";
                cin >> key;

                if(search(&tree, key) == NULL){
                    cout<< "Value was not found in BST" << endl;
                }
                else{
                    cout<< endl;
                    cout<< "Value was found at " << search(&tree, key) << endl;
                }

                break;

            case '3':
                cout<< "Enter a value to remove: ";
                cin >> key;

                if(remove(&tree, key))
                    cout << key << " successfully removed from tree." << endl;
                else
                    cout << key << " not found in tree." << endl;

            case '4':
                inorderPrint(&tree);
                cout << endl << endl;
                break;
    }


    }while(c != '0');

    cout<< "Deallocating the subtree." << endl;

    deallocate(&tree);

    cout<< endl;
    cout<< "Successfully deallocated the Binary Search Tree" << endl;
    cout<< endl;

return 0;
}

void centerstring(char *s){
    int len = strlen(s);
    int pos = (int)((50-len)/2);
    for(int i = 0; i < pos; i++)
        cout<< " ";

    cout<< s << endl;
return;
}

void nextline(){
    if(count == 5){
        cout<< endl;
        count = 0;
    }
    ++count;
}

bool isInteger(char *input){
    int intbool;

    while(intbool = isdigit(*(input++)));

    return intbool ? true : false;
}

void initTree(BST *tree){
    tree->root = NULL;
    tree->count = 0;
}

bool empty(BST *tree){
    return tree->root == NULL;
}

bool empty(TreeNode *root){
    return root == NULL;
}

TreeNode *createNode(LISTELEM element, 
                    TreeNode *lchild = NULL, 
                    TreeNode *rchild = NULL){
    TreeNode *tmp = NULL;
    try{
        tmp = new TreeNode;
    } catch(bad_alloc){
        cout<< "Allocation failed" << endl;
        return NULL;
    }
    tmp->data = element;
    tmp->left = lchild;
    tmp->right = rchild;

    return tmp;
}


bool insertSubtree(TreeNode *subroot, LISTELEM elem){
    if(elem < subroot->data){
        if(subroot->left)
            return insertSubtree(subroot->left, elem);
        else
            subroot->left = createNode(elem);
            return ((subroot->left) ? true : false);    
    }
    else if(elem > subroot->data){
        if(subroot->right)
            return insertSubtree(subroot->right, elem);
        else{
            subroot->right = createNode(elem);
            return ((subroot->right) ? true : false);
        }
    }
    else{
        cout<< "Error: no duplicate entries " << elem << endl;
        return false;
    }
}

bool insert(BST *tree, LISTELEM elem){
    if(empty(tree)){
        tree->root = createNode(elem);
        if(!tree->root){
            cout<< "Out of memory" << endl;
            return false;
        }
    }
    else
        return insertSubtree(tree->root, elem);
}

TreeNode *search(BST *tree, LISTELEM elem){
    if(empty(tree)){
        cout<< "Tree is empty, insert items" << endl;
        return NULL;
    }
    else if(elem < tree->root->data){
        if(empty(tree->root->left))
            return NULL;
        else
            return searchSubtree(tree->root->left, elem);
    }
    else if(elem == tree->root->data)
        return tree->root;
    else{ 
        if(empty(tree->root->right))
            return NULL;
        else
            return searchSubtree(tree->root->right, elem);
    }
}

TreeNode *searchSubtree(TreeNode *subroot, LISTELEM key){
    if(key < subroot->data){
        if(!subroot->left)
            return NULL;
        else
            return searchSubtree(subroot->left, key);
    }
    else if(key == subroot->data)
        return subroot;
    else{
        if(!subroot->right)
            return NULL;
        else
            return searchSubtree(subroot->right, key);
    }
}

void inorderPrint(BST *tree){
    if(empty(tree)){
        cout<< "Tree is empty." << endl;
        return;
    }
    else 
       return inorderSubtree(tree->root);
}

void inorderSubtree(TreeNode *subroot){
    if(subroot->left){
        inorderSubtree(subroot->left);
    }
    
    cout<< subroot->data << " ";
    nextline();
    
    if(subroot->right){
        inorderSubtree(subroot->right);
    }
}

void deallocate(BST *tree){
    if(empty(tree)){
        cout<< "Tree has no members to deallocate" << endl;
        return;
    }

    deallocateSubtree(tree->root);
}

void deallocateSubtree(TreeNode *subroot){
    if(subroot->left){
        deallocateSubtree(subroot->left);
    }
    if(subroot->right){
        deallocateSubtree(subroot->right);
    }
    
    cout<< "Deallocating: ";
    cout<< subroot->data << " " << endl;
    delete subroot;
}

bool remove(BST *tree, LISTELEM key){
    bool found = false;
    TreeNode *node = tree->root;
    TreeNode *parent = NULL;
    
    while(!found && node){
        if(key == node->data){
            found = true;
            break;
        }
        else if(key < node->data){
            parent = node;
            node = node->left;
        }
        else{
            parent = node;
            node = node->right;
        }
    }

    if(!found)
        return false;
    
    if(node->left && node->right){
        TreeNode *replacement = node->right;
        while(replacement->left){
            parent = replacement;
            replacement = replacement->left;
        }
        node->data = replacement->data;
        node = replacement;
    }

    TreeNode *subtree = node->right;
    
    if(!subtree)
        subtree = node->left;

    if(!parent)
        tree->root = subtree;
    else{
        if(node -> data < parent->data)
            parent->left = subtree;
        else
            parent->right = subtree;
    }

    delete node;
}
