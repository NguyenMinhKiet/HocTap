#include <iostream>
using namespace std;

typedef struct tagNode
{
    int Data;
    tagNode *Left;
    tagNode *Right;
};

typedef tagNode *BSTree;

// Duyệt thứ tự trước:
void NLR(BSTree T)
{
    if (T)
    {

        printf("%d", T->Data);
        NLR(T->Left);
        NLR(T->Right);
    }
}
// Duyệt thứ tự sau:
void LRN(BSTree T)
{
    if (T)
    {

        LRN(T->Left);
        LRN(T->Right);
        printf("%d", T->Data);
    }
}
// Duyệt thứ tự giữa:
void LNR(BSTree T)
{
    if (T)
    {
        LNR(T->Left);
        printf("%d", T->Data);
        LNR(T->Right);
    }
}

int Count_Node_of_Tree(BSTree T)
{
    if (!T)
        return 0;
    return (1 + Count_Node_of_Tree(T->Left) + Count_Node_of_Tree(T->Right));
}

int Count_NodeLeaf_of_Tree(BSTree T)
{
    if (!T) return 0;
    if (!T->Left && !T->Right) return 1;
    return Count_NodeLeaf_of_Tree(T->Left) + Count_NodeLeaf_of_Tree(T->Right);
}

int countNodeHave2Child(BSTree T)
{
    if(!T) return 0;
	if (T->Left && T->Right)
		return ((T->Left && T->Right ? 1 : 0) + countNodeHave2Child(T->Left) + countNodeHave2Child(T->Right));
}

int sumNodeOfTree(BSTree T)
{
    if (!T)
        return 0;
    return (T->Data + sumNodeOfTree(T->Left) + sumNodeOfTree(T->Right));
}

float avg_of_tree(BSTree T)
{
    if (!T)
        return 0;
    return sumNodeOfTree(T) * 1.0 / Count_Node_of_Tree(T);
}

int closest_value(BSTree T)
{
    int p;
    float *closest;
    if (T)
    {
        int avg = avg_of_tree(T);
        if (T->Data == avg)
            return p = T->Data;
        if (!closest || abs(T->Data - avg) < *closest)
        {
            *closest = abs(T->Data - avg);
            p = T->Data;
        }
        if (T->Data > avg)
            return closest_value(T->Left);
        else
            return closest_value(T->Right);
    }
    else
        return p;
}

int height_of_Tree(BSTree T)
{
	if (!T) return 0;
    int l = height_of_Tree(T->Left);
    int r = height_of_Tree(T->Right);
    return (1 + l>r ? l : r);
}

int countNodeUnderLevelK(BSTree node, int k)
{
	if (!node || k < 0) return 0;
	return 1 + countNodeUnderLevelK(node->Left, k - 1) + countNodeUnderLevelK(node->Right, k - 1);
}

int countNodeAtLevelK(BSTree node, int k)
{
	if (!node) return 0;
	if (!k) return 1;
	return countNodeAtLevelK(node->Left, k - 1) + countNodeAtLevelK(node->Right, k - 1);
}
