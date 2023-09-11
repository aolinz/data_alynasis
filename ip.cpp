#include "ip.h"
#include "ui_ip.h"

ip::ip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ip)
{
    ui->setupUi(this);
    QString ipAddress;
    QList<QHostAddress> ipList;
    ipList = QNetworkInterface::allAddresses();
    for (int i = 0; i<ipList.size();i++) {
        if(ipList.at(i) != QHostAddress::LocalHost && ipList.at(i).toIPv4Address())
        {
            ipAddress = ipList.at(i).toString();
            qDebug() << ipAddress;
        }
    }
    ui->ip_label->setText(ipAddress);
    this->resize(200,100);
}

ip::~ip()
{
    delete ui;
}
