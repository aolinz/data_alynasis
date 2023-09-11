#include "data_aly.h"
#include "ui_data_aly.h"
#include <QMetaMethod>
data_aly::data_aly(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::data_aly)
{
    ui->setupUi(this);
    connect(ui->w4_plt,SIGNAL(mouseDoubleClick(QMouseEvent *)),this,SLOT(myMouseMoveEvent(QMouseEvent *)));
    connect(ui->w2_plt,SIGNAL(mouseDoubleClick(QMouseEvent *)),this,SLOT(myMouseMoveEventw2(QMouseEvent *)));
    //处理来自子窗口的值
    ui->parameter->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->message->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //widget1
    ui->w1_close->setStyleSheet("border:none");
    ui->w1_lab->setStyleSheet("border:none");
    ui->w1_change->setStyleSheet("border:none");
    ui->w1_qml->setStyleSheet("border:none");
    //这里先不用考虑第一个窗口的事情
    //ui->w1_qml->setSource(QUrl::fromLocalFile("map.qml"));
    //widget_2
    for(int i = 0;i < 99;i++)
    {
        point_w2.append(0);
    }
    ui->w2_plt->setStyleSheet("border:none");
    ui->w2_close->setStyleSheet("border:none");
    ui->w2_label->setStyleSheet("border:none");
    ui->w2_change->setStyleSheet("border:none");
    customPlot_second = ui->w2_plt;
    ui->parameter->setContextMenuPolicy(Qt::CustomContextMenu);
    //widget3
    ui->w3_gmt->setStyleSheet("padding:0px;border:0px");
    ui->w3_lab->setStyleSheet("border:none");
    ui->w3_close->setStyleSheet("border:none");
    ui->w3_change->setStyleSheet("border:none");
    //widget4
    for(int i = 0;i < 99;i++)
    {
        point_w4.append(0);
    }
    customPlot_four = ui->w4_plt;
    ui->w4_lab->setStyleSheet("border:none");
    ui->w4_plt->setStyleSheet("border:none");
    ui->w4_close->setStyleSheet("border:none");
    ui->w4_change->setStyleSheet("border:none");
}

data_aly::~data_aly()
{
    qDebug() << "main stop";
    delete ui;
}

void data_aly::on_actionshow_parameter_triggered()
{
    count_title++;
    QString curpath = QDir::currentPath();
    QString dlgTitle = "file";
    QString fileter = "???????(*.xls *.xlsx);;xlsx???(*.xlsx);;???????(*.*)";
    QStringList fileList = QFileDialog::getOpenFileNames(this,dlgTitle,curpath,fileter);
    if(fileList.count() <1 )
    {
        return;
    }
    for(int i = 0;i<fileList.count();i++)
    {
        strData = fileList.at(i);
    }

    QAxObject excel("Excel.Application");

    excel.setProperty("Visible",false);

    QAxObject *workbooks = excel.querySubObject("WorkBooks");
    workbooks->dynamicCall("Open(const QString&)",strData);

    QAxObject *workbook = excel.querySubObject("ActiveWorkBook");

    QAxObject *worksheet = workbook->querySubObject("Worksheets(int)",3);

    QAxObject *range = worksheet->querySubObject("UsedRange");

    QAxObject* cols = worksheet->querySubObject("Columns");
    QString strVal = "";
    QStringList header;
    QString val_title;
    ui->parameter->setRowCount(0);
    ui->parameter->setColumnCount(0);
    int row = 60;

    int col = 6;
    for(int i =1 ;i <= row;i++)
    {

        ui->parameter->setRowCount(ui->parameter->rowCount()+1);
        for(int j =1 ; j <= col;j++)
        {
            if(i==1)
            {
                ui->parameter->setColumnCount(ui->parameter->columnCount()+1);
                if(j == 3)
                {
                    strVal = "val";
                    header << strVal;
                    continue;
                }
                range = worksheet->querySubObject("Cells(int,int)",i,j);
                strVal = range->dynamicCall("Value2()").toString();
                header<< strVal;
            }
            else{
                if(j == 3)
                {
                    ui->parameter->setItem(i-2,j-1,new QTableWidgetItem(""));
                    continue;
                }
                //ui->parameter->removeColumn(3);
                range = worksheet->querySubObject("Cells(int,int)",i,j);
                strVal = range->dynamicCall("Value2()").toString();
                ui->parameter->setItem(i-2,j-1,new QTableWidgetItem(strVal));
            }
        }
        if(i==1)
        {
//            qDebug() << header;
            ui->parameter->setHorizontalHeaderLabels(header);
            ui->parameter->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->parameter->verticalHeader()->setVisible(false);
        }
    }
    ui->parameter->removeColumn(3);

    if(list_table.size() != 0)
    {
        for(int i = 0;i< 59;i++)
        {
            ui->parameter->setItem(i,2,new QTableWidgetItem(list_table[i]));
        }
        //table_timer = new QTimer();
        //这里要快一些
        table_timer->start(0);//尽快展示，不然在最后会慢一些
        connect(table_timer,&QTimer::timeout,[=]()
        {
            slotTriggered();
        });
    }
}

