#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QObject>
#include <QLabel>
class Counter : public QObject
{
   Q_OBJECT
public:
   Counter() { m_value = 0; }
   int value() const { return m_value; }
public slots:
   void updateValue();
signals:
   void valueChanged(int newValue);
private:
   int m_value;
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
     QLabel *orderPresentation;

public slots:
    void updateLabel(int x);
};






#endif // WIDGET_H
