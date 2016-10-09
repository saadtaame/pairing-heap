
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct HeapNode {

    int key;
    HeapNode *leftChild;
    HeapNode *nextSibling;

    HeapNode():
        leftChild(NULL), nextSibling(NULL) {}

    HeapNode(int key_, HeapNode *leftChild_, HeapNode *nextSibling_):
        key(key_), leftChild(leftChild_), nextSibling(nextSibling_) {}

    void addChild(HeapNode *node) {
        if(leftChild == NULL)
            leftChild = node;
        else {
            node->nextSibling = leftChild;
            leftChild = node;
        }
    }
};

bool Empty(HeapNode *node) {
    return (node == NULL);
}

HeapNode *Merge(HeapNode *A, HeapNode *B) {
    if(A == NULL) return B;
    if(B == NULL) return A;
    if(A->key < B->key) {
        A->addChild(B);
        return A;
    }
    else {
        B->addChild(A);
        return B;
    }

    return NULL; // Unreachable
}

int Top(HeapNode *node) {
    return node->key;
}

HeapNode *Push(HeapNode *node, int key) {
    return Merge(node, new HeapNode(key, NULL, NULL));
}

HeapNode *TwoPassMerge(HeapNode *node) {
    if(node == NULL || node->nextSibling == NULL)
        return node;
    else {
        HeapNode *A, *B, *newNode;
        A = node;
        B = node->nextSibling;
        newNode = node->nextSibling->nextSibling;

        A->nextSibling = NULL;
        B->nextSibling = NULL;

        return Merge(Merge(A, B), TwoPassMerge(newNode));
    }

    return NULL; // Unreachable
}

HeapNode *Pop(HeapNode *node) {
    return TwoPassMerge(node->leftChild);
}

struct PairingHeap {
    HeapNode *root;

    PairingHeap():
        root(NULL) {}

    bool Empty(void) {
        return ::Empty(root);
    }

    int Top(void) {
        return ::Top(root);
    }

    void Push(int key) {
        root = ::Push(root, key);
    }

    void Pop(void) {
        root = ::Pop(root);
    }

    void Join(PairingHeap other) {
        root = ::Merge(root, other.root);
    }
};

int main(void) {

    PairingHeap heap1, heap2;
    heap1.Push(4);
    heap1.Push(2);

    heap2.Push(5);
    heap2.Push(-1);

    heap1.Join(heap2);

    cout << heap1.Top() << endl;
    return 0;
}