void data_aly::on_actionwarning_message_triggered()
{
    QString curpath = QDir::currentPath();
    QString dlgTitle = "";
    QString fileter = "(*.xls *.xlsx);;xlsx(*.xlsx);;(*.*)";

    QStringList fileList = QFileDialog::getOpenFileNames(this,dlgTitle,curpath,fileter);
    if(fileList.count() <1 )
    {
        return;
    }
    for(int i = 0;i<fileList.count();i++)
    {
        strData = fileList.at(i);
    }

    QAxObject excel("Excel.Application");

    excel.setProperty("Visible",false);

    QAxObject *workbooks = excel.querySubObject("WorkBooks");
    workbooks->dynamicCall("Open(const QString&)",strData);

    QAxObject *workbook = excel.querySubObject("ActiveWorkBook");
    QAxObject *worksheet = workbook->querySubObject("Worksheets(int)",1);

    QAxObject *range;
    QString strVal = "hull";
    QStringList header;

    ui->message->setRowCount(0);
    ui->message->setColumnCount(0);
    int row = 100;
    int col = 4;
    for(int i =1 ;i <= row;i++)
    {
        ui->message->setRowCount(ui->message->rowCount()+1);
        for(int j =1 ; j<= col;j++)
        {
            if(i==1)
            {
                ui->message->setColumnCount(ui->message->columnCount()+1);
                range = worksheet->querySubObject("Cells(int,int)",i,j);
                strVal = range->dynamicCall("Value2()").toString();
                header<<strVal;
            }
            else{
                range = worksheet->querySubObject("Cells(int,int)",i,j);
                strVal = range->dynamicCall("Value2()").toString();
                ui->message->setItem(i-2,j-1,new QTableWidgetItem(strVal));
            }
        }
        if(i==1)
        {
            ui->message->setHorizontalHeaderLabels(header);
        }
    }
}
void data_aly::on_run_2_triggered()
{
    qDebug() << "the graph start runnning!";
    emit sendData();
}

