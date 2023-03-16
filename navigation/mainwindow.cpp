#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customview.h"
#include "mainwindow.h"
#include "Node_Edge.h"
#include <QString>
#include<QDebug>
#include <QApplication>
#include<QVector>
#include<list>
#include <conio.h>
#include <math.h>
#include<random>
#include<algorithm>
#include<QTimer>
#include <QtGlobal>
#include<QTime>
#include <QMouseEvent>
#include <QDebug>
#include <QWheelEvent>
#include<QPainter>
#include "Node_Edge.h"
#pragma once
#define nmax 110
#define inf 999999999
using namespace std;
QVector<Node> NodeArray;
QVector<Edge> EdgeArray;
const int Nodenumber = 100;
int Edgenumber = 150;
struct smadistance {
public:
    int distance;
    Node node;
};
QVector<Edge> shopath;
bool md = 0;
Edge e0;
QVector<QVector<Edge>> edge(Nodenumber,QVector<Edge>(Nodenumber,e0));
int dis[Nodenumber];
void setgraph(int , int , int , int ); //画图的主函数
void RandomArray(int* arr, int Amounts);
bool IsNodeConnected(Node node1, Node node2);
void CreatNewNodeX_Y(Node& new_node, Node cur_node, int EdgeMaxLen, int EdgeMinLen);
bool  IsEdgeIntersectedEdgeArray(Edge& edge);
bool  IsEdgeIntersectedEdgeArray(Node cur_node, Node new_node);
void setgraph(int NodeCounts, int EdgeCounts, int EdgeMaxLen, int EdgeMinLen) {
    int* randomArray = new int[NodeCounts];
    RandomArray(randomArray, NodeCounts);
    srand(time(NULL));
    //顺序的遍历随机序列，添加边
    for (int i = 0; i < NodeCounts; ++i)
    {
        //如果是第一个，设置其坐标为(0,0)
        if (i == 0)
        {
            Node new_node(0, 0, i);
            NodeArray.push_back(new_node);
        }
        //否则，随机确定其坐标
        else
        {
            //从已经确定坐标的点中，随机挑选一个出来作为连接节点
            int val = rand() % i;
            Node choose_node = NodeArray.at(val);
            //产生符合要求的新节点
            Node new_node(800, 450, i);
            CreatNewNodeX_Y(new_node, choose_node, EdgeMaxLen, EdgeMinLen);
            //将边和节点添加进容器中
            Edge new_edge(choose_node, new_node);
            EdgeArray.push_back(new_edge);
            NodeArray.push_back(new_node);
        }
    }
    //再添加剩余的边
    while (EdgeArray.size() < (EdgeCounts))
    {
        int node1_id = 0, node2_id = 0;
        while (node1_id == node2_id)
        {
            //RandomCreatFunc(1, NodeArray.size());
            node1_id = rand() % NodeArray.size();
            node2_id = rand() % NodeArray.size();
        }
        Node choose_node1 = NodeArray.at(node1_id);
        Node choose_node2 = NodeArray.at(node2_id);
        Edge newEdge(choose_node1, choose_node2);
        EdgeArray.push_back(newEdge);
    }
}
double mult(Node a, Node b, Node c)
{
    return double((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y));
}
bool intersect(Node aa, Node bb, Node cc, Node dd)
{
    if (max(aa.GetX(), bb.GetX()) < min(cc.GetX(), dd.GetX()))
    {
        return false;
    }
    if (max(aa.GetY(), bb.GetY()) < min(cc.GetY(), dd.GetY()))
    {
        return false;
    }
    if (max(cc.GetX(), dd.GetX()) < min(aa.GetX(), bb.GetX()))
    {
        return false;
    }
    if (max(cc.GetY(), dd.GetY()) < min(aa.GetY(), bb.GetY()))
    {
        return false;
    }
    if (mult(cc, bb, aa) * mult(bb, dd, aa) < 0)
    {
        return false;
    }
    if (mult(aa, dd, cc) * mult(dd, bb, cc) < 0)
    {
        return false;
    }
    return true;
}
double determinant(double v1, double v2, double v3, double v4)  // 行列式
{
    return (v1 * v3 - v2 * v4);
}
//判断两个边(线段)是否相交 是-返回true 否-返回false
bool IsIntersect(Edge edge1, Edge edge2)
{
    Node a, b, c, d;
    a = edge1.GetNode1();
    b = edge1.GetNode2();
    c = edge2.GetNode1();
    d = edge2.GetNode2();
    return intersect(a, b, c, d);
}
//判断节点node,是否在node1和node2的线段上 是-返回1 否-返回0
 int on_segment(Node node, Node& node1, Node& node2)
{
    int x1 = node1.GetX();
    int x2 = node2.GetX();
    int y1 = node1.GetY();
    int y2 = node2.GetY();
    double max = x1 > x2 ? x1 : x2;
    double min = x1 < x2 ? x1 : x2;
    double max1 = y1 > y2 ? y1 : y2;
    double min1 = y1 < y2 ? y1 : y2;
    if (node.GetX() >= min && node.GetX() <= max &&
        node.GetY() >= min1 && node.GetY() <= max1)
        return 1;
    else
        return 0;
}
//判断新边是否与现有的边相交（除去相邻的边）是-返回true 否-返回false
bool  IsEdgeIntersectedEdgeArray(Edge& edge)
{
    Node node1, node2;//边取出的两个节点
    Edge Aedge;//容器中取出的边
    Node edge_node1, edge_node2;
    edge_node1 = edge.GetNode1();
    edge_node2 = edge.GetNode2();
   QVector<Edge>::const_iterator iterator = EdgeArray.begin();
    for (; iterator != EdgeArray.end(); ++iterator)
    {
        Aedge = (*iterator);
        node1 = Aedge.GetNode1();
        node2 = Aedge.GetNode2();
        //如果两个边有同样的节点，则直接跳过
        if (node1 == edge_node1 || node1 == edge_node2 || node2 == edge_node1 || node2 == edge_node2)
            continue;
        if (IsIntersect(edge, Aedge) == true)
            return true;
    }
    return false;
}
bool  IsEdgeIntersectedEdgeArray(Node cur_node, Node new_node)
{
    Edge edge(cur_node, new_node);
    Edge Aedge;//容器中取出的边
     //如果尚未有边，则返回false
    if (EdgeArray.size() == 0)
        return false;
    QVector<Edge>::const_iterator iterator = EdgeArray.begin();
    for (; iterator != EdgeArray.end(); ++iterator)
    {
        Aedge = (*iterator);
        //如果旧节点是边的其中一个节点，则不需要判断，直接下一个循环
        if (Aedge.GetNode1() == cur_node || Aedge.GetNode2() == cur_node)
            continue;
        if (IsIntersect(edge, Aedge) == true)
            return true;
    }
    return false;
}
//判断节点是否在已存边的任意一条边上 是-返回true 否-返回false
bool IsNodeInEdgeArray(const Node& node)
{
    Node node1, node2;//边取出的两个节点
    Edge edge;//容器中取出的边
    int Counts = 0;
    //如果尚未有边，则返回false
    if (EdgeArray.size() == 0)
        return false;
    //将节点与所有边进行判断是否在线段上
    QVector<Edge>::const_iterator iterator = EdgeArray.begin();
    for (; iterator != EdgeArray.end(); ++iterator)
    {
        edge = (*iterator);
        node1 = edge.GetNode1();
        node2 = edge.GetNode2();
        Counts += on_segment(node, node1, node2);
    }
    if (Counts == 0)
        return false;
    else
        return true;
}
int RandomCreatFunc(int interval_min, int interval_max)
{
    if (interval_min >= interval_max)
        return INT_MAX;
    //种子值是通过 random_device 类型的函数对象 rd 获得的。
    //每一个 rd() 调用都会返回不同的值，而且如果我们实现的 random_devic 是非确定性的，程序每次执行连续调用 rd() 都会产生不同的序列。
    random_device rd;
    static default_random_engine e{ rd() };
    int random_num = 0;
    //分情况产生随机数，考虑3种情况：min<0&&max>0 、max<0和min>0
    if (interval_min >= 0)//min>0的情况
    {
        static uniform_int_distribution<unsigned> a(interval_min, interval_max);
        random_num = a(e);
    }
    else if (interval_max > 0)//min<0&&max>0 的情况
    {
        static uniform_int_distribution<unsigned> a(0, -interval_min);
        random_num = a(e);
        random_num = -random_num;
        static uniform_int_distribution<unsigned> b(0, 10);
        if (b(e) % 2 == 0)
        {
            static uniform_int_distribution<unsigned> c(0, interval_max);
            random_num = c(e);
        }
    }
    else//max<0的情况
    {
        static uniform_int_distribution<unsigned> a(-interval_max, -interval_min);
        random_num = a(e);
        random_num = -random_num;
    }
    return random_num;
}
void RandomArray(int* arr, int Amounts)
{
    for (int i = 0; i < Amounts; ++i)
        arr[i] = 0;
    int count = 0;		//计数，
    int k = 0;
    while (count < Amounts)
    {   k++;
        if (k > 10000) return;
        int val = RandomCreatFunc(0, Amounts - 1);//随机确定下标
        if (!arr[val])
        {
            arr[val] = count + 1;
            ++count;
        }
    }
}
void CreatNewNodeX_Y(Node& new_node, Node cur_node, int EdgeMaxLen, int EdgeMinLen)
{
    //判断参数
    if (EdgeMaxLen <= EdgeMinLen) return;

    int new_nodeX1 = 0, new_nodeY1 = 0, new_nodeX = 0, new_nodeY = 0;
    //四个区间，x和y分别有两个区间


    //设置随机数种子
    srand((unsigned int)time(NULL));
    random_device rd;
    default_random_engine e{ rd() };
        //随机产生坐标
        //这里有四个区间，这里先分别产生1个x的随机数，1个y的随机数，再根据对称原理（对称轴为cur_node的x和y这两条直线）产生对称的x和y，最后由随机数确定该选哪个x和y
        //产生2个x和2个y
    new_nodeX1 = RandomCreatFunc(-500, 500);
    new_nodeY1 = RandomCreatFunc(-300, 300);
            new_nodeX = new_nodeX1;
            new_nodeY = new_nodeY1;
        //new_nodeX= rand() / (double)RAND_MAX *(Xmax - Xmin) + Xmin;
        //srand((unsigned)time(NULL));
        //new_nodeY= rand() / (double)RAND_MAX *(Ymax - Ymin) + Ymin;
        //设置节点坐标
        new_node.SetX(new_nodeX);
        new_node.SetY(new_nodeY);
        //如果符合要求，跳出循环
}
bool IsNodeConnected(Node node1, Node node2)
{
    Edge edge;
    Node edge_node1, edge_node2;
    QVector<Edge>::const_iterator iter = EdgeArray.begin();
    for (; iter != EdgeArray.end(); ++iter)
    {
        edge = (*iter);
        if (edge.GetNode1() == node1 && edge.GetNode2() == node2)
            return true;
        else if (edge.GetNode1() == node2 && edge.GetNode2() == node1)
            return true;
    }
    return false;
}
bool comp(const struct smadistance& a, const struct smadistance& b)
{
    return a.distance < b.distance;
}

    ///--------------------------------- 我写的部分-------------------------------//

        //---------函数声明--------//
