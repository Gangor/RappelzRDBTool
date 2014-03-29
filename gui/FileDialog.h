#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QString>
#include <QFileDialog>
class QWidget;

class FileDialog
{
public:
	static QString getSaveFileName(QWidget *parent = 0,
								   const QString &caption = QString(),
								   const QString &dir = QString(),
								   const QString &filter = QString(),
								   QString *selectedFilter = 0,
								   QFileDialog::Options options = 0);

	static QString getOpenFileName(QWidget *parent = 0,
								   const QString &caption = QString(),
								   const QString &dir = QString(),
								   const QString &filter = QString(),
								   QString *selectedFilter = 0,
								   QFileDialog::Options options = 0);
};

#endif // FILEDIALOG_H