void data_aly::Receive()
{
    QFile lat_file("./road_data_aly.txt");
    if(!lat_file.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        qDebug() << "start error";
        return;
    }
    QTextStream out_lat(&lat_file);
    //这是全部的数据
    QFile file(QString("./data_aly.txt"));
    if(!file.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        qDebug() << "start error";
        return;
    }
    QTextStream out(&file);
    if(row_title == 0)
        out << "VNAV_Dist_To_End	VNAV_is_Active	VNAV_Flight_Phase	Autopilot_Mode	Vnav_Submodes	Vert_Mode_Req	Baro_Alt	MCP_Alt	Crz_Alt	Ref_Holding_Alt	Ref_Alt	Alt_Slave_Bit	Next_Alt_Constraint	Ref_CAS	Ref_Mach	Ref_Spd_Mode	VS	VS_Cmd	Vert_Dev	Pitch_Command	Gnd_Spd	Dyn_TOD_Alt	Dyn_TOD_Dist	Prof1_Dist	Prof1_Alt	Prof2_Dist	Prof2_Alt	Prof3_Dist	Prof3_Alt	Lon	Lat	Boc_Flashing_Indicator	Boc_Steady_Indicator	Check_Alt_Selector_Indicator	Check_Fplan_Alt_Indicator	Check_Nav_Source_Indicator	Check_Speed_Indicator	Decelerate_Indicator	Max_Vpa_Exceeded_Indicator	No_Vert_Path_Cond_Indicator	No_Vert_Path_Due_To_Ctd_Exceed_Indicator	No_Vert_Path_Due_To_Pilot_Cmd_Indicator	No_Vert_Path_Due_To_Tae_Exceed_Indicator	No_Vert_Path_Due_To_Vectors_Indicator	No_Vert_Path_On_This_Leg_Indicator	Vnav_Sensor_data_aly_Invalid_Indicator	Vert_Path_Warning_Ctd_Exceed_Indicator	Vert_Path_Warning_Tae_Exceed_Indicator	Unable_Cruise_Alt_Indicator	Unable_Cruise_Speed_Indicator	Unable_Fplan_Alt_Indicator	Unable_Fplan_Sequence_Indicator	Unable_Next_Alt_Indicator	Tod_Flashing_Indicator	Tod_Steady_Indicator	Advisory_Vnav_State_Indicator	Advisory_Vnav_Avail_Indicator	Path_Below_Aircraft_Indicator"<<endl;
    row_title = 1;
    while(receiver->hasPendingDatagrams())
    {
        recvMsg.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(recvMsg.data(),recvMsg.size());
        QVariantList list;
//        qDebug() << recvMsg.size();
        long j=0;
        QVector<int> int_count = {0,6,7,8,9,10,12,13,14};
        for(int i = 16;i<=30;i++)
        {
            int_count.push_back(i);
        }
        QVector<int> int_single;
        for(int i = 59;i<=98;i++)
        {
            int_count.push_back(i);
            int_single.push_back(i);
        }
        QVector<int> lat_count = {29,30};
        int k =0;
        int index = 0;
        for( long i = 0 ; i < recvMsg.size(); i+=4)
        {
            int var;
            float var1;
            if(int_count.contains(j%99))
            {
                memcpy(&var1,recvMsg.constData()+i,4);
                QString str = QString::number(var1,'f',2);
                if(int_single.contains(j % 99) /*&& pointSingle == 0*/)
                {
                    point_single.append(QPointF(index++,var1));
                }
                if(j%99 == 29)
                {
                    out_lat << var1 << "\t";
                }
                if(j % 99 == 30)
                    out_lat << var1 << endl;
                out << var1 << "\t";
                if(!int_single.contains(j % 99))
                {
                    list_table.append(str);
                }
                list.append(var1);
//                qDebug() << " var1 = " << var1;
                if(j % 99 == 0)
                {
                    draw_points[j%99].append(QPointF(k++,var1));
                }
                else{
                    draw_points[j%99].append(QPointF(k++,var1));
                }
            }
            else{
                memcpy(&var,recvMsg.constData()+i,4);
                QString str = QString::number(var);
                out << var << "\t";
                list_table.append(str);
                if(j % 99 == 0)
                {
                    draw_points[j%99].append(QPointF(k++,-var));
                }
                else{
                    draw_points[j%99].append(QPointF(k++,var));
                }
                list.append(var);
            }
            j++;
            if(j % 99 == 0)
                out << endl;
        }
    }
}

void data_aly::getExcelContent(QVector<QVector<QString> > &map)
{

    QAxObject *excel  = new QAxObject(this);
    excel->setControl("Excel.Application");
    excel->setProperty("Visible",false);
    excel->setProperty("DisplayAlerts",true);
    QAxObject *workbooks = excel->querySubObject("WorkBooks");
    QString str = QFileDialog::getOpenFileName(this,"????",
                                               QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                               "Excel ???(*.xls *.xlsx)");

    workbooks->dynamicCall("Open(const QString&)",str);
    QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
    QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)",1);
    QAxObject *usedRange = worksheet->querySubObject("UsedRange");
    QVariant var = usedRange->dynamicCall("Value");
    QList<QList<QVariant>> excel_list;
    QVariantList varRows = var.toList();
    if(varRows.isEmpty()) return;
    const int row_count = varRows.size();
    QVariantList rowdata_aly;
    for(int i = 1;i <= row_count;i++)
    {
        rowdata_aly = varRows[i].toList();
        excel_list.push_back(rowdata_aly);
    }

    for(int i =0 ;i < row_count;i++)
    {
        QList<QVariant> curList = excel_list.at(i);
        int curRowCount = curList.size();
        for(int j = 0;j<curRowCount;j++)
        {
            qDebug() << curList.at(j).toString();
        }
    }
    workbook->dynamicCall("Close(Boolean)",false);
    excel->dynamicCall("Quit(void)");
}