class Data			//用来保存最短路径及其顶点连边
{
public:
    QVector<QString> path;
    QVector<long long>	dst;
    Node* select;
    Node node1, node2;
    Data()
    {
        select = new Node[Nodenumber]();
        for (int i = 0; i < Nodenumber; i++)
        {
            path.push_back("");
            dst.push_back(0);
        }
    }
    Data(Node n1, Node n2, QVector<QString> p, QVector<long long> d, Node* s)
    {
        select = new Node[Nodenumber]();
        for (int i = 0; i < Nodenumber; i++)
        {
            path.push_back(p[i]);
            dst.push_back(d[i]);
            select[i] = s[i];
        }
        node1 = n1;
        node2 = n2;
    }
    Data(const Data& D)
    {
        select = new Node[Nodenumber]();
        for (int i = 0; i < Nodenumber; i++)
        {
            path.push_back(D.path[i]);
            dst.push_back(D.dst[i]);
            select[i] = D.select[i];
        }
        node1 = D.node1;
        node2 = D.node2;
    }
    void showdata()
    {
        int i = 0;
        if (node2.number == 20000) node2.number = node1.number;
       //qDebug() << path[node2.number] << endl;
          int d = 0; int t = 0;
        while ( i < 10)
        {
            int j = 0;
            j = select[i].number;
            /*qDebug() << "从" << node1.number << "到" << j << endl;
            qDebug() << "最短路径是：   " << path[j] << endl;
            qDebug() << "最短长度是：   " << dst[j] << endl;
            qDebug() << endl;*/
           // d +=EdgeArray[j].distance; t+=EdgeArray[j].t;
           // cout << d << "  " << t << endl;


            i++;
            //if (i>=10000){ cout << "out of range" << endl; break; }
        }
        cout << "最短长度是：   " << dst[node2.number] << endl;
        //QString::fromLocal8Bit("")

    }
    QString showpoint()
    {   QString s = "";
        for (int i = 0 ;i < 30; i++)
        {   if(select[i].number == -1) break;
            s += QString::number(select[i].number,10);
            if ((i % 10 == 0) || (i % 5 != 0)) s+= ",";
            else if (i % 5 == 0) s+= "\n";
        }
        return s;
    }
    ~Data()
    {
        delete[]select;
    }
};
QString findnearpoint(Node, int);
void inputedge();
string trchar(int);
void findmin_t(Node*, QVector<bool>& , QVector<int>& , QVector<QString>& );
void findmin_distance(Node* ,QVector<bool>& ,QVector<int>& ,QVector<QString>& );
Data shortpath(Node, Node, bool, int);
int trchar2(QString&,bool);
    //-----------函数定义-----------//
