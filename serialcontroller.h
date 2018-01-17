#ifndef SERIALCONTROLLER_H
#define SERIALCONTROLLER_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>

class SerialController : public QObject
{
    Q_OBJECT
public:
    explicit SerialController(QObject *parent = nullptr);

signals:
    void openSuccess(); //串口打开成功
    void openFailed();  //串口打开失败
    void closeSuccess();    //串口关闭成功
    void writeSuccess(int len); //串口发送成功 len为成功发送的字节
    void writeFailed(); //串口发送失败

public slots:
    void openSerial(QString name);
    void closeSerial();
    void getBaudrate(QString baudrate); //改变波特率
    void getStopbits(QString stopbits); //改变停止位
    void getDatabits(QString databits); //改变数据为
    void getParity(QString parity);     //改变校验位
    void writeData(QString content);     //发送数据

private:
    QSerialPort *serial;

};

#endif // SERIALCONTROLLER_H