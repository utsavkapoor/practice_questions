#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

class Tree{
    void printlevel(node* root, int k);
    int compare(int a , int b);
    
public:
    Tree(node *root);
    node* insert(int num,node* root);
    node* del(int num, node* root);
    int search(int num, node* root);
    void preorder_disp(node* root);
    void postorder_disp(node *root);
    void inorder_disp(node *root);
    void bfs_disp(node *root);
    int height(node *root);
    int diameter(node *root);
    node* LCA(node *root, int a, int b);
    void ancestor(int k,node *root);
    node* getmin(node *root);
    node* getmax(node *root);
};

Tree::Tree(node *root){
    root = NULL;
}

node* Tree::insert(int num, node* root){
    if (root == NULL){
        node *temp = new node;
        temp->data = num;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
    }
    else if (num < root->data){
        root->left = insert(num,root->left);
    }
    else if (num > root->data){
        root->right = insert(num,root->right);
    }
    else{
        cout<<"Node already present"<<endl;
    }
    return root;
    
}


node* Tree::del(int num, node* root){
    if(root == NULL){
        cout<<"Node not found to delete"<<endl;
    }
    else if (root->data > num){
        root->left = del(num,root->left);
    }
    else if (root->data < num){
        root->right = del(num,root->right);
    }
    else if (root->data == num){//node found which is to be deleted
         
        if(root->left == NULL){
            node *random = root->right;
            free(root);
            return random;
        }
        else if (root->right == NULL){
            node *random = root->left;
            free(root);
            return random;
        }
        else{
            node *random1 = getmin(root->right);
            root->data = random1->data;
            root->right = del(random1->data,root->right);
        }
    
    }
    
    return root;

}

node* Tree::getmin(node* root){
    
    node* random = root;
    
    while(random->left != NULL){
        random = random->left;
    }
    return random;
}

node* Tree::getmax(node* root){
    
    node* random = root;
    
    while(random->right != NULL){
        random = random->right;
    }
    
    return random;
}

void Tree::ancestor(int k, node* root){// The Program suppose that the number is already in the tree
    
    node *random = root;
    int a[100], i=0;
    while (random != NULL){
        
        if (random->data > k ){
            a[i++] = random->data;
            random = random->left;
        }
        else if (random->data < k){
            a[i++] = random->data;
            random = random->right;
        }
        else if (random->data == k){
            
            for (int j=0;j<i;j++){
                cout<<a[j]<<" ";
            }
            cout<<endl;
            break;
        }
    }
    return;

}

int Tree::search(int num, node* root) {
    int k;
    if (root == NULL){
            cout<<"Number not found"<<endl;
            k = 0;
            return k;
    }
    if (num > root->data){
        search(num,root->right);
    }
    else{
        if(num < root->data){
            search(num,root->left);
        }
        else{
            cout<<"Number is Found"<<endl;
            k=1;
            return k;
           
        }
    }
 return 0;   
}



void Tree::inorder_disp(node *root){
    if (root!=NULL){
        inorder_disp(root->left);
        cout<<root->data<<" ";
        inorder_disp(root->right);
    }
    
}

void Tree::postorder_disp(node* root){
    if(root!=NULL){
        postorder_disp(root->left);
        postorder_disp(root->right);
        cout<<root->data<<" ";
    }

}

void Tree::preorder_disp(node* root){
    
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder_disp(root->left);
        preorder_disp(root->right);
    }

}


int Tree::height(node* root){
    int k=0;
    if (root==NULL){return 0;}
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight>rheight){
            return (1 + lheight);
        }
        else{
            return (1 + rheight);
        }
    }
    
}

void Tree::bfs_disp(node* root){
    int high = height(root);
    
    for (int i=1;i<=high;i++){
        printlevel(root,i);
    }
}

void Tree::printlevel(node* root, int k){
    if(root==NULL){return ;}
    if(k == 1){
        cout<<root->data<<" ";
    }
    else if (k > 1){
        printlevel(root->left,k-1);
        printlevel(root->right,k-1);
    
    }

}

int Tree::compare(int a, int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }

}
int Tree::diameter(node* root){
    if (root==NULL){return 0;}
    int lheight = height(root->left);
    int rheight = height(root->right);
    
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    
    return compare(lheight+rheight+1,compare(ldiameter,rdiameter));
    

}

node* Tree::LCA(node* root, int a, int b){//it is assumed that a is greater than b

    if (root == NULL){return NULL;}
    if(root->data > a && root->data < b){
        cout<<"I am here"<<endl;
        return root;
    }
    else if (root->data > b){
    
        return LCA(root->left,a,b);
    }
    else{
        return LCA(root->right,a,b);
    }
    cout<<"I am here also"<<endl;
    return root;
}




int main(){
    node *temp = NULL;
    Tree bst(temp);
    temp=bst.insert(10,temp);
    bst.insert(20,temp);
    bst.insert(4,temp);
    bst.insert(8,temp);
    bst.insert(28,temp);
    bst.insert(1,temp);
    bst.insert(100,temp);
    bst.preorder_disp(temp);
    cout<<endl;
    bst.search(8,temp);
    bst.search(9,temp);
    int m = bst.height(temp);
    cout<<m<<endl;
    bst.bfs_disp(temp);
    cout<<endl;
    int c = bst.diameter(temp);
    cout<<c<<endl;
    bst.postorder_disp(temp);
    cout<<endl;
    bst.inorder_disp(temp);
    cout<<endl;
    bst.ancestor(28,temp);
    node* random = bst.LCA(temp,1,8);
    cout<<random->data<<endl;
    return 0;
}


