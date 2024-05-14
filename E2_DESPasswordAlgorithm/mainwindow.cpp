#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "stdlib.h"
#include "string"
#include "QString"
#include "QDir"
#include "QFile"
#include "QApplication"
#include "QFileDialog"
#include "QMessageBox"
using namespace std;

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

void ErrorMessageBox(QString dlgTitle,QString strInfo)
{
    QMessageBox::warning(NULL,dlgTitle,strInfo);
}

string dec2bin(int n)//10进制转2进制
{
    int i;
    string s1,s2;
    char c;
    while(n!=0)
    {
        c=n%2+'0';
        s1.append(1,c);
        n/=2;
    }
    if(s1.length()%8!=0) s2.append(8-s1.length()%8,'0');
    for(i=0;i<s1.length();i++)
    {
        s2.append(1,s1[s1.length()-i-1]);
    }
    return s2;
}

string bin2hex(string s1)//2进制转16进制
{
    string s2;
    int i;
    char c;
    c=0;
    for(i=0;i<s1.length();i++)
    {
        c=c*2+s1[i]-'0';
        if((i+1)%4==0||i==s1.length()-1)
        {
            if(c>=0&&c<=9) c+='0';
            else c=c-10+'A';
            s2.append(1,c);
            c=0;
        }
    }
    return s2;
}

string hex2bin(string s1)//16进制转2进制
{
    string s2;
    int i;
    for(i=0;i<s1.length();i++)
    {
        switch(s1[i])
        {
            case '0':s2.append("0000");break;
            case '1':s2.append("0001");break;
            case '2':s2.append("0010");break;
            case '3':s2.append("0011");break;
            case '4':s2.append("0100");break;
            case '5':s2.append("0101");break;
            case '6':s2.append("0110");break;
            case '7':s2.append("0111");break;
            case '8':s2.append("1000");break;
            case '9':s2.append("1001");break;
            case 'A':s2.append("1010");break;
            case 'B':s2.append("1011");break;
            case 'C':s2.append("1100");break;
            case 'D':s2.append("1101");break;
            case 'E':s2.append("1110");break;
            case 'F':s2.append("1111");break;
            default:break;
        }
    }
    return s2;
}

string hex2dec(string s1)//16进制转10进制
{
    int i;
    string s2;
    char c=0;
    for(i=0;i<s1.length();i++)
    {
        if(s1[i]>='0'&&s1[i]<='9') s1[i]-='0';
        else if(s1[i]>='A'&&s1[i]<='F') s1[i]=s1[i]-'A'+10;
        c=c*16+s1[i];
        if(i%2==1||i==s1.length()-1)
        {
            s2.append(1,c);
            c=0;
        }
    }
    return s2;
}

class DES
{
public:
    char Data[64];
    char Key[64];
    char Key1[56];
    char Key2[48];
    char L[32], R[32];
    char C[28], D[28];
    char Eext[48];
    char Res[48];
    char Sexc[32];
    char Pexc[32];
    char mode;

