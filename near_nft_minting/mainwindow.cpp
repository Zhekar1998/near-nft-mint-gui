#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_clicked()
{
    close();
}

void MainWindow::on_mint_clicked()
{
    QString wallet_id = ui->Wallet_edit->text().toLower();
    QString network_id = ui->Network->text();
    QString nft_api = ui->NFT_storage->text();
    QString media_data = ui->mediadata->text();
    QString contract_id = ui->contract->text();
    QString meta_title = ui->metatitle->text();
    QString meta_description = ui->meta_description->text();
    QString media_source = ui->meta_media->text();
    QString media_hash = ui->meta_media_hash->text();
    QString copies = ui->Meta_copies->text();
    QString issued = ui->Meta_issued->text();
    QString expires = ui->Metaexpiries->text();
    QString strats = ui->Metastarts->text();
    QString updated = ui->Metaupdated->text();
    QString extra = ui->Metaextra->text();
    QString meta_reference = ui->Metareference->text();
    QString meta_reference_hash = ui->meta_reference_hash->text();

    system("near login");
    /*QString contr_init = "near call "+contract_id+" new_default_meta '{\"owner_id\": \"'"+contract_id+"'\"}' --accountId " + wallet_id;
    QByteArray ba = contr_init.toLocal8Bit();
      const char *c_str1 = ba.data();
    system(c_str1);*/
    QString l1 = "near generate-key " + wallet_id;
            QByteArray ba = l1.toLocal8Bit();
              const char *c_str1 = ba.data();
system(c_str1);
    for (int i=0;i<ui->spinBox->text().toInt();i++){
        QString nft = "near call " + contract_id + " nft_mint '{\"token_id\": \""+meta_title+"_"+QString::number(i)+"\", \"receiver_id\": \"" + "'"+wallet_id+ "'\", \"token_metadata\":{\"title\": \""+meta_title+"\", \"description\": \""+meta_description+"\", \"media\": \""+media_data+"\", \"copies\": "+copies+"}}' --accountId "+wallet_id+" --deposit 0.1";
        QByteArray ba = nft.toLocal8Bit();
          const char *c_str2 = ba.data();
        system(c_str2);
    }
}
