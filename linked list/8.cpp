void ltp(Node *head)
{	Node *p = head, *prev = NULL;
	while (p->next)
	{	prev = p;
		p = p->next;
	}


	prev->next = NULL;

	p->next = head;
	head = p;
}