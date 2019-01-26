#ifndef MLABELWAVE_H
#define MLABELWAVE_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <math.h>
#include <QDebug>
#include <QMouseEvent>
#define WIDTH 200
#define HEIGHT 128
class MyWaveLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyWaveLabel(QWidget *parent = 0);
    
signals:
    void clickTop();
    void clickBom();
public slots:
    void updateSet(bool set);
    void updateValid(bool valid);
    void updateText(QString text);
    void updateWave(QByteArray wave);
    bool isChecked();
    QByteArray wave();
private slots:
    void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *ev);
private:
    bool isSet;
    bool isValid;
    QString item;
    QList<int > px;
    QByteArray waveByte;
    
};

#endif // MWAVELABEL_H