void data_aly::getExcelContent_1(QVector<QVector<QString> > &map)
{

    QAxObject *excel = NULL;
    QAxObject *workbooks = NULL;
    QAxObject *workbook = NULL;
    QString filepath = QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",QStringLiteral("Excel file(*.xls *.xlsx)"));
    if(filepath.isEmpty()) return;
    CoInitializeEx(NULL,COINIT_MULTITHREADED);
    excel = new QAxObject("Excel.Application");
    if(!excel){
        qDebug() << "EXCEL ";
    }
    workbooks = excel->querySubObject("Workbooks");
    if(0 == workbooks)
    {
        qDebug() << "kong";
        return;
    }
    workbook = workbooks->querySubObject("open (const QString &)",filepath);
    if(0 == workbook)
    {
        qDebug() << "workbook00000";
        return;
    }
    QAxObject *worksheet = workbook->querySubObject("Worksheets(int)",1);
    QAxObject *usedrange = worksheet->querySubObject("UsedRange");
    QAxObject* rows = usedrange->querySubObject("Rows");
    QAxObject* colums = usedrange->querySubObject("Columns");
    intRows =rows->property("Count").toInt();
    intCols = colums->property("Count").toInt();
    QVariant var = usedrange->dynamicCall("Value");
    foreach(QVariant varRow,var.toList())
    {
        QVector<QString> vecdata_alyRow;
        foreach(QVariant var,varRow.toList())
        {
            vecdata_alyRow.push_back(var.toString());
        }
        map.push_back(vecdata_alyRow);
    }
    //这里则是关闭了excel
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");
    if(excel)
    {
        delete excel;
        excel = NULL;
    }
}

void data_aly::chart_init(int i)
{
    //添加曲线
    QPen pen;
    for(int i = 0;i < 60;i++)
    {
        customPlot_second->addGraph();
        pen.setColor(QColor(qSin(i*0.3)*100+100,qSin(i*0.6+0.7)*100+100,qSin(i*0.4+0.6)*100+100));
        customPlot_second->graph(i)->setPen(pen);
    }
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    customPlot_second->xAxis->setTicker(timeTicker);
    //四边安上坐标轴
    //customPlot_second->axisRect()->setupFullAxesBox();
    //设置y轴范围
    customPlot_second->yAxis->setRange(-1000, 1000);
    // 使上下轴、左右轴范围同步
    connect(customPlot_second->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot_second->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot_second->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot_second->yAxis2, SLOT(setRange(QCPRange)));
    //定时器连接槽函数realtimedata_alySlot
}

void data_aly::chart4_init(int i)
{
    //添加曲线
    QPen pen_w4;
    for(int i = 0;i <= 60;i++)
    {
        customPlot_four->addGraph();
        pen_w4.setColor(QColor(qSin(i*0.3)*100+100,qSin(i*0.6+0.7)*100+100,qSin(i*0.4+0.6)*100+100));
        customPlot_four->graph(i)->setPen(pen_w4);
    }
    //设置x轴范围
    customPlot_four->xAxis->setRange(-100,0);
    //设置y轴范围
    customPlot_four->yAxis->setRange(0, 30000);
    // 使上下轴、左右轴范围同步
    connect(customPlot_four->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot_four->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot_four->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot_four->yAxis2, SLOT(setRange(QCPRange)));
    //定时器连接槽函数realtimedata_alySlot
}

void data_aly::getData_single()
{
    QString line;
    QStringList list,column;
    QFile locationfile("C:/Users/du_chao/Desktop/2023/3-30/ui/1.txt");
    if(!locationfile.open(QIODevice::ReadOnly))
    {
        qDebug() << "不能打开文件";
    }
    QTextStream in(&locationfile);
    while(!in.atEnd())
    {
        line = in.readLine();
        if(line.startsWith("Distance")) continue;
        column = line.split("\t",QString::SkipEmptyParts);
        point_single.append(QPointF(-column.at(0).toDouble(),column.at(1).toDouble()));
    }
}

