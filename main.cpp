/* * Curso Programación
* Autor: Mauricio Vega
* Fecha: 02-01-2021
* Practica 08 parte 2 */
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir directorio;
    //Direccion de la carpeta disco local c
    directorio.setPath("C:/Actividad Qt");
    qDebug() << "\nObteniendo información de" << directorio.absolutePath() << ":";
    QFileInfoList contenido = directorio.entryInfoList();
    foreach (const QFileInfo &info, contenido) {
        qDebug() << "**Nombre:\n" << info.fileName();
        qDebug() << "**Directorio:\n" << info.isDir();
        qDebug() << "**Se puede escribir:\n" << info.isWritable();
        qDebug() << "**Creación:\n" << info.lastModified().toString();
        qDebug() << "-------------------";
    }
    qDebug() << "\nListar archivos ordenados:";
    QStringList extenciones = {"*.cpp", "*.h"};
    contenido = directorio.entryInfoList(extenciones, QDir::Files, QDir::Name);
    foreach (const QFileInfo &info, contenido) {
        qDebug() << info.fileName();
    }
    QString carpeta = "Carpeta1";
    qDebug() << "Ingresando a\n" << carpeta;
    if (!directorio.cd(carpeta)){
        qWarning() << "No existe directorio\n" << carpeta;
    }else{
        QStringList contenido = directorio.entryList();
        foreach (QString elemento, contenido) {
            qDebug() << elemento;
        }
        directorio.cdUp();
    }
    qDebug() << "\nCreando directorio:";
    QString nuevo = "Carpeta6";
    if (directorio.mkdir(nuevo)){
        qDebug() << nuevo << "creado con exito!";
        QStringList contenido = directorio.entryList(QDir::Dirs);
        foreach (QString elemento, contenido) {
            qDebug() << elemento;
        }
    }else{
        qWarning() << "No se pudo crear el directorio" << nuevo;
    }
    qDebug() << "\nBorrando un directorio:";
    QString  nuevos= "Carpeta3";
    if (directorio.rmdir(nuevos)){
        qDebug() << nuevos << "borrado con exito!";
        QStringList contenido = directorio.entryList(QDir::Dirs);
        foreach (QString elemento, contenido) {
            qDebug() << elemento;
        }
    }else{
        qWarning() << "No se pudo borrar el directorio" << nuevo;
    }
    return a.exec();
}
