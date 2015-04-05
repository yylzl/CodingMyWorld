#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>

typedef enum color_e
{
    BLACK = 0,
    RED
}color_t;

typedef struct rbtree_node_s rbtree_node_t;
typedef struct rbtree_s rbtree_t;

typedef void (*rbtree_insert_pt) (rbtree_t *tree, rbtree_node_t *node);
typedef void (*rbtree_delete_pt) (rbtree_t *tree, rbtree_node_t *node);
typedef rbtree_node_t * (*rbtree_search_pt) (rbtree_t *tree, uintptr_t key);

struct rbtree_node_s
{
    rbtree_node_t *parent;
    rbtree_node_t *left;
    rbtree_node_t *right;
    uintptr_t key;
    color_t color;
};

struct rbtree_s
{
    rbtree_node_t *root;
    rbtree_node_t *nil;
    rbtree_insert_pt insert;
    rbtree_insert_pt delete;
    rbtree_search_pt search;
};

#define rbtree_node_red(node) ((node)->color=RED)
#define rbtree_node_black(node) ((node)->color=BLACK)
#define rbtree_node_is_red(node) ((node)->color==RED)
#define rbtree_node_is_black(node) ((node)->color==BLACK)
#define rbtree_node_copy_color(node1,node2) ((node1)->color=(node2)->color)

#define rbtree_node_is_left_child(node)  ((node)==(node)->parent->left)
#define rbtree_node_is_right_child(node)  ((node)==(node)->parent->right)
#define rbtree_node_get_uncle_right(node)  ((node)->parent->parent->right)
#define rbtree_node_get_uncle_left(node)  ((node)->parent->parent->left)

rbtree_node_t * rbtree_sentinel_init(void)
{
    rbtree_node_t *nil = malloc(sizeof(rbtree_node_t));
    rbtree_node_black(nil);
    return nil;
}

rbtree_node_t * rbtree_node_new(rbtree_t *tree, uintptr_t key, color_t color)
{
    rbtree_node_t *ret = malloc(sizeof(rbtree_node_t));
    if(ret==NULL)
    {
        return NULL;
    }
    ret->parent = tree->nil;
    ret->left = tree->nil;
    ret->right = tree->nil;
    ret->key = key;
    ret->color = color;
    return ret;
}

void rbtree_left_rotate(rbtree_t *tree, rbtree_node_t *node)
{
    rbtree_node_t *right = node->right;
    node->right = right->left;
    if(right->left!=tree->nil)
    {
        right->left->parent = node;
    }

    right->parent = node->parent;

    if(node->parent==tree->nil)
    {
        tree->root = right;
    }
    else if(rbtree_node_is_left_child(node))
    {
        node->parent->left = right;
    }
    else
    {
        node->parent->right = right;
    }

    node->parent = right;
    right->left = node;
}

void rbtree_right_rotate(rbtree_t *tree, rbtree_node_t *node)
{
    rbtree_node_t *left = node->left;
    node->left = left->right;
    if(left->right!=tree->nil)
    {
        left->right->parent = node;
    }

    left->parent = node->parent;

    if(node->parent==tree->nil)
    {
        tree->root = left;
    }
    else if(rbtree_node_is_left_child(node))
    {
        node->parent->left = left;
    }
    else
    {
        node->parent->right = left;
    }

    node->parent = left;
    left->right = node;
}

