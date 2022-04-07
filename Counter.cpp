#include "Counter.h"

Counter::Counter(QMutex *mutex, int *value)
{

    m_value = value;
    m_mutex = mutex;
}

void Counter::run()
{
    // We will wait until finished his job

    QMutexLocker locker(m_mutex);

    QThread::currentThread()->msleep(50);
    *m_value = *m_value +1;
    qInfo()<<*m_value<<QThread::currentThread();

}
