#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPainter>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   // void paintEvent(QPaintEvent *event);
public slots:
    //bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::MainWindow *ui;
    QRect rect;
       float zoom;//缩放系数
       QPoint CurrentCoordinates,LastCoordinates;
};
#endif // MAINWINDOW_H