    int iprule[64] = { 58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7 };//初始置换规则
    int riprule[64] = { 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };//逆初始置换规则
    int pc1rule[56] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
    int pc2rule[48] = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32 };
    int clsrule[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };
    int eextrule[48] = { 32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1 };
    int sbox1[64] = { 14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 };
    int sbox2[64] = { 15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 };
    int sbox3[64] = { 10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 };
    int sbox4[64] = { 7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,19,10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 };
    int sbox5[64] = { 2,12,4,1,7,10,11,6,5,8,3,15,13,0,14,9,14,11,2,12,4,7,13,1,5,0,15,13,3,9,8,6,4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 };
    int sbox6[64] = { 12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 };
    int sbox7[64] = { 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 };
    int sbox8[64] = { 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11, };
    int pbox[32] = { 16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25 };

    QString DESAlgorithm(QString Data, QString Key, char mode)
    {
        int i, j;
        char temp[32];
        char K[16][48];
        QString Data_qs;
        if (Data.length() != 64)
        {
            ErrorMessageBox("错误","数据长度不匹配。");
        }
        else if (Key.length() != 64)
        {
            ErrorMessageBox("错误","密钥长度不匹配。");
        }
        else
        {
            for (i = 0; i < 64; i++)
            {
                this->Data[i] = Data[i].unicode();
                this->Key[i] = Key[i].unicode();
            }
            this->mode = mode;
            if (this->mode == 'c')
            {
                ipexc();
                pc1exc();
                for (i = 0; i < 16; i++)
                {
                    eboxext();
                    pc2exc(i);
                    for (j = 0; j < 48; j++)
                    {
                        if (Eext[j] == Key2[j]) Res[j] = '0';
                        else Res[j] = '1';
                    }
                    sboxexc();
                    pboxexc();
                    for (j = 0; j < 32; j++)
                    {
                        temp[j] = L[j];
                        L[j] = R[j];
                    }
                    for (j = 0; j < 32; j++)
                    {
                        if (temp[j] == Pexc[j]) R[j] = '0';
                        else R[j] = '1';
                    }
                }
                for (i = 0; i < 64; i++)
                {
                    if (i < 32) this->Data[i] = L[i];
                    else this->Data[i] = R[i - 32];
                }
                ripexc();
                Data_qs=QString::fromLocal8Bit(this->Data,64);
            }
            else if (this->mode == 'd')
            {
                ripexc();
                pc1exc();
                for (i = 0; i < 16; i++)
                {
                    pc2exc(i);
                    for (j = 0; j < 48; j++)
                    {
                        K[i][j] = Key2[j];
                    }
                }
                for (i = 15; i >=0 ; i--)
                {
                    for (j = 0; j < 32; j++)
                    {
                        temp[j] = R[j];
                        R[j] = L[j];
                    }
                    eboxext();
                    for (j = 0; j < 48; j++)
                    {
                        if (Eext[j] == K[i][j]) Res[j] = '0';
                        else Res[j] = '1';
                    }
                    sboxexc();
                    pboxexc();
                    for (j = 0; j < 32; j++)
                    {
                        if (temp[j] == Pexc[j]) L[j] = '0';
                        else L[j] = '1';
                    }
                }
                for (i = 0; i < 64; i++)
                {
                    if (i < 32) this->Data[i] = L[i];
                    else this->Data[i] = R[i - 32];
                }
                ipexc();
                Data_qs=QString::fromLocal8Bit(this->Data,64);
            }
        }
        return Data_qs;
    }
    void ipexc()//IP置换
    {
        int i;
        char Data1[64];
        for (i = 0; i < 64; i++)
        {
            if (mode == 'c')
            {
                Data1[i] = Data[iprule[i] - 1];
                if (i < 32) L[i] = Data1[i];
                else R[i - 32] = Data1[i];
            }
            else if (mode == 'd')
            {
                Data1[iprule[i] - 1] = Data[i];
            }
        }
        for (i = 0; i < 64; i++)
        {
            Data[i] = Data1[i];
        }
    }
    void ripexc()//IP-1置换
    {
        int i;
        char Data1[64];
        for (i = 0; i < 64; i++)
        {
            if (mode == 'c')
            {
                Data1[i] = Data[riprule[i] - 1];
            }
            else if (mode == 'd')
            {
                Data1[riprule[i] - 1] = Data[i];
            }
        }
        for (i = 0; i < 64; i++)
        {
            Data[i] = Data1[i];
            if (mode == 'd')
            {
                if (i < 32) L[i] = Data1[i];
                else R[i - 32] = Data1[i];
            }
        }
    }
    void eboxext()//E盒扩展
    {
        int i;
        for (i = 0; i < 48; i++)
        {
            Eext[i] = R[eextrule[i] - 1];
        }
    }
    void pc1exc()//PC1置换
    {
        int i;
        for (i = 0; i < 56; i++)
        {
            Key1[i] = Key[pc1rule[i] - 1];
            if (i < 28) C[i] = Key1[i];
            else D[i - 28] = Key1[i];
        }
    }
    void pc2exc(int pc2time)//PC2置换
    {
        char s1[28], s2[28];
        int i;
        for (i = 0; i < 28; i++)
        {
            if (i < 28 - clsrule[pc2time])
            {
                s1[i] = C[i + clsrule[pc2time]];
                s2[i] = D[i + clsrule[pc2time]];
            }
            else
            {
                s1[i] = C[i + clsrule[pc2time] - 28];
                s2[i] = D[i + clsrule[pc2time] - 28];
            }
        }
        for (i = 0; i < 28; i++)
        {
            C[i] = s1[i];
            D[i] = s2[i];
        }
        for (i = 0; i < 48; i++)
        {
            if (pc2rule[i] <= 28) Key2[i] = C[pc2rule[i] - 1];
            else Key2[i] = D[pc2rule[i] - 29];
        }
    }
    void sboxexc()//S盒替代
    {
        int i, j;
        int temp1, temp2, result;
        char temp[6];
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 6; j++)
            {
                temp[j] = Res[i * 6 + j] - '0';
            }
            temp1 = temp[0] * 2 + temp[5];
            temp2 = temp[1] * 8 + temp[2] * 4 + temp[3] * 2 + temp[4];
            switch (i)
            {
                case 0:result = sbox1[temp1 * 16 + temp2]; break;
                case 1:result = sbox2[temp1 * 16 + temp2]; break;
                case 2:result = sbox3[temp1 * 16 + temp2]; break;
                case 3:result = sbox4[temp1 * 16 + temp2]; break;
                case 4:result = sbox5[temp1 * 16 + temp2]; break;
                case 5:result = sbox6[temp1 * 16 + temp2]; break;
                case 6:result = sbox7[temp1 * 16 + temp2]; break;
                case 7:result = sbox8[temp1 * 16 + temp2]; break;
                default:break;
            }
            for (j = 3; j >= 0; j--)
            {
                Sexc[i * 4 + j] = result % 2 + '0';
                result /= 2;
            }
        }
    }
    void pboxexc()
    {
        int i;
        for (i = 0; i < 32; i++)
        {
            Pexc[i] = Sexc[pbox[i] - 1];
        }
    }
};

