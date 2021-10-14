#include "keyboardfilter.h"

KeyboardFilter::KeyboardFilter(QObject *parent) : QObject(parent)
{

}
//The way with event fillter
bool KeyboardFilter::eventFilter(QObject *watched, QEvent *event)
{
    //          left 0x01000012 - 0
    //        //right 0x01000014 - 1
    //        //up 0x01000013 - 2
    //        //down 0x01000015 - 3
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        //qDebug() << "Filter: Key pressed " << keyEvent->key();
        if(keyEvent->key() == 0x01000012)
        {
            emit nextTurn(0);
            return true;
        }else if(keyEvent->key() == 0x01000014)
        {
            emit nextTurn(1);
            return true;
        }
        else if(keyEvent->key() == 0x01000013)
        {
            emit nextTurn(2);
            return true;
        }else if(keyEvent->key() == 0x01000015)
        {
            emit nextTurn(3);
            return true;
        }
    }
    return QObject::eventFilter(watched, event);
}
