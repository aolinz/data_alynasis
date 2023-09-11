#ifndef IP_H
#define IP_H

#include <QDialog>
#include <QHostInfo>
#include <QHostAddress>
#include <QDebug>
#include <QNetworkInterface>
namespace Ui {
class ip;
}

class ip : public QDialog
{
    Q_OBJECT

public:
    explicit ip(QWidget *parent = nullptr);
    ~ip();

private:
    Ui::ip *ui;
};

#endif // IP_H
