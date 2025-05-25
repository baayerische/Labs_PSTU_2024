#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <sstream>
#include <iostream>
#include "point.h"
#include "openglwidget.h"

class MainWindow : public QMainWindow {
private:
    Point* root;
    QTextEdit* output;
    QLineEdit* input;
    OpenGLWidget* glWidget;

public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent), root(nullptr) {
        QWidget* centralWidget = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);

        input = new QLineEdit(centralWidget);
        output = new QTextEdit(centralWidget);
        output->setReadOnly(true);
        glWidget = new OpenGLWidget(centralWidget);

        QPushButton* insertBtn = new QPushButton("Вставить узел", centralWidget);
        QPushButton* deleteBtn = new QPushButton("Удалить узел", centralWidget);
        QPushButton* searchBtn = new QPushButton("Найти узел", centralWidget);
        QPushButton* preOrderBtn = new QPushButton("Прямой обход", centralWidget);
        QPushButton* inOrderBtn = new QPushButton("Симметричный обход", centralWidget);
        QPushButton* postOrderBtn = new QPushButton("Обратный обход", centralWidget);
        QPushButton* balanceBtn = new QPushButton("Сбалансировать", centralWidget);
        QPushButton* printVertBtn = new QPushButton("Вертикальная печать", centralWidget);
        QPushButton* printHorzBtn = new QPushButton("Горизонтальная печать", centralWidget);
        QPushButton* averageBtn = new QPushButton("Среднее арифметическое", centralWidget);

        layout->addWidget(input);
        layout->addWidget(insertBtn);
        layout->addWidget(deleteBtn);
        layout->addWidget(searchBtn);
        layout->addWidget(preOrderBtn);
        layout->addWidget(inOrderBtn);
        layout->addWidget(postOrderBtn);
        layout->addWidget(balanceBtn);
        layout->addWidget(printVertBtn);
        layout->addWidget(printHorzBtn);
        layout->addWidget(averageBtn);
        layout->addWidget(output);
        layout->addWidget(glWidget);

        setCentralWidget(centralWidget);

        connect(insertBtn, &QPushButton::clicked, this, &MainWindow::onInsert);
        connect(deleteBtn, &QPushButton::clicked, this, &MainWindow::onDelete);
        connect(searchBtn, &QPushButton::clicked, this, &MainWindow::onSearch);
        connect(preOrderBtn, &QPushButton::clicked, this, &MainWindow::onPreOrder);
        connect(inOrderBtn, &QPushButton::clicked, this, &MainWindow::onInOrder);
        connect(postOrderBtn, &QPushButton::clicked, this, &MainWindow::onPostOrder);
        connect(balanceBtn, &QPushButton::clicked, this, &MainWindow::onBalance);
        connect(printVertBtn, &QPushButton::clicked, this, &MainWindow::onPrintVertical);
        connect(printHorzBtn, &QPushButton::clicked, this, &MainWindow::onPrintHorizontal);
        connect(averageBtn, &QPushButton::clicked, this, &MainWindow::onAverage);

        updateVisualization();
    }

    ~MainWindow() {
        freeTree(root);
    }

private slots:
    void onInsert() {
        bool ok;
        int value = input->text().toInt(&ok);
        if (ok) {
            insertNode(root, value);
            output->append(QString("Вставлен узел: %1").arg(value));
            updateVisualization();
        } else {
            output->append("Ошибка: введите целое число");
        }
    }

    void onDelete() {
        bool ok;
        int value = input->text().toInt(&ok);
        if (ok) {
            deleteNode(root, value);
            output->append(QString("Удален узел: %1").arg(value));
            updateVisualization();
        } else {
            output->append("Ошибка: введите целое число");
        }
    }

    void onSearch() {
        bool ok;
        int value = input->text().toInt(&ok);
        if (ok) {
            Point* node = searchNode(root, value);
            output->append(node ? QString("Узел %1 найден").arg(value) : QString("Узел %1 не найден").arg(value));
        } else {
            output->append("Ошибка: введите целое число");
        }
    }

    void onPreOrder() {
        std::vector<int> result;
        preOrder(root, result);
        QString out = "Прямой обход: ";
        for (int val : result)
            out += QString::number(val) + " ";
        output->append(out);
    }

    void onInOrder() {
        std::vector<int> result;
        inOrder(root, result);
        QString out = "Симметричный обход: ";
        for (int val : result)
            out += QString::number(val) + " ";
        output->append(out);
    }

    void onPostOrder() {
        std::vector<int> result;
        postOrder(root, result);
        QString out = "Обратный обход: ";
        for (int val : result)
            out += QString::number(val) + " ";
        output->append(out);
    }

    void onBalance() {
        balanceTree(root);
        output->append("Дерево сбалансировано");
        updateVisualization();
    }

    void onPrintVertical() {
        output->append("Вертикальная печать:");
        std::stringstream ss;
        std::streambuf* old = std::cout.rdbuf(ss.rdbuf());
        printVertical(root);
        std::cout.rdbuf(old);
        output->append(QString::fromStdString(ss.str()));
    }

    void onPrintHorizontal() {
        std::vector<int> result;
        inOrder(root, result);
        QString out = "Горизонтальная печать: ";
        for (int val : result)
            out += QString::number(val) + " ";
        output->append(out);
    }

    void onAverage() {
        double avg = averageValue(root);
        output->append(QString("Среднее арифметическое: %1").arg(avg));
    }

    void updateVisualization() {
        glWidget->setTree(root);
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
