#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Tree.h"
#include "queue_int.h"
#include "stack.h"
void PostOrder(bnode_t* root);
void minTime(bnode_t* root, int target)
{
	queue_t q;
	queue_t temp;
	bnode_t* contain;
	InitializeQ(&temp);
	InitializeQ(&q);
	int counter = 1;
	if (root != NULL)
	{
		insert(&q, root);

	}

	while (!isEmptyQ(&q))
	{
		contain = remove(&q);
		insert(&temp, contain);



		if (contain->left != NULL)
		{
			insert(&q, contain->left);
		}

		if (contain->right != NULL)
		{
			insert(&q,contain->right);
		}
	

		if (contain->left!=NULL &&contain->left->data == target)
		{
			contain->OnFire = true;
			printf("After %d sec: %d is set on fire\n", counter, contain->data);
			counter++;
		}
		if (contain->right != NULL && contain->right->data == target)
		{
			contain->OnFire = true;
			printf("After %d sec: %d is set on fire\n", counter, contain->data);
			counter++;
		}

		if (contain->right!=NULL && contain->right->data != target && contain->OnFire)
		{
			printf("After %d sec: %d is set on fire\n", counter, contain->right->data);
			PostOrder(root);
			counter++;
		}
		if (contain->left != NULL && contain->left->data != target && contain->OnFire)
		{
			PostOrder(root);

			printf("After %d sec: %d is set on fire\n", counter, contain->left->data);
			counter++;
		}
	}
	//InorderTraversal(root, temp);
}
void PostOrder(bnode_t* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		if (root->right!=NULL && root->right->OnFire)
		{
			root->OnFire =true;
		}
		if (root->left != NULL && root->left->OnFire)
		{
			root->OnFire = true;
		}
	}

}
int main(void)
{
	bnode_t* root = getBinaryNode(1);
	root->right = getBinaryNode(3);
	root->right->right = getBinaryNode(6);
	root->right->right->right = getBinaryNode(9);
	root->right->right->right->right = getBinaryNode(10);
	root->left= getBinaryNode(2);
	root->left->left = getBinaryNode(4);
	root->left->right = getBinaryNode(5);
	root->left->right->left = getBinaryNode(7);
	root->left->right->right = getBinaryNode(8);

	int Target = 8;

	minTime(root, Target);

	//PreOrder(root);

	return 0;
}