void data_aly::on_w1_change_clicked()
{
    ui->widget_map->raise();
    if(w1_flag_maxornomal == 0)
    {
        int width = ui->widget_map->size().width();
        int height = ui->widget_map->size().height();
        ui->widget_map->resize(2*width,2*height);
        w1_flag_maxornomal = 1;
    }
    else if(w1_flag_maxornomal == 1)
    {
        int width = ui->widget_map->size().width();
        int height = ui->widget_map->size().height();
        ui->widget_map->resize(width/2,height/2);
        w1_flag_maxornomal = 0;
    }
}

void data_aly::on_w1_close_clicked()
{
    ui->widget_map->close();
}

void data_aly::on_w2_change_clicked()
{

    ui->widget_2->raise();
    if(w2_flag_maxornomal == 0)
    {
        ui->widget_2->move(ui->widget_2->geometry().x() - ui->widget_2->width(),ui->widget_2->geometry().y());
        int width = ui->widget_2->size().width();
        int height = ui->widget_2->size().height();
        ui->widget_2->resize(2*width,2*height);
        w2_flag_maxornomal = 1;
    }
    else if(w2_flag_maxornomal == 1)
    {
        int width = ui->widget_2->size().width();
        int height = ui->widget_2->size().height();
        ui->widget_2->resize(width/2,height/2);
        ui->widget_2->move(ui->widget_2->geometry().x()+ ui->widget_2->width(),ui->widget_2->geometry().y());
        w2_flag_maxornomal = 0;
    }
}

void data_aly::on_w2_close_clicked()
{
    ui->widget_2->close();
}

void data_aly::on_w3_change_clicked()
{

    ui->widget_3->raise();
    if(w3_flag_maxornomal == 0)
    {

        ui->widget_3->move(ui->widget_3->geometry().x() ,ui->widget_3->geometry().y() - ui->widget_3->height());
        int width = ui->widget_3->size().width();
        int height = ui->widget_3->size().height();
        ui->widget_3->resize(2*width,2*height);
        w3_flag_maxornomal = 1;
    }
    else if(w3_flag_maxornomal == 1)
    {
        int width = ui->widget_3->size().width();
        int height = ui->widget_3->size().height();
        ui->widget_3->resize(width/2,height/2);
        ui->widget_3->move(ui->widget_3->geometry().x(),ui->widget_3->geometry().y() + ui->widget_3->height());
        w3_flag_maxornomal = 0;
    }
}

void data_aly::on_w3_close_clicked()
{
    ui->widget_3->close();
}

void data_aly::on_w4_change_clicked()
{

    ui->widget_4->raise();
    if(w4_flag_maxornomal == 0)
    {

        ui->widget_4->move(ui->widget_4->geometry().x() - ui->widget_4->width() ,ui->widget_4->geometry().y() - ui->widget_4->height());
        int width = ui->widget_4->size().width();
        int height = ui->widget_4->size().height();
        ui->widget_4->resize(2*width,2*height);
        w4_flag_maxornomal = 1;
    }
    else if(w4_flag_maxornomal == 1)
    {
        int width = ui->widget_4->size().width();
        int height = ui->widget_4->size().height();
        ui->widget_4->resize(width/2,height/2);
        ui->widget_4->move(ui->widget_4->geometry().x()  + ui->widget_4->width(),ui->widget_4->geometry().y() + ui->widget_4->height());
        w4_flag_maxornomal = 0;
    }
}

void data_aly::on_w4_close_clicked()
{
    ui->widget_4->close();
}

void data_aly::on_actionrun_triggered()
{
//    getExcelContent_1(exc_res);
//    m_chart = new QChart();
//    for(int j = 1;j < intCols;++j)
//    {
//        QSplineSeries *splineseries = new QSplineSeries();
//        for(int i = 1 ; i<= intRows;++i)
//        {
//            splineseries->append(i,exc_res[i-1][j].toDouble());
//            qDebug() << "i = " << i << ", exc_res[i][j] = " << exc_res[i-1][j];
//        }
//        m_chart->addSeries(splineseries);
//    }
//    m_chart->setTheme(QChart::ChartThemeLight);
//    m_chart->legend()->hide();
//    m_chart->createDefaultAxes();
//    ui->w3_chart->setChart(m_chart);
//    ui->w3_chart->setRenderHint(QPainter::Antialiasing);
}

