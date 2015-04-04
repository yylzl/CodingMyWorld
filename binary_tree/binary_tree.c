#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct binary_tree_node_s binary_tree_node_t;
typedef struct binary_tree_s binary_tree_t;

typedef void (*binary_tree_insert_pt) (binary_tree_t *tree, binary_tree_node_t *node);
typedef void (*binary_tree_delete_pt) (binary_tree_t *tree, binary_tree_node_t *node);
typedef binary_tree_node_t * (*binary_tree_search_pt) (binary_tree_t *tree, uintptr_t key);

struct binary_tree_node_s
{
    binary_tree_node_t *parent;
    binary_tree_node_t *left;
    binary_tree_node_t *right;
    uintptr_t key;
};

struct binary_tree_s
{
    binary_tree_node_t *root;
    binary_tree_insert_pt insert;
    binary_tree_insert_pt delete;
    binary_tree_search_pt search;
};

binary_tree_node_t * binary_tree_node_new(uintptr_t key)
{
    binary_tree_node_t *ret = malloc(sizeof(binary_tree_node_t));
    if(ret==NULL)
    {
        return NULL;
    }
    ret->parent = NULL;
    ret->left = NULL;
    ret->right = NULL;
    ret->key = key;
    return ret;
}

void binary_tree_insert(binary_tree_t *tree, binary_tree_node_t *node)
{
    if(node==NULL)
    {   
        return;
    }   
    if(tree->root==NULL)
    {
        tree->root = node;
        return;
    }

    binary_tree_node_t *child = tree->root;
    binary_tree_node_t *parent = NULL;
    while(child)
    {
        parent = child;
        if(node->key > child->key)
        {
            child = child->right;
        }
        else
        {
            child = child->left;
        }
    }

    node->parent = parent;
    if(node->key > parent->key)
    {
        parent->right = node;
    }
    else
    {
        parent->left = node;
    }
}

binary_tree_node_t * binary_tree_search(binary_tree_t *tree, uintptr_t key)
{
    if((tree==NULL) || (tree->root==NULL))
    {
        return NULL;
    }

    binary_tree_node_t *it = tree->root;
    while(it)
    {
        if(it->key==key)
        {
            return it;
        }
        else if(it->key > key)
        {
            it = it->left;
        }
        else
        {
            it = it->right;
        }
    }

    return NULL;
}

void binary_tree_inorder_output_node(binary_tree_node_t *node)
{
#if 1
    if(node!=NULL)
    {
        binary_tree_inorder_output_node(node->left);
        printf("%lu\n", node->key);
        binary_tree_inorder_output_node(node->right);
    }
#else
    //非递归用栈实现，用c++比较方便
#endif
}

void binary_tree_inorder_output(binary_tree_t *tree)
{
    if((tree==NULL) || (tree->root==NULL))
    {
        return;
    }

    binary_tree_inorder_output_node(tree->root);
}


uintptr_t get_max_key(binary_tree_node_t *root)
{
    if(root==NULL)
    {
        return 0xdeadbeef;
    }
    binary_tree_node_t *it = root;
    while(it->right)
    {
        it=it->right;
    }

    return it->key;
}

binary_tree_node_t * get_max_key_node(binary_tree_node_t *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    binary_tree_node_t *it = root;
    while(it->right)
    {
        it=it->right;
    }

    return it;
}

uintptr_t get_min_key(binary_tree_node_t *root)
{
    if(root==NULL)
    {
        return 0xdeadbeef;
    }
    binary_tree_node_t *it = root;
    while(it->left)
    {
        it=it->left;
    }

    return it->key;
}

uintptr_t get_successor(binary_tree_node_t *node)
{
    if(node==NULL)
    {
        return 0xdeadbeef;
    }

    if(node->right)
    {
        return get_min_key(node->right);
    }
    binary_tree_node_t * parent = node->parent;
    while(parent && (node==parent->right))
    {
        node = parent;
        parent = node->parent;
    }

    if(parent == NULL)
    {
        return 0xdeadbeef;
    }

    return parent->key;
}

uintptr_t get_predecessor(binary_tree_node_t *node)
{
    if(node==NULL)
    {
        return 0xdeadbeef;
    }

    if(node->left)
    {
        return get_max_key(node->left);
    }
    binary_tree_node_t * parent = node->parent;
    while(parent && (node==parent->left))
    {
        node = parent;
        parent = node->parent;
    }

    if(parent == NULL)
    {
        return 0xdeadbeef;
    }

    return parent->key;
}

void transplant(binary_tree_t *tree, binary_tree_node_t *x, binary_tree_node_t *y)
{
    if(x->parent==NULL)
    {
        tree->root = y;
    }
    if(x==x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    if(y!=NULL)
    {
        y->parent = x->parent;
    }
}

void binary_tree_delete(binary_tree_t *tree, binary_tree_node_t *node)
{
    if((node==NULL)||(tree==NULL))
    {
        return;
    }
    if(node->right==NULL)
    {
        transplant(tree, node, node->left);
    }
    else if(node->left==NULL)
    {
        transplant(tree, node ,node->right);
    }
    else
    {
        binary_tree_node_t *predecessor = get_max_key_node(node->left);
#if 0
        if(predecessor == node->left)
        {
            transplant(tree, node predecessor);
            predecessor->right = node->right;
            predecessor->right->parent = predecessor;
        }
        else
        {
            transplant(tree, predecessor, predecessor->left);
            transplant(tree, node, predecessor);
            predecessor->right = node->right;
            predecessor->left = node->left;
            predecessor->right->parent = predecessor;
            predecessor->left->parent = predecessor;

        }
#else
        if(predecessor!=node->left)
        {
            transplant(tree, predecessor, predecessor->left);
            predecessor->left = node->left;
            predecessor->left->parent = predecessor;
        }
        transplant(tree, node, predecessor);
        predecessor->right = node->right;
        predecessor->right->parent = predecessor;
#endif
    }
}

int main(int argc, char *argv[])
{
    binary_tree_t tree;
    tree.root = NULL;
    tree.insert = binary_tree_insert;
    tree.delete = binary_tree_delete;
    tree.search = binary_tree_search;

    binary_tree_node_t *node = NULL;
    uintptr_t i = 0;
    for(i=0;i<100;++i)
    {
        node = binary_tree_node_new(i);
        tree.insert(&tree, node);
    }

    binary_tree_inorder_output(&tree);

    binary_tree_node_t *t = tree.search(&tree, 88);
    if(t)
    {
        printf("find %lu\n", t->key);
        if(t->parent)
        {
            printf("parent=%lu\n", t->parent->key);
        }
        if(t->left)
        {
            printf("left=%lu\n", t->left->key);
        }
        if(t->right)
        {
            printf("right=%lu\n", t->right->key);
        }
        printf("t successor=%lu\n", get_successor(t));
        printf("t predecessor=%lu\n", get_predecessor(t));
    }

    printf("tree max=%lu\n", get_max_key(tree.root));
    printf("tree min=%lu\n", get_min_key(tree.root));

    tree.delete(&tree, t);

    binary_tree_inorder_output(&tree);

    return 0;
}

