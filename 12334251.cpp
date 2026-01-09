struct node{
    int m;
    node *next;
};

node* delNode( node *head, int n )
{
	node* p = head;
	
	for (int i = 0; i < n; i++)
	{
		node* temp = p->next;
		delete p;
		p = temp;
	}

	return p;
}

int main() {}