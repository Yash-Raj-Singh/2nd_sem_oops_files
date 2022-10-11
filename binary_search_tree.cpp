#include <bits/stdc++.h>

#define SPACE 10

using namespace std;

class Treenode
{
public:
	int value;
	Treenode *left;
	Treenode *right;

	Treenode()
	{
		value = 0;

		left = NULL;
		right = NULL;
	}

	Treenode(int v)
	{
		value = v;

		left = NULL;
		right = NULL;
	}

};

class BST
{
public:
	Treenode *root;

	BST()
	{
		root =NULL;
	}

	bool isTreeEmpty()
	{
		if(root == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void insertNode(Treenode * new_node) {
    if (root == NULL) {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    } else {
      Treenode * temp = root;
      while (temp != NULL) {
        if (new_node -> value == temp -> value) {
          cout << "Value Already exist," <<
            "Insert another value!" << endl;
          return;
        } else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) {
          temp -> left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        } else if (new_node -> value < temp -> value) {
          temp = temp -> left;
        } else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) {
          temp -> right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        } else {
          temp = temp -> right;
        }
      }
    }
  }

	void print2D(Treenode *r, int space)
	{
		if(r == NULL)
		{
			return;
		}
		space += SPACE;
		print2D(r->right, space);
		cout<<endl;

		for(int i = SPACE; i < space; i++)
		{
			cout<<" ";
		}
		cout<<r->value<<"\n";
		print2D(r->left, space);
	}

	void printPreorder(Treenode *r)
	{
		if( r == NULL)
		{
			return;
		}
		cout<<r->value<<" ";

		printPreorder(r->left);

		printPreorder(r->right);
	}

	void printInorder(Treenode *r)
	{
		if( r == NULL)
		{
			return;
		}
		
		printInorder(r->left);

		cout<<r->value<<" ";

		printInorder(r->right);
	}

	void printPostorder(Treenode *r)
	{
		if( r == NULL)
		{
			return;
		}
		
		printPostorder(r->left);

		printPostorder(r->right);

		cout<<r->value<<" ";
	}

	Treenode *iterativeSearch(int val)
	{
		if( root == NULL)
		{
			return root;
		}
		else
		{
			Treenode *temp = root;

			while(temp != NULL)
			{
				if( val == temp->value)
				{
					return temp;
				}
				else if(val < temp->value)
				{
					temp = temp->left;
				}
				else
				{
					temp = temp->right;
				}
			}

			return NULL;
		}
	}

	int height(Treenode *r)
	{
		if( r==NULL )
		{
			return -1;
		}
		else
		{
			int lheight = height(r->left);
			int rheight = height(r->right);

			if(lheight>rheight)
			{
				return (lheight+1);
			}
			else
			{
				return (rheight+1);
			}
			
		}
	}

	void printGivenLevel(Treenode *r, int level)
	{
		if(r==NULL)
		{
			return;
		}
		else if(level == 0)
		{
			cout<<r->value<<" "; 
		}
		else
		{
			printGivenLevel(r->left , level-1);
			printGivenLevel(r->right , level-1);
		}
	}

	void printLevelOrderBFS(Treenode *r)
	{
		int h = height(r);
		
		for(int i = 0; i <= h; i++)
		{
			printGivenLevel(r, i);
		}
	}

	Treenode *minValueNode(Treenode* node)
	{
		Treenode *current = node;
		while(current != NULL)
		{
			current = current->left;
		}

		return current;
	}

	Treenode *deletenode(Treenode *r, int v)
	{
		if(r == NULL)
		{
			return NULL;
		}
		else if(v > r->value)
		{
			r->right = deletenode(r->right, v);
		}
		else if(v < r->value)
		{
			r->left = deletenode(r->left, v);
		}
		else
		{
			if (r -> left == NULL) 
			{
        		Treenode * temp = r -> right;
        		delete r;
        		return temp;
      		} 
	  		else if (r -> right == NULL) 
			{
        		Treenode * temp = r -> left;
        		delete r;
       			return temp;
      		} 
	 	 	else 
	  		{ 
        		Treenode * temp = minValueNode(r -> right);
        
        		r -> value = temp -> value;
         
        		r -> right = deletenode(r -> right, temp -> value);
         
      		}
		}

		return r; 
	}

};

int main()
{
	int option, val;

	BST obj;

	do
	{
		cout<<"What operation do you like to perform ?";
		cout<<"\nSelect 0 to exit.....\n";

		cout<<"1. Insert Node "<<endl;
		cout<<"2. Search Node"<<endl;
		cout<<"3. Delete Node"<<endl;
		cout<<"4. Print BST Values"<<endl;
		cout<<"5. Clear Screen"<<endl;
		cout<<"6. Height Of The Tree"<<endl;
		cout<<"0. Exit From Here"<<endl;

		cout<<endl<<"Enter here : ";
		cin>>option;
		cout<<endl;

		Treenode *new_node = new Treenode();

		switch(option)
		{
			case 0:
				break;

			case 1:
				cout<<"Enter VALUE of TREE NODE to INSERT in BST : ";
				cin>>val;
				new_node->value = val;
				obj.insertNode(new_node);				
				cout<<endl;
				break;

			case 2:
				cout<<"Search"<<endl;
				cout<<"Enter value to search in BST : ";
				cin>>val;
				new_node = obj.iterativeSearch(val);
				if(new_node != NULL)
				{
					cout<<"Value Found !\n";
				}
				else
				{
					cout<<"Nothing Found !\n";
				}
				break;

			case 3:
				cout << "DELETE" << endl;
      			cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      			cin >> val;
      			new_node = obj.iterativeSearch(val);
      			if (new_node != NULL) {
        		obj.deletenode(obj.root, val);
        		cout << "Value Deleted" << endl;
      			} else {
        		cout << "Value NOT found" << endl;
      			}
      			break;

			case 4:
				cout<<"Print and Traverse"<<endl;
				obj.print2D(obj.root, 5);
				cout<<endl<<endl<<"Preorder DFS : ";
				obj.printPreorder(obj.root);
				cout<<endl<<"Inorder DFS : ";
				obj.printInorder(obj.root);
				cout<<endl<<"Postorder DFS : ";
				obj.printPostorder(obj.root);
				cout<<endl;
				cout<<endl<<"Level Order / BFS : ";
				obj.printLevelOrderBFS(obj.root);
				cout<<endl<<endl;
				break;

			case 5:
				cout<<"Clear Screen"<<endl;
				system("cls");
				break;

			case 6:
				cout<<"Tree's Height : "<<obj.height(obj.root);
				cout<<endl;
				break;

			default:
			cout<<"Enter Proper Number "<<endl;
		}
	}
	while(option != 0);

	return 0;
}