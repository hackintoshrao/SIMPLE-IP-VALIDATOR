#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegExp exp("([0-9]{1,3}[.]){3}[0-9]{1,3}");//A regular expression for validating IP
    ui->lineEdit->setValidator(new QRegExpValidator(exp,this));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(close()));

}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_lineEdit_textChanged()
{
    ui->pushButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