void data_aly::on_actionrun_2_triggered()
{
//    getExcelContent_1(exc_res);
//    m_chart = new QChart();
//    for(int j = 1;j < intCols;++j)
//    {
//        QSplineSeries *splineseries = new QSplineSeries();
//        for(int i = 1 ; i<= intRows;++i)
//        {
//            splineseries->append(i,exc_res[i-1][j].toDouble());
//            qDebug() << "i = " << i << ", exc_res[i][j] = " << exc_res[i-1][j];
//        }
//        m_chart->addSeries(splineseries);
//    }
//    m_chart->setTheme(QChart::ChartThemeLight);
//    m_chart->legend()->hide();
//    m_chart->setTitle("???");
//    m_chart->createDefaultAxes();
//    ui->w4_chart->setChart(m_chart);
//    ui->w4_chart->setRenderHint(QPainter::Antialiasing);
}


void data_aly::on_actionshuipingxianshi_triggered()
{
    receiver = new QUdpSocket(this);
    receiver->bind(QHostAddress::AnyIPv4,38500,QUdpSocket::ShareAddress);
    connect(receiver,SIGNAL(readyRead()),this,SLOT(Receive()));
    ip *p1 = new ip(this);
    p1->show();
}


void data_aly::Drawline(int i)
{

}

void data_aly::slotTriggered()
{
    //应该是这里动的太快导致定时器停止了
    if(59 * (count) < list_table.size() )
    {
//        qDebug() << "count*59" << count*59;
//        qDebug() << "list_table.size()-" << list_table.size();
        for(int i = 0;i < 59;i++)
        {
            ui->parameter->removeCellWidget(i,2);
        }
        for(int i = 0;i < 59 ;i++ )
        {
            ui->parameter->setItem(i,2,new QTableWidgetItem(list_table[i+count*59]));
        }
        count++;
    }
}

void data_aly::on_parameter_customContextMenuRequested(const QPoint &pos)
{
    QMenu menu;
    QAction *addSeries = menu.addAction(tr("add"));
    menu.addSeparator();
    QAction *deleteSeries = menu.addAction(tr("delete"));
    menu.addSeparator();
    connect(addSeries,&QAction::triggered,[=]()
    {
        QModelIndex index = ui->parameter->indexAt(pos);
        int row = index.row();
        qDebug() << "row--" << row;

        chart4_init(row);
        //timer_w4 = new QTimer();
        timer_w4->start(0);
        connect(timer_w4,&QTimer::timeout,[=]()
        {
            realtimeDataSlot_four(row);
        });
        //这里绘出曲线
        //timer_single = new QTimer();
        timer_single->start(50);
        //在这里将数据读入(从txt读取数据)
        //getdata_aly_single();
        //现在要采取不同的方式来读取数据，在这里进行修改一下
        connect(timer_single,&QTimer::timeout,[=]()
        {
            Drawline_single();
        });
//        //这里进行清空point数组，并且告诉udp我需要重新接收point的数据了
//        pointSingle = 0;
//        point_single.clear();
        chart_init(row);
        //timer_w2 = new QTimer();
        timer_w2->start(0); // 间隔时间 0ms表示尽可能快的触发
        connect(timer_w2,&QTimer::timeout,[=]()
        {
            realtimeDataSlot(row);
        });

    });
    connect(deleteSeries,&QAction::triggered,[=]()
    {
        QModelIndex index = ui->parameter->indexAt(pos);
        int row = index.row();
        if(row == 29 || row == 30)
        {

        }
        else if(heightNum.contains(row))
        {
            customPlot_four->removeGraph(row);
        }
        else{
            customPlot_second->removeGraph(row);
        }
    });
    menu.exec(QCursor::pos());
}

void data_aly::w3_chartinit()
{

}

void data_aly::Drawline_W3()
{

}

void data_aly::Drawline_W4(int i)
{

}

void data_aly::Drawline_single()
{
    QPen pen;
    pen.setColor(Qt::black);
//    for(int i = 0;i <point_single.size();i++)
//        qDebug() << point_single[i];
    if(single_count < point_single.size())
    {
        customPlot_four->graph(60)->setPen(pen);
        //这里的逻辑还需要在修改一下
        customPlot_four->graph(60)->addData(-point_single[single_count++].ry(),point_single[single_count].ry());
        single_count++;
    }

    customPlot_four->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                                     QCP::iSelectLegend | QCP::iSelectPlottables);
    //绘图
    customPlot_four->replot();
}

