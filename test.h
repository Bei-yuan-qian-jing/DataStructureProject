#ifndef TEST_H
#define TEST_H

#include <QObject>

class TEST : public QObject
{
    Q_OBJECT
public:
    explicit TEST(QObject *parent = nullptr);

signals:

};

#endif // TEST_H
