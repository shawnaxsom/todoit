/* The Todo.txt master class.
  It handles the todo.txt and parses out information from it as well as writing it back.
  Also done.txt is handled here if needed
  */

#ifndef TODOTXT_H
#define TODOTXT_H

#define TODOFILE "todo.txt"
#define DONEFILE "done.txt"
#define DELETEDFILE "deleted.txt"

#include <vector>
#include <set>
#include <QString>

using namespace std;

class todotxt
{
protected:
    QString filedirectory;
    vector<QString> todo;
    vector<QString> done;
    set<QString> active_projects;
    set<QString> active_contexts;
    static bool lessThan(QString &,QString &);
    bool threshold_hide(QString &);

public:
    todotxt();
    void setdirectory(QString &dir);
    void parse(); // Parses the files in the directory
    void getActive(QString& filter,vector<QString> &output);
    void getAll(QString& filter,vector<QString> &output);
    Qt::CheckState getState(QString& row);
    static QString prettyPrint(QString& row);
    void update(QString& row,bool checked,QString& newrow);
    void write(QString& filename,vector<QString>&  content);
    void slurp(QString& filename,vector<QString>&  content);
    void remove(QString line);
    void archive();
    void refresh();
    bool isInactive(QString& text);
    QString getToday();
    QString getTodoFile();
    QString getDoneFile();
    QString getRelativeDate(QString shortform);

    struct todoline{
        QString createdDate;
        QString closedDate;
        bool checked;
        QString priority;
        QString text; // The rest of the text
    };

    static void String2Todo(QString &line,todoline &t);
    static QString Todo2String(todoline &t);


};

#endif // TODOTXT_H
