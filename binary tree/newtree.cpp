/**
 *    Author:ANSHUL DHANKHER
 *     YMCA CE-2023
 *    KEEP HUSTLING!!!
**/

#include<bits/stdc++.h>

typedef long long int ll;
#define MOD 1000000007
#define INF INT_MAX
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node*right;

	Node(int d)
	{
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};




Node * rb_tree()
{
	int d;
	cin >> d;
	if (d == -1)
		return NULL;

	Node *root = new Node(d);
	root->left = rb_tree();
	root->right = rb_tree();

	return root;
}

void rpreorder(Node *p)
{
	if (p == NULL)
		return;
	cout << p->data << " ";
	rpreorder(p->left);
	rpreorder(p->right);
}

void rpostorder(Node *p)
{
	if (p == NULL)
		return;

	rpostorder(p->left);
	rpostorder(p->right);
	cout << p->data << " ";
}

void rinorder(Node *p)
{
	if (p == NULL)
		return;

	rinorder(p->left);
	cout << p->data << " ";
	rinorder(p->right);

}

void ipreorder(Node *p)
{
	stack<Node*> s;
	while (p || !s.empty())
	{
		if (p)
		{
			cout << p->data << " ";
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}

void iinorder(Node *p)
{
	stack<Node*> s;
	while (p || !s.empty())
	{
		if (p)
		{

			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->data << " ";
			p = p->right;
		}
	}
}

void ipostorder(Node *p)
{
	stack<Node*> s;
	vector<int> ans;
	while (p || !s.empty())
	{
		if (p)
		{
			ans.push_back(p->data);
			s.push(p);
			p = p->right;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->left;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";
}
//kre gye

void ilevelorder(Node *p)
{
	queue<Node *> q;
	q.push(p);
	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
}
// basic it is bfs on a tree


void bfs1(Node *p)//method 1
{
	queue<pair<Node *, int>> q;
	int level = 1;
	q.push({p, 1});

	while (!q.empty())
	{
		Node *temp = q.front().first;
		if (level != q.front().second)
		{
			level++;
			cout << endl;
		}
		q.pop();
		cout << temp->data << " ";

		if (temp->left)
			q.push({temp->left, level + 1});
		if (temp->right)
			q.push({temp->right, level + 1});
	}
}


void bfs2(Node *p)//method 2
{
	queue<Node *> q;
	q.push(p);
	q.push(NULL);
	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		if (temp == NULL)
		{
			cout << endl;
			if (!q.empty())
				q.push(NULL);
		}
		else
		{
			cout << temp->data << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
}

int Height(Node *p)
{
	if (p == NULL)
		return 0;

	int x = Height(p->left);
	int y = Height(p->right);

	return max(x, y) + 1;
}

void printklevel(Node *p, int k)
{
	if (!p)
		return;
	if (k == 1)
		cout << p->data << " ";
	printklevel(p->left, k - 1);
	printklevel(p->right, k - 1);


}

int countofnodes(Node *p)
{
	if (!p)
		return 0;
	return 1 + countofnodes(p->left) + countofnodes(p->right);
}

int sumofnodes(Node *p)
{
	if (!p)
		return 0;
	return p->data + sumofnodes(p->left) + sumofnodes(p->right);
}

int diameter(Node *p)
{
	if (!p)
		return 0;

	int h1 = Height(p->left);
	int h2 = Height(p->right);

	int op1 = h1 + h2;
	int op2 = diameter(p->left);
	int op3 = diameter(p->right);

	return max({op1, op2, op3});
}

pair<int, int> diameteroptimised(Node *root)
{
	pair<int, int> p;
	if (!root)
	{
		p.first = 0;
		p.second = 0;
		return p;
	}
	pair<int, int> l = diameteroptimised(root->left);
	pair<int, int> r = diameteroptimised(root->right);
	p.first = max(l.first, r.first) + 1;
	p.second = max({l.first + r.first, l.second, r.second});
	return p;

}

vector<int> leftview(Node * root)
{
	if (!root)
		return {};
	vector<int> ans;
	queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		int n = q.size();
		for (int i = 1; i <= n; i++)
		{
			Node *p = q.front();
			q.pop();
			if (i == 1)
				ans.push_back(p->data);

			if (p->left)
				q.push(p->left);

			if (p->right)
				q.push(p->right);
		}
	}
	return ans;
}



vector<int> rightview(Node * root)
{
	if (!root)
		return {};
	vector<int> ans;
	queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		int n = q.size();
		for (int i = 1; i <= n; i++)
		{
			Node *p = q.front();
			q.pop();
			if (i == n)
				ans.push_back(p->data);

			if (p->left)
				q.push(p->left);

			if (p->right)
				q.push(p->right);
		}
	}
	return ans;
}

pair<int, bool> checkbalanced(Node *root)
{
	if (!root)
		return {0, true};

	pair<int, bool> p;
	pair<int, bool> l = checkbalanced(root->left);
	pair<int, bool> r = checkbalanced(root->right);

	p.first = abs(l.first - r.first);

	if (abs(l.first - r.first) <= 1 && l.second && r.second)
		p.second = true;

	else
		p.second = false;
	return p;

}

Node* createbalancedbinarytreeusingarray(int arr[], int start, int end)
{
	if (start > end)
		return NULL;
	int mid = start + (end - start) / 2;

	Node* root = new Node(arr[mid]);
	Node* l = createbalancedbinarytreeusingarray(arr, start, mid - 1);
	Node* r = createbalancedbinarytreeusingarray(arr, mid + 1, end);

	root->left = l;
	root->right = r;

	return root;

}

Node *buildbhtreefrompre(vector<int> &pre, vector<int> &in, int start, int end)
{
	static int pos = 0;
	if (start > end)
		return NULL;
	int mid = -1;
	for (int i = start; i <= end; i++)
	{
		if (pre[pos] == in[i])
		{
			mid = i;
			break;
		}
	}
	Node *root = new Node(pre[pos]);
	pos++;

	root->left = buildbhtreefrompre(pre, in, start, mid - 1);
	root->right = buildbhtreefrompre(pre, in, mid + 1, end);

	return root;

}


Node *buildbhtreefrompost(vector<int> &post, vector<int> &in, int start, int end)
{
	static int pos = end;
	if (start > end)
		return NULL;
	int mid = -1;
	for (int i = start; i <= end; i++)
	{
		if (post[pos] == in[i])
		{
			mid = i;
			break;
		}
	}
	Node *root = new Node(post[pos--]);

	root->right = buildbhtreefrompost(post, in, mid + 1, end);
	root->left = buildbhtreefrompost(post, in, start, mid - 1);
	//in post order first tree with right subtree is build to be remebered


	return root;

}

void printklevelbelow(Node *root, int k)
{
	if (!root)
		return;

	if (k == 0)
	{
		cout << root->data << " ";
		return;
	}

	printklevelbelow(root->left, k - 1);
	printklevelbelow(root->right, k - 1);
	return;
}


int nodesatdistancek(Node *root, Node *target, int k)
{
	if (root == NULL)
		return -1;

	if (root == target)
	{
		printklevelbelow(target, k);
		return 0;
	}

	int dl = nodesatdistancek(root->left, target, k);

	if (dl != -1)
	{
		if (dl + 1 == k)
		{
			cout << root->data << " ";

		}
		else
		{
			printklevelbelow(root->right, k - 2 - dl);

		}
		return dl + 1;
	}

	int dr = nodesatdistancek(root->right, target, k);
	if (dr != -1)
	{
		if (dr + 1 == k)
		{
			cout << root->data << " ";

		}
		else
		{
			printklevelbelow(root->left, k - 2 - dr);

		}
		return dr + 1;
	}
	return -1;

}

Node* lca(Node *root, int a, int b)
{
	if (!root)
		return NULL;

	if (root->data == a || root->data == b)
		return root;

	Node *l = lca(root->left, a, b);
	Node *r = lca(root->right, a, b);

	if (l != NULL && r != NULL)
		return root;

	if (l != NULL)
		return l;

	return r;


}
bool getpath(Node *root, int ele, vector<int> &path)
{

	if (!root)
		return false;

	path.push_back(root->data);

	if (root->data == ele)
		return true;

	if (getpath(root->left, ele, path) || getpath(root->right, ele, path))
		return true;

	path.pop_back();
	return false;
}
int lcausingstoring(Node *root, int a, int b)
{
	vector<int> path1;
	int ans1 = getpath(root, a, path1);



	vector<int> path2;
	int ans2 = getpath(root, b, path2);




	int ans = -1;
	for (int i = 0; i < path1.size() && i < path2.size(); i++)
	{
		if (path1[i] == path2[i])
			ans = path1[i];
	}
	return ans;
}


int max_sum(Node *root, int &ans)
{
	if (!root)
		return 0;

	int l_sum = max_sum(root->left, ans);
	int r_sum = max_sum(root->right, ans);

	int val = root->data;
	int op1 = val;
	int op2 = val + l_sum;
	int op3 = val + r_sum;
	int op4 = val + l_sum + r_sum;

	ans = max(ans, max({op1, op2, op3, op4}));
	return max({op1, op2, op3});
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->right = new Node(5);
	*/

	Node *root = rb_tree();
	cout << "preorder" << endl;
	rpreorder(root);

	cout << endl;
	cout << "inorder" << endl;
	rinorder(root);

	cout << endl;
	cout << "postorder" << endl;
	rpostorder(root);

	cout << endl;
	cout << "ipreorder" << endl;
	ipreorder(root);


	cout << endl;
	cout << "iinorder" << endl;
	iinorder(root);

	cout << endl;
	cout << "ipostorder" << endl;
	ipostorder(root);

	cout << endl;
	cout << "ilevelorder" << endl;
	ilevelorder(root);

	cout << endl;
	cout << "height:" << Height(root);

	cout << endl;
	printklevel(root, 3);
	//to print all k level on by one make a for loops
	//bad solution o(n) make bfs or iterative level order


	cout << endl;
	bfs1(root);

	cout << endl;
	bfs2(root);


	cout << countofnodes(root) << " " << sumofnodes(root);


	cout << endl;
	cout << diameter(root);

	cout << endl;
	pair<int, int> p = diameteroptimised(root);
	cout << "height:" << p.first << " diameter:" << p.second;


	cout << endl;
	vector<int> lv = leftview(root);
	cout << "leftview" << endl;
	for (auto ele : lv)
		cout << ele << " ";


	cout << endl;
	vector<int> rv = rightview(root);
	cout << "rightview" << endl;
	for (auto ele : rv)
		cout << ele << " ";

	cout << endl;
	pair<int, bool> check = checkbalanced(root);

	if (check.second)
		cout << "isbalanced";
	else
		cout << "notbalancde";

	cout << endl;
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	Node *bt = createbalancedbinarytreeusingarray(arr, 0, 6);

	bfs1(bt);

	cout << endl;
	vector<int> pre = {8, 10 , 1 , 6 , 9, 7 , 3 , 14, 13 };
	vector<int> in = {1 , 10, 9, 6, 7, 8, 3, 13, 14 };
	Node *bt1 = buildbhtreefrompre(pre, in, 0, 8);

	cout << endl;
	nodesatdistancek(bt1, bt1->left, 2 );
	cout << endl;
	Node *A = lca(bt1, 1, 9);
	cout << A->data;


	cout << endl;
	cout << lcausingstoring(bt1, 1, 9);


	Node *msbt = new Node(-10);
	msbt->left = new Node(9);
	msbt->right = new Node(20);
	msbt->right->left = new Node(15);
	msbt->right->right = new Node(7);
	cout << endl;
	int ans = INT_MIN;
	max_sum(msbt, ans);
	cout << ans;





	return 0;

}