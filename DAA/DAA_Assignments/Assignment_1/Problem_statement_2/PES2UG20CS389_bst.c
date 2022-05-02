// Name: Vishwa Mehul Mehta
// SRN: PES2UG20CS389
#include "bst.h"
#include <stdlib.h>
/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Static functions used are insert_node(), del_node(), minValueNode(), search_node(), max_node(), rec_free(), rec_clear()

// insert_node() is a recursive function used to insert a node in the BST
static node_t *insert_node(node_t *root, int key, int *count_ptr) {
	if (root == NULL) {
		(*count_ptr)++;
		node_t *temp = (node_t*)malloc(sizeof(node_t));
		temp -> key = key;
		temp -> left = NULL;
		temp -> right = NULL;
		return temp;
	}
	else {
	    if (++*count_ptr && key > root -> key)
			root -> right = insert_node(root -> right, key, count_ptr);
	    else {
			(*count_ptr)++;
			root -> left = insert_node(root -> left, key, count_ptr);
		}
	}
	return root;
}
// used in del_node()
static node_t* minValueNode(node_t* node) {
    node_t* curr = node;
    while (curr && curr -> left != NULL)
        curr = curr -> left;
    return curr;
}

static node_t *del_node(node_t *root, int key, int *count_ptr) {
	if (root == NULL)
		return root;
	if (++*count_ptr && key < root -> key)
		root -> left = del_node(root -> left, key, count_ptr);
	else if (++*count_ptr && key > root -> key)
		root -> right = del_node(root -> right, key,count_ptr);
	else {
		++*count_ptr;
		if (root -> left == NULL && root -> right == NULL) {
			free(root);
	        return NULL;
	    }
		else if (root -> left == NULL || root -> right == NULL) {
	        node_t *temp;
	        if(root -> left == NULL)
				temp = root -> right;
	        else
	            temp = root -> left;
	        free(root);
	        return temp;
	    }
		else {
			++*count_ptr;
			node_t* temp = minValueNode(root -> right);
			root -> key = temp -> key;
		    root -> right = del_node(root -> right, temp -> key,count_ptr);
		}
	}
	return root;
}

// search_node() is a recursive function to search for a node in the BST
static int search_node(node_t *root, int key, int *count_ptr) {
	if (++*count_ptr && root == NULL)
		return -1;
	else if(++*count_ptr && root -> key == key)
		return root -> key;
	else if(++*count_ptr && root -> key < key)
		return search_node(root -> right, key, count_ptr);
	else {
		++*count_ptr;
		return search_node(root -> left, key, count_ptr);
	}
}

// max_node() is a recursive function to search for the max element in the BST
static node_t *max_node(node_t *root, int *count_ptr) {
	if (++*count_ptr && root -> right != NULL) {
		return max_node(root -> right, count_ptr);
	}
	else {
		++*count_ptr;
		return root;
	}
}

// rec_free() is used to free the BST
static void rec_free(node_t *root) {
	if (root == NULL)
		return;
	rec_free(root -> left);
	rec_free(root -> right);
	free(root);
}

// rec_clear() is used to clear the BST
static void rec_clear(node_t *root) {
	if(root == NULL) {
		return;
	}
	if (root -> left == NULL && root -> right == NULL) {
		free(root);
    return;
	}
	rec_clear(root->left);
	rec_clear(root->right);
}

// Initializes the root of the bst
void init_bst(bst_t *bst) {
	bst -> root = NULL;
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
void insert(bst_t *tree, int key, int *count_ptr) {
	tree -> root = insert_node(tree -> root, key, count_ptr);
}

// Delete key from the BST
// Replaces node with in-order successor
void delete_element(bst_t *tree, int key, int *count_ptr) {
	tree -> root = del_node(tree -> root, key, count_ptr);
}

// Searches for the element key in the bst
// Returns the element if found, else -1
int search(const bst_t *tree, int key, int *count_ptr) {
	return search_node(tree -> root, key, count_ptr);
}

// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr) {
	if(tree -> root == NULL) {
		return -1;
	}
	node_t *temp = (node_t*)malloc(sizeof(node_t));
	temp = max_node(tree -> root, count_ptr);
	return temp -> key;
}

// Deletes all the elements of the bst
void free_bst(bst_t *bst) {
  rec_free(bst -> root);
  free(bst);
}

// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst) {
	rec_clear(bst -> root);
	bst -> root = NULL;
}
