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



class Node
{
public:
    Node *left;
    int data;
    Node *right;

};

class Tree
{
    Node *root;
public:

    Tree()
    {
        root = NULL;
    }
    void create()
    {
        Node *temp, *p;
        int x;
        queue<Node *> q;
        cout << "ENTER ROOT VALUE" << endl;
        cin >> x;
        temp = new Node;
        q.push(temp);
        root = temp;
        root->data = x;
        root->left = root->right = NULL;
        p = root;
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            cout << "ENTER LEFT CHILD OF " << p->data << endl;
            cin >> x;
            if (x != -1)
            {

                temp = new Node;
                temp->data = x;
                temp->left = temp->right = NULL;
                q.push(temp);
                p->left = temp;
            }
            cout << "ENTER RIGHT CHILD OF " << p->data << endl;
            cin >> x;
            if (x != -1)
            {
                temp = new Node;
                temp->data = x;
                temp->left = temp->right = NULL;
                q.push(temp);
                p->right = temp;
            }
        }
    }
    Node * getroot() {return root;}
    void rpreorder(Node *p)
    {
        if (p)
        {
            cout << p->data << " ";
            rpreorder(p->left);
            rpreorder(p->right);
        }

    }
    void rpostorder(Node *p)
    {
        if (p)
        {
            rpostorder(p->left);
            rpostorder(p->right);
            cout << p->data << " ";
        }

    }
    void rinorder(Node *p)
    {
        if (p)
        {
            rinorder(p->left);
            cout << p->data << " ";
            rinorder(p->right);
        }

    }

    void levelorder()
    {
        Node *p = root;
        queue<Node *> q;
        q.push(root);
        cout << root->data << " ";
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            if (p->left)
            {
                cout << p->left->data << " ";
                q.push(p->left);
            }
            if (p->right)
            {
                cout << p->right->data << " ";
                q.push(p->right);

            }
        }
    }

    void ipreorder()
    {
        Node *p = root;
        stack<Node *> s;
        while (p || !s.empty())
        {
            if (p)
            {
                cout << p->data << " ";
                s.push(p);
                p = p->left;

            }
            else {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
    }

    void iinorder()
    {
        Node *p = root;
        stack<Node *> s;
        while (p || !s.empty())
        {
            if (p)
            {
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top();
                s.pop();
                cout << p->data << " ";
                p = p->right;
            }
        }
    }
    int count(Node *p)
    {
        if (p)
            return count(p->left) + count(p->right) + 1;
        return 0;
    }
    int height(Node *p)
    {
        int x = 0, y = 0;
        if (p == NULL)
            return 0;
        x = height(p->left);
        y = height(p->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }


};
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);



    Tree t;
    t.create();
    t.rpreorder(t.getroot());
    cout << endl;
    t.rpostorder(t.getroot());
    cout << endl;
    t.rinorder(t.getroot());
    cout << endl;
    t.levelorder();
    cout << endl;
    t.ipreorder();
    cout << endl;
    t.iinorder();
    cout << endl;
    cout << t.count(t.getroot()) << " " << t.height(t.getroot()) << endl;

    return 0;
}
