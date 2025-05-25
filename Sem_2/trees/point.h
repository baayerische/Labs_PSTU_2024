#ifndef POINT_H
#define POINT_H

#include <vector>
#include <string>

struct Point {
    int data;
    Point* left;
    Point* right;
    Point(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Вставка узла
void insertNode(Point*& root, int value);

// Удаление узла
void deleteNode(Point*& root, int value);

// Поиск узла
Point* searchNode(Point* root, int value);

// Обходы дерева
void preOrder(Point* root, std::vector<int>& result);
void inOrder(Point* root, std::vector<int>& result);
void postOrder(Point* root, std::vector<int>& result);

// Балансировка дерева
void balanceTree(Point*& root);

// Печать дерева
void printVertical(Point* root, int level = 0);
void printHorizontal(Point* root);

// Вычисление среднего арифметического
double averageValue(Point* root);

// Освобождение памяти
void freeTree(Point*& root);

#endif // POINT_H
