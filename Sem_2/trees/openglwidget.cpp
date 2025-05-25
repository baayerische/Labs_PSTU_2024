#include "openglwidget.h"
#include <QOpenGLFunctions>
#include <QDebug>
#include <cmath>

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent), root(nullptr) {
    setFixedSize(800, 600);
}

void OpenGLWidget::setTree(Point* root) {
    this->root = root;
    update();
}

void OpenGLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Белый фон
    const GLubyte* version = glGetString(GL_VERSION);
    qDebug() << "OpenGL Version:" << (version ? reinterpret_cast<const char*>(version) : "Not available");
}

void OpenGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, -1, 1); // Ортографическая проекция
    glMatrixMode(GL_MODELVIEW);
}

void OpenGLWidget::paintGL() {
    qDebug() << "Rendering OpenGL";
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    if (root) {
        drawNode(root, width() / 2.0f, 50.0f, 200.0f, 1);
    }
}

void OpenGLWidget::drawNode(Point* node, float x, float y, float offsetX, int level) {
    if (!node)
        return;

    // Рисуем узел (круг)
    glColor3f(0.0f, 0.0f, 0.0f); // Черный контур
    drawCircle(x, y, 20.0f);

    // Рисуем связи к дочерним узлам
    float childOffsetY = 100.0f;
    float childOffsetX = offsetX / (level + 1);

    if (node->left) {
        glColor3f(0.0f, 0.0f, 0.0f);
        drawLine(x, y, x - childOffsetX, y + childOffsetY);
        drawNode(node->left, x - childOffsetX, y + childOffsetY, offsetX, level + 1);
    }
    if (node->right) {
        glColor3f(0.0f, 0.0f, 0.0f);
        drawLine(x, y, x + childOffsetX, y + childOffsetY);
        drawNode(node->right, x + childOffsetX, y + childOffsetY, offsetX, level + 1);
    }
}

void OpenGLWidget::drawCircle(float x, float y, float radius) {
    const int segments = 32;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        float angle = 2.0f * M_PI * i / segments;
        glVertex2f(x + radius * std::cos(angle), y + radius * std::sin(angle));
    }
    glEnd();
}

void OpenGLWidget::drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}
