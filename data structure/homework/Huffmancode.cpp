#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>
#define HEAPCAPACITY 64
#define MINWEIGHT 0
using namespace std;
typedef struct TreeNode *HuffmanTree;
typedef struct Heap *MinHeap;
struct TreeNode
{
    int weight;
    HuffmanTree left;
    HuffmanTree right;
};
struct Heap
{
    HuffmanTree *data;
    int size;
};
MinHeap createHeap();
HuffmanTree createWeightTree();
void sortHeap(MinHeap H, int i);
void adjust(MinHeap H);
MinHeap initHeap(int n);
HuffmanTree Delete(MinHeap H);
void insert(MinHeap H, HuffmanTree Huff);
HuffmanTree createHuffman(MinHeap H);
int roadLength(HuffmanTree Huff);
int main()
{
    MinHeap H;
    HuffmanTree Huff;
    int n, length;
    cin >> n;
    H = initHeap(n);
    Huff = createHuffman(H);
    length = roadLength(Huff);
    cout << length << endl;
    return 0;
}
MinHeap createHeap()
{
    MinHeap H;
    H = (MinHeap)malloc(sizeof(struct Heap));
    H->data = (HuffmanTree *)malloc(sizeof(struct TreeNode) * HEAPCAPACITY);
    H->size = 0;
    HuffmanTree Huff = createWeightTree();
    H->data[0] = Huff;
    return H;
}
HuffmanTree createWeightTree()
{
    HuffmanTree Huff;
    Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
    Huff->weight = MINWEIGHT;
    Huff->left = NULL;
    Huff->right = NULL;
    return Huff;
}
void sortHeap(MinHeap H, int i)
{
    int parent, child;
    HuffmanTree Huff = H->data[i];
    for (parent = i; parent * 2 <= H->size; parent = child)
    {
        child = parent * 2;

        if (child != H->size && H->data[child + 1]->weight < H->data[child]->weight)
            child++;

        if (Huff->weight <= H->data[child]->weight)
            break;

        H->data[parent] = H->data[child];
    }

    H->data[parent] = Huff;
}
void adjust(MinHeap H)
{
    for (int i = H->size / 2; i > 0; i--)
    {
        sortHeap(H, i);
    }
}
MinHeap initHeap(int n)
{
    MinHeap H = createHeap();
    HuffmanTree Huff;
    int weight;
    for (int i = 0; i < n; i++)
    {
        cin >> weight;
        Huff = createWeightTree();
        Huff->weight = weight;
        H->size++;
        H->data[H->size] = Huff;
    }
    adjust(H);
    return H;
}
HuffmanTree Delete(MinHeap H)
{
    HuffmanTree T = H->data[1];
    HuffmanTree Huff = H->data[H->size--];
    int parent, child;
    for (parent = 1; parent * 2 <= H->size; parent = child)
    {
        child = parent * 2;
        if (child != H->size && H->data[child + 1]->weight < H->data[child]->weight)
            child++;
        if (Huff->weight <= H->data[child]->weight)
            break;
        H->data[parent] = H->data[child];
    }
    H->data[parent] = Huff;
    return T;
}
void insert(MinHeap H, HuffmanTree Huff)
{
    H->size++;
    int i = H->size;
    for (; Huff->weight < H->data[i / 2]->weight; i /= 2)
    {
        H->data[i] = H->data[i / 2];
    }
    H->data[i] = Huff;
}
HuffmanTree createHuffman(MinHeap H)
{
    HuffmanTree Huff;
    int times = H->size;
    for (int i = 1; i < times; i++)
    {
        Huff = createWeightTree();
        Huff->left = Delete(H);
        Huff->right = Delete(H);
        Huff->weight = Huff->left->weight + Huff->right->weight;
        insert(H, Huff);
    }
    Huff = Delete(H);
    return Huff;
}
int roadLength(HuffmanTree Huff)
{
    int first = Huff->weight;
    int length = 0;
    queue<HuffmanTree> q;
    HuffmanTree T;
    if (!Huff)
        return NULL;
    q.push(Huff);
    while (!q.empty())
    {
        T = q.front();
        q.pop();
        length += T->weight;
        if (T->left)
            q.push(T->left);
        if (T->right)
            q.push(T->right);
    }
    return length - first;
}
