#include "accusationcheck.h"
#include "ui_accusationcheck.h"

AccusationCheck::AccusationCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccusationCheck)
{
    ui->setupUi(this);
}

AccusationCheck::~AccusationCheck()
{
    delete ui;
}

void AccusationCheck::on_NoButton_clicked()
{
    if(!finished)
        AccusationCheck::close();
    else
        exit(0);
}

void AccusationCheck::on_YesButton_clicked()
{
    if (!finished){
        if (selected->shortDescription() == "The Butler")
            ui->label->setText("YOU WIN!...\nThat was kind of underwhelming and easy but this isn't a game yet.\nThis is a project");
        else
            ui->label->setText("You lose...god you suck");
    finished = true;
    }
    else
        exit(0);
}
