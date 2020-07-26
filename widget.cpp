#include "widget.h"
#include <QLabel>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    orderPresentation=new QLabel(this);
    QDateEdit *dateSold=new QDateEdit(QDate::currentDate(),this);
    dateSold->setCalendarPopup(true);
    dateSold->setDisplayFormat("yyyy-MM-dd");

    QPushButton *buttom_P= new QPushButton("P");


    QVBoxLayout * mainLayout=new QVBoxLayout(this);
    this->setLayout(mainLayout);
    mainLayout->addWidget(orderPresentation);
    mainLayout->addWidget(dateSold);
    mainLayout->addWidget(buttom_P);

    Counter *w=new Counter();
    connect(buttom_P, SIGNAL(clicked()), w, SLOT(updateValue()));
    connect(w, SIGNAL(valueChanged(int )), this, SLOT(updateLabel(int)));
}

Widget::~Widget()
{
}

void Widget::updateLabel(int x)
{
    orderPresentation->setText(QString::number(x));
}


void Counter::updateValue()
{
    ++this->m_value;
    emit  emit valueChanged(this->value());
}