void rbtree_insert(rbtree_t *tree, rbtree_node_t *node)
{
    if((node==NULL) || (tree==NULL))
    {   
        return;
    }   
    if(tree->root==NULL)
    {
        tree->root = node;
        //return;
    }
    else
    {
        rbtree_node_t *child = tree->root;
        rbtree_node_t *parent = NULL;
        while(child!=tree->nil)
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

    //rbtree insert fixup
    while(rbtree_node_is_red(node->parent) && (node!=tree->root))
    {
        if(rbtree_node_is_left_child(node->parent))
        {
            rbtree_node_t *uncle_right = rbtree_node_get_uncle_right(node);
            if(rbtree_node_is_red(uncle_right))
            {
                rbtree_node_black(node->parent);
                rbtree_node_black(uncle_right);
                rbtree_node_red(node->parent->parent);
                node = node->parent->parent;
            }
            else
            {
                if(rbtree_node_is_right_child(node))
                {
                    node = node->parent;
                    rbtree_left_rotate(tree, node);
                }
                rbtree_node_black(node->parent);
                rbtree_node_red(node->parent->parent);
                rbtree_right_rotate(tree, node->parent->parent);
            }
        }
        else
        {
            rbtree_node_t *uncle_left = rbtree_node_get_uncle_left(node);
            if(rbtree_node_is_red(uncle_left))
            {
                rbtree_node_black(node->parent);
                rbtree_node_black(uncle_left);
                rbtree_node_red(node->parent->parent);
                node = node->parent->parent;
            }
            else
            {
                if(rbtree_node_is_left_child(node))
                {
                    node = node->parent;
                    rbtree_right_rotate(tree, node);
                }
                rbtree_node_black(node->parent);
                rbtree_node_red(node->parent->parent);
                rbtree_left_rotate(tree, node->parent->parent);
            }
        }
    }

    rbtree_node_black(tree->root);
}

rbtree_node_t * rbtree_search(rbtree_t *tree, uintptr_t key)
{
    if((tree==NULL) || (tree->root==NULL))
    {
        return NULL;
    }

    rbtree_node_t *it = tree->root;
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

void rbtree_inorder_output_node(rbtree_t *tree, rbtree_node_t *node)
{
#if 1
    if(node!=tree->nil)
    {
        rbtree_inorder_output_node(tree, node->left);
        printf("%lu\n", node->key);
        if(rbtree_node_is_red(node))
        {
            printf("color:red\n");
        }
        else
        {
            printf("color:black\n");
        }
        if(node->parent!=tree->nil)
        {
            printf("parent=%lu\n",node->parent->key);
        }
        else
        {
            printf("root node\n");
        }
        if(node->left!=tree->nil)
        {
            printf("left=%lu\n",node->left->key);
        }
        else
        {
            printf("left nil\n");
        }
        if(node->right!=tree->nil)
        {
            printf("right=%lu\n",node->right->key);
        }
        else
        {
            printf("right nil\n");
        }
        rbtree_inorder_output_node(tree, node->right);
    }
#else
    //非递归用栈实现，用c++比较方便
#endif
}

void rbtree_inorder_output(rbtree_t *tree)
{
    if((tree==NULL) || (tree->root==NULL))
    {
        return;
    }

    rbtree_inorder_output_node(tree, tree->root);
}


uintptr_t get_max_key(rbtree_node_t *nil, rbtree_node_t *root)
{
    if((root==NULL) || (root==nil))
    {
        return 0xdeadbeef;
    }
    rbtree_node_t *it = root;
    while(it->right!=nil)
    {
        it=it->right;
    }

    return it->key;
}

rbtree_node_t * get_max_key_node(rbtree_node_t *nil, rbtree_node_t *root)
{
    if((root==NULL) || (root==nil))
    {
        return nil;
    }
    rbtree_node_t *it = root;
    while(it->right!=nil)
    {
        it=it->right;
    }

    return it;
}

uintptr_t get_min_key(rbtree_node_t *nil, rbtree_node_t *root)
{
    if((root==NULL) || (root==nil))
    {
        return 0xdeadbeef;
    }
    rbtree_node_t *it = root;
    while(it->left!=nil)
    {
        it=it->left;
    }

    return it->key;
}

rbtree_node_t * get_min_key_node(rbtree_node_t *nil, rbtree_node_t *root)
{
    if((root==NULL) || (root==nil))
    {
        return nil;
    }
    rbtree_node_t *it = root;
    while(it->left!=nil)
    {
        it=it->left;
    }

    return it;
}

uintptr_t get_successor(rbtree_t *tree, rbtree_node_t *node)
{
    if((node==NULL) || (node==tree->nil))
    {
        return 0xdeadbeef;
    }

    if(node->right!=tree->nil)
    {
        return get_min_key(tree->nil, node->right);
    }
    rbtree_node_t * parent = node->parent;
    while((parent!=tree->nil) && (node==parent->right))
    {
        node = parent;
        parent = node->parent;
    }

    if(parent == tree->nil)
    {
        return 0xdeadbeef;
    }

    return parent->key;
}

uintptr_t get_predecessor(rbtree_t *tree, rbtree_node_t *node)
{
    if((node==NULL) || (node==tree->nil))
    {
        return 0xdeadbeef;
    }

    if(node->left!=tree->nil)
    {
        return get_max_key(tree->nil, node->left);
    }
    rbtree_node_t * parent = node->parent;
    while((parent!=tree->nil) && (node==parent->left))
    {
        node = parent;
        parent = node->parent;
    }

    if(parent == tree->nil)
    {
        return 0xdeadbeef;
    }

    return parent->key;
}

void transplant(rbtree_t *tree, rbtree_node_t *x, rbtree_node_t *y)
{
    if(x->parent==tree->nil)
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
    //if(y!=NULL)
    //{
    y->parent = x->parent;
    //}
}

void rbtree_delete(rbtree_t *tree, rbtree_node_t *node)
{
    if((node==NULL)||(tree==NULL))
    {
        return;
    }
    
    rbtree_node_t *x, *y, *w;
    color_t color;

    y = node;
    color = y->color;

    if(node->right==tree->nil)
    {
        x = node->left;
        transplant(tree, node, node->left);
    }
    else if(node->left==tree->nil)
    {
        x = node->right;
        transplant(tree, node ,node->right);
    }
    else
    {
        rbtree_node_t *successor = get_min_key_node(tree->nil, node->right);
        y = successor;
        color = y->color;
        x = successor->right;
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
        if(successor!=node->right)
        {
            transplant(tree, successor, successor->right);
            successor->right = node->right;
            successor->right->parent = successor;
        }
        transplant(tree, node, successor);
        successor->left = node->left;
        successor->left->parent = successor;
        rbtree_node_copy_color(successor, node);
#endif
    }

    //rbtree delete fixup
    if(color==BLACK)
    {
        while((x!=tree->root)&&rbtree_node_is_black(x))
        {
            if(rbtree_node_is_left_child(x))
            {
                w = x->parent->right;
                if(rbtree_node_is_red(w))
                {
                    rbtree_node_black(w);
                    rbtree_node_red(x->parent);
                    rbtree_left_rotate(tree, x->parent);
                    w = x->parent->right;
                }

                if(rbtree_node_is_black(w->right) && rbtree_node_is_black(w->left))
                {
                    rbtree_node_red(w);
                    x = x->parent;
                }
                else
                {
                    if(rbtree_node_is_black(w->right))
                    {
                        rbtree_node_black(w->left);
                        rbtree_node_red(w);
                        rbtree_right_rotate(tree, w);
                        w = x->parent->right;
                    }
                    rbtree_node_copy_color(w, x->parent);
                    rbtree_node_black(x->parent);
                    rbtree_node_black(w->right);
                    rbtree_left_rotate(tree, x->parent);
                    x = tree->root;
                }
            }
            else
            {
                w = x->parent->left;
                if(rbtree_node_is_red(w))
                {
                    rbtree_node_black(w);
                    rbtree_node_red(x->parent);
                    rbtree_right_rotate(tree, x->parent);
                    w = x->parent->left;
                }

                if(rbtree_node_is_black(w->right) && rbtree_node_is_black(w->left))
                {
                    rbtree_node_red(w);
                    x = x->parent;
                }
                else
                {
                    if(rbtree_node_is_black(w->left))
                    {
                        rbtree_node_black(w->right);
                        rbtree_node_red(w);
                        rbtree_left_rotate(tree, w);
                        w = x->parent->left;
                    }
                    rbtree_node_copy_color(w, x->parent);
                    rbtree_node_black(x->parent);
                    rbtree_node_black(w->right);
                    rbtree_right_rotate(tree, x->parent);
                    x = tree->root;
                }
            }
        }
    }

    rbtree_node_black(x);
}

int main(int argc, char *argv[])
{
    rbtree_t tree;
    rbtree_node_t *nil = rbtree_sentinel_init();
    tree.root = NULL;
    tree.nil = nil;
    tree.insert = rbtree_insert;
    tree.delete = rbtree_delete;
    tree.search = rbtree_search;

    rbtree_node_t *node = nil;
    uintptr_t i = 0;
    for(i=0;i<100;++i)
    {
        node = rbtree_node_new(&tree, i, RED);
        tree.insert(&tree, node);
    }

    rbtree_inorder_output(&tree);
#if 1

    rbtree_node_t *t = tree.search(&tree, 8);
    if(t)
    {
        printf("find %lu\n", t->key);
        if(t->parent!=tree.nil)
        {
            printf("parent=%lu\n", t->parent->key);
        }
        else
        {
            printf("parent=nil\n");
        }
        if(t->left!=tree.nil)
        {
            printf("left=%lu\n", t->left->key);
        }
        else
        {
            printf("left=nil\n");
        }
        if(t->right!=tree.nil)
        {
            printf("right=%lu\n", t->right->key);
        }
        else
        {
            printf("right=nil\n");
        }
        printf("%lu successor=%lu\n", t->key, get_successor(&tree, t));
        printf("%lu predecessor=%lu\n", t->key, get_predecessor(&tree, t));
    }

    printf("tree max=%lu\n", get_max_key(tree.nil, tree.root));
    printf("tree min=%lu\n", get_min_key(tree.nil, tree.root));

    tree.delete(&tree, t);

    rbtree_inorder_output(&tree);

    tree.delete(&tree, tree.root);
    rbtree_inorder_output(&tree);
#endif
    return 0;
}

