#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include<QGraphicsView>

class CustomView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomView(QWidget *parent = nullptr);
    void wheelEvent(QWheelEvent *event);
    void draw(bool m1 = 1,bool m2 = 1,bool m3 = 1,bool m4 = 1,bool m0 = 1);
    void print();
signals:

public slots:
};

#endif // CUSTOMVIEW_H
