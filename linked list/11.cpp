Node* findIntersection(Node* head1, Node* head2)
{
    Node *start = NULL, *end = NULL;
    unordered_map<int, int> mp;
    Node *p = head1;
    while (p)
    {
        mp[p->data] = 1;
        p = p->next;
    }
    p = head2;
    while (p)
    {
        if (mp[p->data])
        {
            if (start == NULL)
            {
                Node *temp = new Node(p->data);
                start = temp;
                end = temp;
            }
            else
            {
                Node *temp = new Node(p->data);
                end->next = temp;
                end = temp;
            }
            mp[p->data] = 0;
        }
        p = p->next;
    }
    return start;
}