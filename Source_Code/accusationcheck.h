#ifndef ACCUSATIONCHECK_H
#define ACCUSATIONCHECK_H
#include "Character.h"
#include <QDialog>

namespace Ui {
class AccusationCheck;
}

class AccusationCheck : public QDialog
{
    Q_OBJECT

public:
    explicit AccusationCheck(QWidget *parent = nullptr);
    ~AccusationCheck();
    Character *selected;
    bool finished = false;

private slots:
    void on_NoButton_clicked();

    void on_YesButton_clicked();

private:
    Ui::AccusationCheck *ui;
};

#endif // ACCUSATIONCHECK_H
