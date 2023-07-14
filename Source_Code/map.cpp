#include "map.h"
#include "ui_map.h"
#include <QPixmap>

Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    QPixmap pix("://Pictures/Map.png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

Map::~Map()
{
    delete ui;
}


void Map::on_CloseButton_clicked()
{
    Map::close();
}