QString findnearpoint(Node n1,int n0 = 31)
{
    Node n2(0, 0, 101);
    Data d = shortpath(n1, n2, 0,n0);

    // dst[select[n].number]是第n短的长度，对应的点是select[n]路径是path[select[n].number]
    int i = 0;
   // d.showdata();

    while ( i < n0)
    {
        int n = d.select[i].number;
       // qDebug() << d.path[n] << endl;
        while(d.path[n].indexOf('-') != -1)
        {   //if (num++ > 100) break;
            int v0 = trchar2(d.path[n],1);
            int v1 = trchar2(d.path[n],0);
            edge[v0][v1].x = edge[v1][v0].x = 2.0;  //将其标记，x=2.0
             edge[v0][v1].flag = edge[v1][v0].flag = 0;
        }

        i++;
    }
    for (int i = 0; i < 150 ; i++)
    {
       int v0 = EdgeArray[i].Node1.number;
       int v1 = EdgeArray[i].Node2.number;
       if (edge[v0][v1].flag == 0 || edge[v1][v0].flag == 0 ) {EdgeArray[i].flag = 0;edge[v0][v1].flag = edge[v1][v0].flag = 1;//qDebug()<<i << ":" << v0<<"-"<<v1<<endl;
       }

    }
    //qDebug() << "pass" << endl;
    return d.showpoint();
    return "yes";
}
int trchar2(QString &s,bool p)
{
    QString s0 = "";
    if (s.indexOf('-') == -1 && s!="") return s.toInt();
     if (s.indexOf('-') == -1 ) return 0;
    int i = 0;
    while(s[i] != '-')
    {
       s0 += s[i];
       i++;
    }
    int num = s0.toInt();
    if (p) s.remove(0,i+1);
    return num;
}
void inputedge()						//输入数据
{
//	for (int i = 0; i < 10000; i++) edge[i].resize(10000);
    int i = 0;
    while (i < Edgenumber)
    {
        int v0 = EdgeArray[i].Node1.number;
        int v1 = EdgeArray[i].Node2.number;
        edge[v0][v1] = edge[v1][v0]= EdgeArray[i];
        i++;
    }
}
QString trchar1(int n)		//将一个整形转换为字符串
{
    QString s = "";
    while (n != 0)
    {
        int m = n % 10;		//余数
        s += char(m + 48);
        n = n / 10;
    }
    reverse(s.begin(), s.end());   //倒序字符串
    return s;
}