QString FileName;
QString selectedDir;

void MainWindow::on_B1_clicked()
{
    QString curPath=QDir::currentPath();
    QString dlgTitle="选择一个文件";
    QString filter="文本文件(*.txt);;图片文件(*.jpg *.bmp)";
    FileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    if(!FileName.isEmpty()) ui->TB1->setText(FileName);
    else ErrorMessageBox("错误","请求的文件不存在。");
}

void MainWindow::on_B2_clicked()
{
    QString curPath=QCoreApplication::applicationDirPath();
    QString dlgTitle="选择一个目录";
    selectedDir=QFileDialog::getExistingDirectory(this,dlgTitle,curPath,QFileDialog::ShowDirsOnly);
    if(!selectedDir.isEmpty()) ui->TB2->setText(selectedDir);
    else ErrorMessageBox("错误","请求的目录不存在。");
}

void MainWindow::on_B3_clicked()
{
    DES des;
    int i,j;
    double runtime;
    char cvec[64];
    string plaintext,key,ciphertext,s1,s2;
    QString plaintext_qs,key_qs,binarykey_qs,qs1,qs2,runtime_qs;
    clock_t start,end;
    start=clock();
    if(ui->CB2->currentIndex()==1)
    {
        if(FileName.isEmpty())
        {
            ErrorMessageBox("错误","请选择文件。");
        }
        else if(selectedDir.isEmpty())
        {
            ErrorMessageBox("错误","请选择目录。");
        }
        else
        {
            QFile file1(FileName);
            if(!file1.open(QFile::ReadOnly|QFile::Text))
            {
                ErrorMessageBox("错误","无法读取文件内容");
            }
            else
            {
                QTextStream in(&file1);
                QApplication::setOverrideCursor(Qt::WaitCursor);
                ui->TE1->setText(in.readAll());
                QApplication::restoreOverrideCursor();
            }
        }
    }
    if(ui->CB2->currentIndex()==0||ui->CB2->currentIndex()==1)
    {
        plaintext_qs=ui->TE1->toPlainText();
        key_qs=ui->TE2->toPlainText();
        plaintext=plaintext_qs.toStdString();
        key=key_qs.toStdString();
        if(plaintext.length()==0)
        {
            ErrorMessageBox("错误","请输入明文。");
            ui->TE3->setText("");
        }
        else if(key.length()==0)
        {
            ErrorMessageBox("错误","请输入密钥。");
            ui->TE3->setText("");
        }
        else if(key.length()!=8)
        {
            ErrorMessageBox("错误","密钥长度应为8个字符。");
            ui->TE2->setText("");
            ui->TE3->setText("");
        }
        else
        {
            s1="";
            for(i=0;i<key.length();i++)
            {
                s1.append(dec2bin(key[i]));
            }
            binarykey_qs=QString::fromStdString(s1);
            s1="";
            for(i=0;i<plaintext.length();i++)
            {
                s1.append(dec2bin(plaintext[i]));
                if((i+1)%8==0||i==plaintext.length()-1)
                {
                    if((i+1)%8!=0&&i==plaintext.length()-1) s1.append(64-s1.length()%64,'0');
                    if(ui->CB1->currentIndex()==1)
                    {
                        if(!qs2.isEmpty())
                        {
                            string qs2_s=qs2.toStdString();
                            for(j=0;j<64;j++)
                            {
                                if(qs2_s[j]==s1[j]) s1[j]='0';
                                else s1[j]='1';
                            }
                        }
                    }
                    qs1=QString::fromStdString(s1);
                    qs2=des.DESAlgorithm(qs1,binarykey_qs,'c');
                    s2=qs2.toStdString();
                    ciphertext.append(bin2hex(s2));
                    s1="";
                }
            }
            ui->TE3->setText(QString::fromStdString(ciphertext));
            if(ui->CB2->currentIndex()==1)
            {
                QFile file2=(selectedDir+"/file_saved.txt");
                if(file2.open(QFile::WriteOnly|QFile::Truncate))
                {
                    QString ciphertext_saved=ui->TE3->toPlainText();
                    QByteArray strBytes=ciphertext_saved.toUtf8();
                    file2.write(strBytes,strBytes.length());
                    file2.close();
                }
                else
                {
                    ErrorMessageBox("错误","请求的文件不存在。");
                }
            }
        }
    }
    end=clock();
    runtime=(double)(end-start)/CLOCKS_PER_SEC;
    runtime_qs = QString("%1").arg(runtime);
    ui->L9->setText(runtime_qs);
}


