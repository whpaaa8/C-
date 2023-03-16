#ifndef NODE_EDGE_H
#define NODE_EDGE_H
#include <QString>
#include<QDebug>
#include <QApplication>
#include<iostream>
#include<QVector>
#include<queue>
#include<stack>
#include<list>
#include <conio.h>
#include <math.h>
#include<random>
#include<algorithm>
#include<QTimer>
#include <QtGlobal>
#include<QTime>
#include<QPainter>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QWheelEvent>
using namespace std;
class Node {
public:
    int number;
    int x;
    int y;
    int GetX() {
        return x;
    }
    int GetY() {
        return y;
    }
    void SetX(int m) {
        x = m;
    }
    void SetY(int n) {
        y = n;
    }
    Node() { x = y = 0; number = -1; }
    Node(int a, int b, int c) {
        x = a;
        y = b;
        number = c;
    }
    friend bool operator ==(const Node& node1, const Node& node2) {
        if (node1.x == node2.x && node1.y == node2.y) {
            return true;
        }
        else
            return false;
    }
};
class Edge {
public:
    Node Node1;
    Node Node2;
    int distance;
    int v; //饱和车流量
    int n; //当前车流量
    int t;      //记录行车时间
    double x; //表示这条路的拥挤程度        x在5-15
    bool flag;
//              x <= 1 ,通畅，绿色
//              1 < x <= 1.25，略堵，黄色
//              x > 1.25 很堵， 红色
    Node GetNode1() {
        return Node1;
    }
    Node GetNode2() {
        return Node2;
    }
    Edge() { distance = t = -1; v = n = 0; x = 0; flag = 1;}
    Edge(Node a, Node b) {
        Node1 = a;
        Node2 = b;
        distance = int(ceil(sqrt((Node1.x - Node2.x) * (Node1.x - Node2.x) + (Node1.y - Node2.y) * (Node1.y - Node2.y))));
        v = distance * 80 /10;
        n = 0;
        x = double(n) /double(v);
        t = -1;
        flag = 1;
        //qDebug() << Node1.x << "   "  << Node1.y << "  " << Node2.x << "  " << Node2.y << endl;
    }
    void set_t()
    {
        double c = 0.05;
        if (x <= 1) t =int(ceil( c * distance));
        if (x > 1) t =int(ceil( c * distance*(1+1.8*x)));
    }
    void set_n()            //n用随机数表示
    {
        set_x();        //随机生成x
        n = int(x * v);
        flag = 1;
        set_t();
    }
    void set_x()
    {


         int test =qrand()%10;
         x = double((test + 5)) / 10;

    }
};
extern QVector<Node> NodeArray;
extern QVector<Edge> EdgeArray;

#endif // NODE_EDGE_H
