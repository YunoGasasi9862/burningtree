#pragma once
typedef int BType;

typedef struct bnode_t
{
	BType data;
	bnode_t* right;
	bnode_t* left;
	bool OnFire;

}bnode_t;

bnode_t* getBinaryNode(BType data)
{
	bnode_t* root;
	root = (bnode_t*)malloc(sizeof(bnode_t));

	if (root) //extra checking :)
	{
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		root->OnFire = false;
	}
	return root;
}

void PreOrder(bnode_t* root)
{

	if (root != NULL)
	{
		printf("%d -> ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}