void findmin_t(Node* select, QVector<bool>& mark, QVector<long long>& dst, QVector<QString>& path)		//迪杰斯特拉算法，每次找最小的时间，最快
{
    int i = 0;

    int m = 0;			//记录本次加入的节点
    while (select[i].number != -1)
    {
        long long min = 92233720368547758;	//记录本次边的最小值
        for (int j = 0; j < Nodenumber; j++)
        {
            if (edge[select[i].number][j].t != -1 && mark[j])			//如果这条边可以选
                if (((edge[select[i].number][j].t + dst[select[i].number] < dst[j]) || dst[j] == 0))
                {
                    dst[j] = edge[select[i].number][j].t + dst[select[i].number];
                    if (path[select[i].number] == "") path[select[i].number] = trchar1(select[i].number);
                    path[j] = path[select[i].number] + "-" + trchar1(j);
                }
        }
        for (int j = 0; j < Nodenumber; j++)
        {
            if (dst[j] != 0 && mark[j])			//在所有dst中找最小的，如果dst存在且这条边可以选
                if (min > dst[j]) { min = dst[j]; m = j; }
        }
        i++;
        if (i >= Nodenumber) break;
    }
    mark[m] = 0;		// 加入集合w
    //path[m] = path[m0] + "-" + trchar(m);	//新一个节点的路径是边的起始点的路径加上新加入的点,格式是 '45-85-75';
    select[i].number = m; //select的下一个是number为m的节点
}
void findmin_distance(Node* select, QVector<bool>& mark, QVector<long long>& dst,QVector<QString>& path)		//迪杰斯特拉算法，每次找最小的距离，最短
{
    int i = 0;
    int m = 0;			//记录本次加入的节点
    while (select[i].number != -1)
    {
        long long min = 92233720368547758;	//记录本次边的最小值
        for (int j = 0; j < Nodenumber; j++)
        {
            if (edge[select[i].number][j].distance != -1 && mark[j])			//如果这条边可以选
                if (((edge[select[i].number][j].distance + dst[select[i].number] < dst[j]) || dst[j] == 0))
            {
                dst[j] = edge[select[i].number][j].distance + dst[select[i].number];
                if (path[select[i].number] == "") path[select[i].number] = trchar1(select[i].number);
                path[j] = path[select[i].number] + "-" + trchar1(j);
            }
        }
        for (int j = 0; j < Nodenumber; j++)
        {	if (dst[j] != 0 && mark[j])			//在所有dst中找最小的，如果dst存在且这条边可以选
            if (min > dst[j]) { min = dst[j]; m = j; }
        }
        i++;
        if (i >= Nodenumber) { cout << "out of range" << endl; break; }
    }
    mark[m] = 0;		// 加入集合w
    //path[m] = path[m0] + "-" + trchar(m);	//新一个节点的路径是边的起始点的路径加上新加入的点,格式是 '45-85-75';
    select[i].number = m; //select的下一个是number为m的节点
}
Data shortpath(Node n1, Node n2, bool p0,int num0 = 10)// 节点数 ,p用来表示是求时间还是距离	p=0 求距离；p=1求时间
{
    QVector<QString> path(Nodenumber+1, "");	//用来记录路径，每个节点存放一个路径
    QVector<long long> dst(Nodenumber+1, 0);		//用来存放节点的总时间
    QVector<bool> mark(Nodenumber+1, 1);	//标记节点是否被选择
    Node* select;					//用来存储已经选择，加入了集合的节点
    select = new Node[Nodenumber+1];
    select[0] = n1;
    path[n1.number] =path[n1.number] + trchar1(n1.number);
    dst[n1.number] = 0;
    mark[n1.number] = 0;
    int p = 0;
    while (1 )
    {
        if (!p0 && p == num0+1) break;
        if (p0) findmin_t(select, mark, dst, path);					// 求时间和距离
        else  findmin_distance(select, mark, dst, path);
        if ( select[p].number == n2.number) break;
        {
            p++;
        }
        if (p >= Nodenumber) { cout << "out of range" << endl; break; }
    }
    //dst[n2.number];		//返回最短路径；
    Data a1(n1,n2, path, dst, select);			//存放数据
    delete[]select;
    return a1;
}
void getpath(Data d)
{       int n =d.node2.number;
        while(d.path[n].indexOf('-') != -1)
        {
            int v0 = trchar2(d.path[n],1);
            int v1 = trchar2(d.path[n],0);
            //qDebug() << n <<" :" << d.path[n] << endl;
            edge[v0][v1].flag = edge[v1][v0].flag = 0;  //将其标记，x=2.0
            //qDebug()<<v0<<"-"<<v1<<endl;
        }

        for (int i = 0; i < 150 ; i++)
        {
           int v0 = EdgeArray[i].Node1.number;
           int v1 = EdgeArray[i].Node2.number;
           if (edge[v0][v1].flag == 0 || edge[v1][v0].flag == 0 ) {EdgeArray[i].flag = 0;edge[v0][v1].flag = edge[v1][v0].flag = 1;qDebug()<<i << ":" << v0<<"-"<<v1<<endl;}

        }


}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setgraph(Nodenumber,Edgenumber,1000,0);
    inputedge();
   // ui->Graph->installEventFilter(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QTimer* timer = new QTimer();
    //设置时间间隔

     ui->graphicsView->draw(0,0,0,0);
    Node n0(0,0,101);
    NodeArray.push_back(n0);
    EdgeArray.push_back(e0);
    connect(ui->start,&QPushButton::clicked,this,[=](){ui->graphicsView->draw(1,0,0,0);});
    connect(ui->m_start,&QPushButton::clicked,timer,[=](){timer->start(3000);ui->start->click();});        //模拟车流开始
    connect(timer,&QTimer::timeout,this,[=](){
        int i = 0; static int num = 0;
        num++;
        bool m1 = 1,m2 = ui->m1->isChecked(),m3 = ui->m2->isChecked(),m4 = ui->m3->isChecked();
        while (i < Edgenumber)
        {
            EdgeArray[i].set_n();
            int v0 = EdgeArray[i].Node1.number;
            int v1 = EdgeArray[i].Node2.number;
            edge[v0][v1] = edge[v1][v0] = EdgeArray[i];
            if (edge[v0][v1].x == 2.0) EdgeArray[i].x = 2.0;
            i++;
        }
        md = 1;
        //if (num == 2)  setx();
        ui->graphicsView->draw(m1,m2,m3,m4);
    }
      );                                                         //模拟车流
     connect(ui->m_end,&QPushButton::clicked,timer,[=]()
     {timer->stop();
         int i = 0;
         /*while (i < Edgenumber)
         {
              EdgeArray[i].x = 0.0;
             i++;

         }*/
         ui->graphicsView->draw(1,0,0,0);
         ui->m1->setCheckState(Qt::Unchecked);
         ui->m2->setCheckState(Qt::Unchecked);
         ui->m3->setCheckState(Qt::Unchecked);
     });//模拟车流结束
     connect(ui->f_start,&QPushButton::clicked,this,[=](){
            int n = ui->f_in->text().toInt();

         QString s =  findnearpoint(NodeArray[n],30);
         //qDebug() << "ys" << endl;
         int i =0;
         while (i < Edgenumber)
         {
             int v0 = EdgeArray[i].Node1.number;
             int v1 = EdgeArray[i].Node2.number;
             if (edge[v0][v1].x == 2.0) {EdgeArray[i].x = 2.0; } else EdgeArray[i].x = 0;
             i++;

         }
         ui->graphicsView->draw(0,0,0,1,0);
        ui->out->setText(s);
     });                                                             //寻找最近30个点
     connect(ui->clear,&QPushButton::clicked,this,[=](){
         ui->f_in->clear();
         ui->out->clear();int i = 0;
         while (i < Edgenumber)
         {
              EdgeArray[i].x = 0.0;
             i++;

         }
         ui->start->click();
     });
     connect(ui->d_start,&QPushButton::clicked,this,[=]()
     {
         int n1 =  ui->d_in1->text().toInt();
         int n2 =  ui->d_in2->text().toInt();
         Data d1 =shortpath(NodeArray[n1],NodeArray[n2],0,100);
          Data d2 =shortpath(NodeArray[n1],NodeArray[n2],1,100);
         n1 =int(d1.dst[n2]);
         n2 =int(d2.dst[n2]);
         QString s1 = QString::number(n1 / 10.0,10,1) + "  " + "(km）";
         QString s2 = QString::number(n2,10) + "  " + "(min)";
         ui->d1->setText(s1);
         ui->d2->setText(s2);
         //qDebug() <<"YY"<< endl;


     });                                                            //最短路径
     connect(ui->mind,&QPushButton::clicked,this,[=](){
         int n1 =  ui->d_in1->text().toInt();
         int n2 =  ui->d_in2->text().toInt();
         Data d1 =shortpath(NodeArray[n1],NodeArray[n2],0,100);

          ui->dout->setText(d1.path[n2]);
         getpath(d1);
         //d1.showdata();
         ui->graphicsView->draw(1,1,1,1,0);
     });                                                            //最短路径
     connect(ui->mint,&QPushButton::clicked,this,[=](){
         int n1 =  ui->d_in1->text().toInt();
         int n2 =  ui->d_in2->text().toInt();
         Data d1 =shortpath(NodeArray[n1],NodeArray[n2],1,100);
         ui->tout->setText(d1.path[n2]);
         getpath(d1);
         ui->graphicsView->draw(1,1,1,1,0);

     });                                                            //最短路径
     connect(ui->d_end,&QPushButton::clicked,this,[=](){
         ui->graphicsView->draw(0,0,0,0);
         ui->d_in1->clear();
          ui->d_in2->clear();
          ui->d1->clear();
           ui->d2->clear();
           ui->dout->clear();
           ui->tout->clear();
         for (int i = 0; i < 150 ; i++) EdgeArray[i].flag = 1;
     });                                                               //最短路径
}

MainWindow::~MainWindow()
{
    delete ui;
}


