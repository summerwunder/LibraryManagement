#include "book.h"

Book::Book()
{

}

Book::Book(int isbn, QString name, QString author, QString publisher, QString addTime)
{
    this->isbn=isbn;
    this->name=name;
    this->author=author;
    this->publisher=publisher;
    this->addTime=addTime;
}