void data_aly::realtimeDataSlot(int i)
{
    //这里进行第二个窗口的直线书写
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0; // 开始到现在的时间，单位秒
    static double lastPointKey = 0;
    if(point_w2[i] <= draw_points[i].size()-4)
    {
        if (key-lastPointKey > 0.5) // 大约200ms添加一次数据
        {
            // 添加数据到graph
            if(i == 0)
            {
                customPlot_second->graph(i)->addData(key,-draw_points[i][point_w2[i]++].ry());
                draw_points[i].erase(draw_points[i].begin() + point_w2[i]);
            }
            else
            {
                customPlot_second->graph(i)->addData(key,draw_points[i][point_w2[i]++].ry());
                draw_points[i].erase(draw_points[i].begin() + point_w2[i]);
            }
            //记录当前时刻
            lastPointKey = key;
        }
    }
    // 曲线能动起来的关键在这里，设定x轴范围为最近8个时刻
    customPlot_second->xAxis->setRange(key, 8, Qt::AlignRight);
    //customPlot->yAxis->rescale(true);//自动缩放
    customPlot_second->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                                      QCP::iSelectLegend | QCP::iSelectPlottables);
    //绘图
    customPlot_second->replot();
}

void data_aly::realtimeDataSlot_four(int i)
{
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0; // 开始到现在的时间，单位秒
    static double lastPointKey = 0;
    if(point_w4[i]  + 8 < draw_points[i].size())
    {
        if (key-lastPointKey > 0.1) // 大约200ms添加一次数据
        {
            //这里进行第四个图的绘图
            customPlot_four->graph(i)->addData(-draw_points[0][point_w4[i]++].ry(),draw_points[i][point_w4[i]].ry());
            draw_points[i].erase(draw_points[i].begin() + point_w4[i]);
            point_w4[i] += 4;
            //记录当前时刻
            lastPointKey = key;
        }
    }
    customPlot_four->xAxis->grid()->setSubGridVisible(false);
    customPlot_four->yAxis->grid()->setSubGridVisible(false);
    customPlot_four->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                                      QCP::iSelectLegend | QCP::iSelectPlottables);
    //绘图
    customPlot_four->replot();
}


void data_aly::on_savedata_triggered()
{
    //这里的保存数据,就是将数据保存到自己想要的地方
    QString path = QFileDialog::getOpenFileName(this,"choose file","./data_aly.txt","(*.txt)");
    bool ok = copyFile("./data_aly.txt",path);
    //此时将data_aly.txt清空
    if(ok)
    {
        QFile file("./data_aly.txt");
        file.open(QFile::WriteOnly|QFile::Truncate);
        file.close();
    }
}

bool data_aly::copyFile(QString srcPath, QString dstPath)
{
    if(srcPath == dstPath)
    {
        qDebug() << "the same path";
        return false;
    }
    if(!QFile::exists(srcPath))
    {
        qDebug() << "src not exist";
        return false;
    }
    if(QFile::exists(dstPath))
    {
        QFile::remove(dstPath);
    }
    if(!QFile::copy(srcPath,dstPath))
    {
        qDebug() << "error";
        return false;
    }
    return true;
}


void data_aly::on_actionlat_lon_triggered()
{
    ImageViewer *img = ui->w3_gmt;
    //connect(img,SIGNAL(signalSend(int,int,float,QString)),this,SLOT(Getmousepos(int,int,float,QString)));
//    //在这里将执行main函数独立执行在另一个线程之中,尝试是否会在程序退出的是否会将此线程收回，这个线程是在系统的线程池中调用的
//    future = QtConcurrent::run([=]()
//    {
//        QString cmd = "./main.exe";
//        program.start(cmd);
//    });
    QProcess *program = new QProcess(this);//主程序
    QString cmd = "./main.exe";
    program->start(cmd);
    gmt->start(1000);
    connect(gmt,&QTimer::timeout,[=]()
    {
        qDebug() << program->state();
        //判断程序是否中止，如果已经中止，则重新运行这个程序
        if(program->state() == 0)
        {
            program->start(cmd);
        }
        //QString path = QString("./%1.png").arg(count_pic);
        QString path = QString("./001.png");
        QPixmap pic;
        bool ret = pic.load(path);
        if(ret &&  !pic.isNull())
        {
//            qDebug() << pic;
            ui->w3_gmt->setPixmap(pic);
        }
        else
        {
            qDebug() << "read error pic";
        }
    });
}

