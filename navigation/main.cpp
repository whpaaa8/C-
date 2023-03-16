#include "mainwindow.h"
#include<QVector>
#include<random>
#include "Node_Edge.h"
#include<algorithm>

#define nmax 110
#define inf 999999999
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
