#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent)
{
}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked(event->pos());
}