void data_aly::addData()
{
    thread_data = QtConcurrent::run([=]()
    {
        QFile file("./data_aly.txtx");
        QTextStream outdata_aly(&file);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "error";
            return;
        }
        //用来判断是否是59-98之间的数值
        QVector<int> judge_single;
        for(int i = 59;i <= 98;i++)
            judge_single.push_back(i);
        int linecount = 0;//从第一行开始读取
        while(!outdata_aly.atEnd())
        {
            if(linecount == 0)
            {
                QString line1 = outdata_aly.readLine();
            }
            QString line = outdata_aly.readLine();
            QStringList line_data_aly = line.split("\t");
            line_data_aly.removeLast();//这里把最后一个空字符串给去除
            //这个将数据存入drawpoints的操作放入一个线程之中

            for(int i = 0;i < line_data_aly.size();i++)
            {
                if(!judge_single.contains(i))
                    list_table_txt.append(line_data_aly[i]);
            }
            //qDebug() << line_data_aly;
            linecount++;
        }
    });
}

void data_aly::myMouseMoveEvent(QMouseEvent *event)
{
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();
    float x_val = ui->w4_plt->xAxis->pixelToCoord(x_pos);
    float y_val = ui->w4_plt->yAxis->pixelToCoord(y_pos);
//    float w2_xval = ui->w2_plt->xAxis->pixelToCoord(x_pos);
//    float w2_yval = ui->w2_plt->xAxis->pixelToCoord(y_pos);
//    qDebug() << "x- " << x_val << "y --" << y_val;
    QString  tip;
    tip += QString::number(x_val);
    tip += ",";
    tip += QString::number(y_val);
    QString st = "<b style= \"background-color:white;font: 12px;color:red;\">%1</b>";
//    QString  tip1;
//    tip1 += QString::number(w2_xval);
//    tip1 += ",";
//    tip1 += QString::number(w2_yval);
    QToolTip::showText(cursor().pos(),st.arg(tip),ui->w4_plt);
    //QToolTip::showText(cursor().pos(),st.arg(tip1),ui->w2_plt);
}

void data_aly::myMouseMoveEventw2(QMouseEvent *event)
{
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();
//    float x_val = ui->w4_plt->xAxis->pixelToCoord(x_pos);
//    float y_val = ui->w4_plt->yAxis->pixelToCoord(y_pos);
    float w2_xval = ui->w2_plt->xAxis->pixelToCoord(x_pos);
    float w2_yval = ui->w2_plt->xAxis->pixelToCoord(y_pos);
//    qDebug() << "x- " << x_val << "y --" << y_val;
//    QString  tip;
//    tip += QString::number(x_val);
//    tip += ",";
//    tip += QString::number(y_val);
    QString st = "<b style= \"background-color:white;font: 12px;color:red;\">%1</b>";
    QString  tip1;
    tip1 += QString::number(w2_xval);
    tip1 += ",";
    tip1 += QString::number(w2_yval);
    //QToolTip::showText(cursor().pos(),st.arg(tip),ui->w4_plt);
    QToolTip::showText(cursor().pos(),st.arg(tip1),ui->w2_plt);
}

void data_aly::Getmousepos(int x,int y,float z,QString s)
{
    //这里数据保存起来
//    QFile file("./flag.txt");
//    QTextStream outdata_aly(&file);
//    if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate))
//        return;
    qDebug() << x << "\t" << y << "\t" << z << "\t" << s;
}

void data_aly::shuchu(QString x)
{
    qDebug() << x;
}

void data_aly::on_actionclose_udp_triggered()
{
    //在这里将udp关闭,同时将所有在使用的定时器进行关闭
    //receiver->close();
    //关闭socket并让它关闭
    receiver->abort();
    if(table_timer->isActive())
        table_timer->stop();
    if(timer_w2->isActive())
        timer_w2->stop();
    if(timer_single->isActive())
        timer_single->stop();
    if(timer_w4->isActive())
        timer_w4->stop();
    if(gmt->isActive())
        gmt->stop();
}
