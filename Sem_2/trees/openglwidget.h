#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "point.h"

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget* parent = nullptr);
    void setTree(Point* root);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    Point* root;
    void drawNode(Point* node, float x, float y, float offsetX, int level);
    void drawCircle(float x, float y, float radius);
    void drawLine(float x1, float y1, float x2, float y2);
};

#endif
