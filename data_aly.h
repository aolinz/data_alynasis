#ifndef DATA_ALY_H
#define DATA_ALY_H

#include <QAxObject>
#include <QMainWindow>
#include <QTableWidget>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QtNetwork>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLogValueAxis>
#include <QtCharts/QValueAxis>
#include <QAxObject>
#include <QFileDialog>
#include <QDebug>
#include <QSplineSeries>
#include <QTimer>
#include <QLineSeries>
#include <QValueAxis>
#include <QDateTime>
#include <QDateTimeAxis>
#include <QMenu>
#include <QAction>
#include <ip.h>
#include <QVector>
#include <QMessageBox>
#include <QtConcurrent/QtConcurrent>
#include "qcustomplot.h"
#include "imageviewer.h"
QT_CHARTS_USE_NAMESPACE
#pragma execution_character_set("utf-8")
namespace Ui {
class data_aly;
}
class data_aly : public QMainWindow
{
    Q_OBJECT

public:
    explicit data_aly(QWidget *parent = nullptr);
    ~data_aly();
    //void excel_read(QString &path,QTableWidget *table);
    //void Qvariant2listlistvariant(const QVariant &var,QList<QList<QVariant>> &ret);
    //跟据导入的excel文件进行画图，这个是widget3之中的
    void getExcelContent(QVector<QVector<QString>>& res);
    void getExcelContent_1(QVector<QVector<QString> > &map);
    void chart_init(int i);//表示传入的是第几条曲线
    void chart4_init(int i);
    void getData_single();
private slots:

    void on_actionshow_parameter_triggered();

    void on_actionwarning_message_triggered();

    void on_run_2_triggered();
    //用于udp接收数据的地方
    void Receive();

    void on_w1_change_clicked();

    void on_w1_close_clicked();

    void on_w2_change_clicked();

    void on_w2_close_clicked();

    void on_w3_change_clicked();

    void on_w3_close_clicked();

    void on_w4_change_clicked();

    void on_w4_close_clicked();

    void on_actionrun_triggered();

    void on_actionrun_2_triggered();

    void on_actionshuipingxianshi_triggered();

    //画曲线定时器的槽函数,表示画的是第几条线
    void Drawline(int i);
    //tablewidget数据转变的槽函数
    void slotTriggered();
    void on_parameter_customContextMenuRequested(const QPoint &pos);
    void w3_chartinit();
    void Drawline_W3();
    void Drawline_W4(int i);
    void Drawline_single();
    //第二个窗口的槽函数
    void realtimeDataSlot(int i);
    //第四个窗口的槽函数
    void realtimeDataSlot_four(int i);
    void on_savedata_triggered();

    void on_actionlat_lon_triggered();

    //尝试使用txt文件来读取数据
    void addData();
    //实现鼠标展示值
    void myMouseMoveEvent(QMouseEvent *event);
    void myMouseMoveEventw2(QMouseEvent *event);
    void on_actionclose_udp_triggered();

signals:
    //发送信号
    void sendData();
public slots:
    void Getmousepos(int x,int y,float z,QString s);
    void shuchu(QString x);
private:
    Ui::data_aly *ui;
    QString strData;
    //这部分是使用txt读取数据的一个存储方式
    QList<QString> list_table_txt;
    QUdpSocket *receiver;
    //这是垂直剖面展示的位置
    int intRows,intCols;
    QVector<QVector<QString>> exc_res;
    //这个是控制第一个窗口的大小
    int w1_flag_maxornomal = 0;
    int w2_flag_maxornomal = 0;
    int w3_flag_maxornomal = 0;
    int w4_flag_maxornomal = 0;
    //表的操作
    int nStartRow = 0,nStartCol = 0,nRowcount = 0;
    int nColCount = 0;
    //动态曲线的定时器
    QHash<int,QTimer *>  draw_timer;
    bool booldraw_timer = false;//打开状态
    //存储udp传过来的值
    QVector<QPointF> points;
    //将所有的点都存入qlist
    QHash<long,QVector<QPointF>> draw_points;
    int pointCount = 0;//记录点数
    QDateTime curDateTime = QDateTime::currentDateTime();
    //用于存储tablewidget的数据值
    QVector<QString> list_table;
    QTimer *table_timer = new QTimer();
    long count = 1;//告诉tablewidget这是第几个包
    int chart_count = 0;
    //第三个窗口水平剖面
    QTimer *w3_timer;
    //第四个窗口垂直剖面
    QHash<int,QSplineSeries*> w4_lineseries;
    QList<int> heightNum = {6,7,8,9,10,21,24,26,28};
    QVector<QPointF> point_single;
    long pointSingle = 0;
    QTimer *timer_single = new QTimer();
    long single_count = 0;
    long single_count1 = 0;
    //这里是者pointcount的大小
    int num = 60;
    QVector<int> point_w2;
    QVector<int> point_w4;
    //单独曲线是否重复读取
    bool flag = true;
    //现在开始做第二个窗口
    QCustomPlot* customPlot_second;
    QTimer *timer_w2 = new QTimer();
    //第四个窗口
    QCustomPlot* customPlot_four;
    QTimer *timer_w4 = new QTimer();
    //加入数据
    QByteArray recvMsg;
    //表示这是存入的第一个数组
    int txt_count = 0;
    bool copyFile(QString srcPath,QString dstPath);
    int count_pic = 1;
    int count_title = 0;
    //是否给文件夹里面增加一行
    int row_title = 0;
    //需要传给main程序的一些参数
    int pos_x = 0,pos_y = 0;
    double fac = 1.0;
    QString default_flag = "false";
    //用于读取txt文件
    QFuture<void> thread_data;
    //用于第三个窗口的gmt绘图的定时器
    QTimer *gmt = new QTimer();
};

#endif // DATA_H