void MainWindow::on_B4_clicked()
{
    DES des;
    int i,j;
    double runtime;
    string plaintext,key,ciphertext,s0,s1,s2,s3;
    QString key_qs,binarykey_qs,ciphertext_qs,qs1,qs2,runtime_qs;
    clock_t start,end;
    start=clock();
    if(ui->CB2->currentIndex()==0)
    {
        ciphertext_qs=ui->TE3->toPlainText();
        key_qs=ui->TE2->toPlainText();
        ciphertext=ciphertext_qs.toStdString();
        key=key_qs.toStdString();
        if(ciphertext.length()==0)
        {
            ErrorMessageBox("错误","请输入密文。");
            ui->TE1->setText("");
        }
        else if(key.length()==0)
        {
            ErrorMessageBox("错误","请输入密钥。");
            ui->TE1->setText("");
        }
        else if(key.length()!=8)
        {
            ErrorMessageBox("错误","密钥长度应为8个字符。");
            ui->TE1->setText("");
            ui->TE2->setText("");
        }
        else
        {
            s1="";
            for(i=0;i<key.length();i++)
            {
                s1.append(dec2bin(key[i]));
            }
            binarykey_qs=QString::fromStdString(s1);
            s0=hex2bin(ciphertext);
            s1="";
            for(i=0;i<s0.length();i++)
            {
                s1.append(1,s0[i]);
                if((i+1)%64==0||i==plaintext.length()-1)
                {
                    if((i+1)%64!=0&&i==plaintext.length()-1) s1.append(64-s1.length()%64,'0');
                    if(!qs1.isEmpty()) s3=qs1.toStdString();
                    qs1=QString::fromStdString(s1);
                    qs2=des.DESAlgorithm(qs1,binarykey_qs,'d');
                    s2=qs2.toStdString();
                    if(ui->CB1->currentIndex()==1&&s3.length())
                    {
                        for(j=0;j<64;j++)
                        {
                            if(s2[j]==s3[j]) s2[j]='0';
                            else s2[j]='1';
                        }
                    }
                    plaintext.append(bin2hex(s2));
                    s1="";
                }
            }
            ui->TE1->setText(QString::fromStdString(hex2dec(plaintext)));
        }
        end=clock();
        runtime=(double)(end-start)/CLOCKS_PER_SEC;
        runtime_qs = QString("%1").arg(runtime);
        ui->L9->setText(runtime_qs);
    }
}

