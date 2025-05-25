#include "point.h"
#include <algorithm>
#include <iostream>

void insertNode(Point*& root, int value) {
    if (!root) {
        root = new Point(value);
        return;
    }
    if (value < root->data)
        insertNode(root->left, value);
    else
        insertNode(root->right, value);
}

Point* findMin(Point* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

void deleteNode(Point*& root, int value) {
    if (!root)
        return;
    if (value < root->data)
        deleteNode(root->left, value);
    else if (value > root->data)
        deleteNode(root->right, value);
    else {
        if (!root->left) {
            Point* temp = root->right;
            delete root;
            root = temp;
        } else if (!root->right) {
            Point* temp = root->left;
            delete root;
            root = temp;
        } else {
            Point* min = findMin(root->right);
            root->data = min->data;
            deleteNode(root->right, min->data);
        }
    }
}

Point* searchNode(Point* root, int value) {
    if (!root || root->data == value)
        return root;
    if (value < root->data)
        return searchNode(root->left, value);
    return searchNode(root->right, value);
}

void preOrder(Point* root, std::vector<int>& result) {
    if (root) {
        result.push_back(root->data);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
}

void inOrder(Point* root, std::vector<int>& result) {
    if (root) {
        inOrder(root->left, result);
        result.push_back(root->data);
        inOrder(root->right, result);
    }
}

void postOrder(Point* root, std::vector<int>& result) {
    if (root) {
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->data);
    }
}

void storeNodes(Point* root, std::vector<int>& nodes) {
    if (root) {
        storeNodes(root->left, nodes);
        nodes.push_back(root->data);
        storeNodes(root->right, nodes);
    }
}

Point* buildBalancedTree(const std::vector<int>& nodes, int start, int end) {
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    Point* root = new Point(nodes[mid]);
    root->left = buildBalancedTree(nodes, start, mid - 1);
    root->right = buildBalancedTree(nodes, mid + 1, end);
    return root;
}

void balanceTree(Point*& root) {
    std::vector<int> nodes;
    storeNodes(root, nodes);
    std::sort(nodes.begin(), nodes.end());
    freeTree(root);
    root = buildBalancedTree(nodes, 0, nodes.size() - 1);
}

void printVertical(Point* root, int level) {
    if (root) {
        printVertical(root->right, level + 1);
        for (int i = 0; i < level; i++)
            std::cout << "   ";
        std::cout << root->data << std::endl;
        printVertical(root->left, level + 1);
    }
}

void printHorizontal(Point* root) {
    std::vector<int> result;
    inOrder(root, result);
    for (int val : result)
        std::cout << val << " ";
    std::cout << std::endl;
}

void sumAndCount(Point* root, int& sum, int& count) {
    if (root) {
        sum += root->data;
        count++;
        sumAndCount(root->left, sum, count);
        sumAndCount(root->right, sum, count);
    }
}

double averageValue(Point* root) {
    int sum = 0, count = 0;
    sumAndCount(root, sum, count);
    return count > 0 ? static_cast<double>(sum) / count : 0.0;
}

void freeTree(Point*& root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
        root = nullptr;
    }
}
