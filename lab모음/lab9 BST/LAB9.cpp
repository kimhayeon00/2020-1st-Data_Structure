#include<iostream>
using namespace std;

class Node{
	private:
		int data;
		Node *left;
		Node *right;
		Node(int value){ data = value; left = 0; right = 0;}
	friend class Tree;
};

class Tree{
    private:
        Node *root;
    public:
        Tree(){root = 0;}
        ~Tree();
        void insertTree(int);
        void deleteTree(int);
        void searchTree(int);
        void traverseTree();
        void NumOfNodes();
        void freeBST(Node *);
        void LevelOrder();
        bool Level(Node *, int);
        Node *insertBST(Node *, int);
        Node *deleteBST(Node *, int);
        Node *searchBST(Node *, int);
        void traverseBST(Node *, int);
        Node *findmax(Node *);
        int countNonLeaves(Node *,int);
        int countLeaves(Node *, int);
        int isEmpty();

};

Tree::~Tree()
{
    freeBST(root);
}

void Tree::insertTree(int key)
{
    insertBST(root,key);
}

void Tree::deleteTree(int key)
{
    Node* ptr = root;
	deleteBST(ptr, key);
}

void Tree::searchTree(int key)
{
    if(searchBST(root, key)!=NULL)
        cout << key << " is found in the Tree " << endl ;
    else 
        cout << key << " is not found in the Tree " << endl ;

}
void Tree::traverseTree()
{
    traverseBST(root, 1);
}
void Tree::LevelOrder()
{
    int level = 1;
    while(Level(root,level))
        level++;
}
void Tree::freeBST(Node *p)
{
    if (p != 0) {
        freeBST(p->left);
        freeBST(p->right);
        delete p;
    }
}

void Tree::NumOfNodes()
{
    int count = 0;
    cout <<"Non leaves : " << countNonLeaves(root, count) << endl;
    cout << "leaves : " << countLeaves(root, count) << endl;
    
}
// Node *Tree::insertBST(Node *ptr, int key)
// {
//     Node *p;
// 	if (ptr == NULL) {
// 		ptr = new Node(key);
// 		ptr->data = key;
// 		ptr->left = NULL;
// 		ptr->right = NULL;
//         if(!root)
//             root = ptr;
		
// 	}
	
// 	else if (key < ptr->data) {
// 		ptr->left = insertBST(ptr->left, key);
// 	}
// 	else if (key > ptr->data) {
// 		ptr->right = insertBST(ptr->right, key);
// 	}
// 	return ptr;
// }

Node *Tree::insertBST(Node *ptr, int key)
{
    Node *p, *q;
    p = root;
    q = root;
	if (ptr == NULL) {
		ptr = new Node(key);
		ptr->data = key;
		ptr->left = NULL;
		ptr->right = NULL;
        if(!root)
            root = ptr;
		
	}

    while(p !=NULL){
        q = p;
        if(key < ptr -> data)
        p = ptr -> left;
        else p = ptr -> right;
    }

    if(key < q->data){
        Node *r = new Node(key);
        q -> left = r;

    }
    else{
        Node *r = new Node(key);
        q->right = r;
    }

}
Node *Tree::deleteBST(Node *ptr, int key){
     if(ptr != NULL) {
        if(key < ptr->data)
            ptr->left = deleteBST(ptr->left, key);
        else if(key > ptr->data)
            ptr->right = deleteBST(ptr->right, key);
        else if((ptr->left == NULL) && (ptr->right == NULL))
            ptr = NULL;
        else if(ptr->left == NULL) {
            Node *p = ptr;
            ptr = ptr->right;
            delete(p);
        }
        else if(ptr->right == NULL) {
            Node *p = ptr;
            ptr = ptr->left;
            delete(p);
        }
        else {
            Node *temp = findmax(ptr->left);
            ptr->data = temp->data;
            ptr->left = deleteBST(ptr->left, ptr->data);
        }
    }
    
    else cout << "Not found" << endl;
    return ptr;
}

Node *Tree::findmax(Node *ptr)
{
   if (ptr->right == NULL)
	{
		return ptr;		//right가 비어있으면 해당 ptr 반환
	}
	else
		findmax(ptr->right);
    return ptr;
}

Node *Tree::searchBST(Node *ptr, int key)
{
    if (ptr == NULL) return NULL; 
    else {
        if (key == ptr->data) return ptr;
        else if (key <ptr->data)
        ptr = searchBST(ptr->left, key); 
        else if (key > ptr->data)
        ptr = searchBST(ptr->right, key); 
    }
 return ptr;
}
void Tree::traverseBST(Node *p, int level)
{
    if (p != 0 && level <= 7) {
        traverseBST(p->right, level+1);
        for (int i = 1; i <= (level-1); i++)
            cout << "     ";
        cout << p->data;
        if (p->left != 0 && p->right != 0) cout << " <" << endl;
        else if (p->right != 0) cout << " /" << endl;
        else if (p->left != 0) cout << " \\" << endl;
        else cout << endl;
        traverseBST(p->left, level+1);
    }
}

int Tree::countLeaves(Node *p, int count)
{
    if(p)
    {
        if(p->left == NULL && p->right == NULL)
            count++;
        else
        {
            count = countLeaves(p->left,count)+countLeaves(p->right,count);
        }
        
    }
    else count = 0;
    return count;
}

int Tree::countNonLeaves(Node *p,int count)
{
    if(p)
    {
        if(p->left == NULL && p->right == NULL)
            count = 0;
        else
            count = countNonLeaves(p->left, count)+countNonLeaves(p->right,count)+1;
    }
    else count = 0;
    return count;
}

bool Tree::Level(Node *ptr, int level)
{
    if(ptr == 0) return false;
    if(level ==1) {
        cout << ptr->data << " "; return true;
    }
    else {
        bool left = Level(ptr->left,level-1);
        bool right = Level(ptr->right, level-1);
        return(left || right);
    }
        
}

int Tree::isEmpty()
{
    if(root ==NULL)
        return 1;
    else 
        return 0;
}
int main()
{
    Tree tree;
    while(1)
    {
        cout << "1.insert  2.delete  3.LevelOrder  4.search  5.Draw  6.NumofNodes  7.quit => " ;
        int a;
        cin >> a;
        switch (a)
        {
        case 1:
            int key;
            cout << "Enter a number to insert => " ;
            cin >> key;
            tree.insertTree(key);
            break;
        case 2:
            if(tree.isEmpty())
                cout << "Tree is Empty!!"<<endl;
            else
            {
                cout << "Enter a number to delete => " ;
                int dkey;
                cin >> dkey;
                tree.deleteTree(dkey);
            }
            break;
        
        case 3:
            if(tree.isEmpty())
                cout << "Tree is Empty!!";
            tree.LevelOrder();
            cout << endl;
            break;

        case 4:
            cout << "Enter a number to search => ";
            int skey;
            cin >> skey;
            tree.searchTree(skey);
            break;
        
        case 5:
            tree.traverseTree();
            break;
            
        case 6:
            tree.NumOfNodes();
            break;
        
        case 7:
            tree.~Tree();
            exit(1);
            break;

        default:
            break;
        }
    }
}


