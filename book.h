#ifndef BOOK_H
#define BOOK_H

#include <QString>
class Book
{
public:
    Book();
    Book(int isbn,QString name,QString author,QString publisher,QString addTime);
private:
    int isbn;
    QString name;
    QString author;
    QString publisher;
    QString addTime;
};

#endif // BOOK_H
