#include "customview.h"
#include <QPointF>
#include<QGraphicsView>
#include<QWheelEvent>
#include<QScrollBar>
#include<QDebug>
#include<QPainter>
#include<QGraphicsItem>
#include<QPixmap>

#include "Node_Edge.h"

CustomView::CustomView(QWidget *parent) : QGraphicsView(parent)
{


}
void CustomView::print()
{
    for (int i = 0; i < 100 ; i++) qDebug() << NodeArray[i].number << endl;
}
void CustomView::wheelEvent(QWheelEvent *event)
{
    // 获取当前鼠标相对于view的位置;
    QPointF cursorPoint = event->pos();
    // 获取当前鼠标相对于scene的位置;
    QPointF scenePos = this->mapToScene(QPoint(cursorPoint.x(), cursorPoint.y()));

    // 获取view的宽高;
    qreal viewWidth = this->viewport()->width();
    qreal viewHeight = this->viewport()->height();

    // 获取当前鼠标位置相当于view大小的横纵比例;
    qreal hScale = cursorPoint.x() / viewWidth;
    qreal vScale = cursorPoint.y() / viewHeight;

    // 当前放缩倍数;
    qreal scaleFactor = this->matrix().m11();
    int wheelDeltaValue = event->delta();
    // 向上滚动，放大;
    if (wheelDeltaValue > 0)
    {
        this->scale(1.2, 1.2);

    }
    // 向下滚动，缩小;
    else
    {
        this->scale(1.0 / 1.2, 1.0 / 1.2);

    }

    // 将scene坐标转换为放大缩小后的坐标;
    QPointF viewPoint = this->matrix().map(scenePos);
    // 通过滚动条控制view放大缩小后的展示scene的位置;
    horizontalScrollBar()->setValue(int(viewPoint.x() - viewWidth * hScale));
    verticalScrollBar()->setValue(int(viewPoint.y() - viewHeight * vScale));
}
void CustomView::draw(bool m1,bool m2,bool m3,bool m4,bool m0) //m0是指定路径
{
    /*
     *  m = 0 只画点
     *  m = 1 画线和点（全黑）
     *  m = 2 模拟车流
     *  m = 3 标记路径
   */

    QGraphicsScene* scene=new QGraphicsScene();


        QPen pen0;
        pen0.setColor(Qt::black);
            pen0.setWidth(3);
     QGraphicsPathItem *m_pathItem1 = new QGraphicsPathItem();m_pathItem1->setPen(pen0);    //黑色
     QGraphicsPathItem *m_pathItem2 = new QGraphicsPathItem();pen0.setColor(Qt::green);m_pathItem2->setPen(pen0);   //绿色
     QGraphicsPathItem *m_pathItem3 = new QGraphicsPathItem();pen0.setColor(Qt::yellow);m_pathItem3->setPen(pen0);   //黄色
     QGraphicsPathItem *m_pathItem4 = new QGraphicsPathItem();pen0.setColor(Qt::red);   //红色
    QPainterPath path1,path2,path3,path4;
  /*  int x1 = EdgeArray[0].Node1.x, y1 = EdgeArray[0].Node1.y;
     int x2 = EdgeArray[0].Node2.x, y2 = EdgeArray[0].Node2.y;
     path1.moveTo(x1,y1);path1.lineTo(x2,y2);*/
    if (m1||m2||m3||m4)for (int i = 0;i < 150 ; i++)
    {   QPainterPath p;
        int x1 = EdgeArray[i].Node1.x, y1 = EdgeArray[i].Node1.y;
         int x2 = EdgeArray[i].Node2.x, y2 = EdgeArray[i].Node2.y;
         if ((EdgeArray[i].flag == false) && (m0 == 0))
         {p.moveTo(x1,y1);p.lineTo(x2,y2);
              EdgeArray[i].flag = 1;
            /* qDebug() << EdgeArray[i].Node1.number << "-" <<EdgeArray[i].Node2.number <<"  " ;
             qDebug() << EdgeArray[i].flag << endl;*/
         }    //如果只显示一条路径

        if (!EdgeArray[i].flag) qDebug() << "no" << endl;
         if (m0) {p.moveTo(x1,y1);p.lineTo(x2,y2);}
         if (EdgeArray[i].x == 0)  path1.addPath(p); else
        if (EdgeArray[i].x <= 1)  path2.addPath(p);
        if (EdgeArray[i].x <= 1.25 &&EdgeArray[i].x > 1 )  path3.addPath(p);
         if (EdgeArray[i].x == 2) {path4.addPath(p); pen0.setWidth(6);   m_pathItem4->setPen(pen0);     }
        if (EdgeArray[i].x > 1.25 && EdgeArray[i].x < 2)   { path4.addPath(p);m_pathItem4->setPen(pen0);}

   }
       QPen pen1;pen1.setColor(Qt::gray);
      // pen1.setBrush(Qt::gray);
       pen1.setWidth(3);
        QGraphicsRectItem  *pItem = new QGraphicsRectItem[100]();
        for (int i = 0; i < 100 ; i++)
        {   int x1 = NodeArray[i].x, y1 = NodeArray[i].y;
            pItem[i].setRect(QRectF(x1-10, y1-10, 20, 20));
            pItem[i].setPen(pen1);
            pItem[i].setBrush(Qt::gray);
        }
        QGraphicsTextItem *pp = new QGraphicsTextItem[100]();
        for (int i = 0; i < 100; i++)
         {
            int x1 = NodeArray[i].x, y1 = NodeArray[i].y;
            pp[i].setPlainText(QString::number(i,10));
            pp[i].setDefaultTextColor(Qt::red);
            pp[i].setPos(x1-12.5,y1-12.5);
        }

     m_pathItem1->setPath(path1);
     m_pathItem2->setPath(path2);
     m_pathItem3->setPath(path3);
     m_pathItem4->setPath(path4);
           /* QGraphicsLineItem *m_lineItem1 = new QGraphicsLineItem();
             m_lineItem1->setLine(0, 0, 80, 80);
            QGraphicsLineItem *m_lineItem2 = new QGraphicsLineItem();
            m_lineItem2->setLine(QLineF(50, 150, -100, -100));*/
    this->setScene(scene);
     if (m1) scene->addItem(m_pathItem1);
     if (m2) scene->addItem(m_pathItem2);
     if (m3) scene->addItem(m_pathItem3);
     if (m4) scene->addItem(m_pathItem4);
     for (int i = 0 ; i < 100; i++) {scene->addItem(&pItem[i]);scene->addItem(&pp[i]);}

}


